#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

#include "mish.h"
#include "builtins.h"

/* mish (Mini-shell)
 *  Simplistic Linux/Unix shell as well as
 *  my personal shell.
 *  Ryan Danver (Visual-mov) 2020.
 */

int main() {
    signal(SIGINT, SIG_IGN);
    char* usr = getenv("USER");
    int cwd_buf = STR_BUF;
    size_t n;

    while(status) {
        char* cwd = (char*) malloc(cwd_buf);
        while(getcwd(cwd, cwd_buf) == NULL && errno == ERANGE) {
            cwd_buf += STR_BUF;
            cwd = realloc(cwd, cwd_buf * sizeof(char));
        }
        check_alloc_ptr((char**) cwd);

        printf(USR_COLOR "%s%s : %s%s%s $ ", usr, RESET, DIR_COLOR, cwd, RESET);

        char* line = NULL;
        getline(&line, &n, stdin);
        parse_line(line);
        free(line);
        free(cwd);
    }
    return 0;
}

// Split line into args tokens and execute.
void parse_line(char* line) {
    line[strlen(line)-1] = '\0';
    int b_size = TOK_BUF;
    char** args = (char**) malloc(b_size * sizeof(char*));
    char* tok = strtok(line, " ");
    int index = 0;

    check_alloc_ptr(args);
    while(tok != NULL) {
        args[index] = tok;
        if(index == b_size-1) {
            b_size += TOK_BUF;
            args = (char**) realloc(args, b_size * sizeof(char*));
            check_alloc_ptr(args);
        }
        tok = strtok(NULL, " ");
        index++;
    }
    args[index] = NULL;

    if(args[0] != NULL) {
        if(in_mish_cmds(args[0]))
            exec_mish_cmd(args[0], args);
        else
            exec_program(args);
    }

    if(status)
        free(args);
}

// Execute builtin mish commands
int exec_mish_cmd(char* cmd, char** args) {
    if(strcmp(cmd, "help") == 0)
        mish_help();
    else if(strcmp(cmd, "exit") == 0)
        mish_exit(args);
    else if(strcmp(cmd, "cd") == 0)
        mish_cd(args);
    else if(strcmp(cmd, "~") == 0)
        mish_home();
    else if(strcmp(cmd, "/") == 0)
        mish_root();
    else if(strcmp(cmd, "cd..") == 0)
        mish_cd_up();
}

// Create child process and execute program located in PATH
int exec_program(char** args) {
    pid_t pid = fork();
    int stat;
    if(pid == 0) {
        // Don't suppress signal interrupt for child process.
        signal(SIGINT, SIG_DFL);

        // If execution was unsuccessful, print the cause and terminate the child process.
        if(execvp(args[0], args) == -1) {
            char* err;
            switch(errno) {
                default: err = "execution error"; break;
                case ENOENT: err = "command not found"; break;
                case EACCES: err = "permission denied"; break;
            }
            printf("%s: %s\n", args[0], err);
            mish_exit(args);
        }
    } else if(pid > 0) {
        waitpid(pid, &stat, WUNTRACED);
        signal(SIGINT, SIG_IGN);
    }
}

void check_alloc_ptr(char** p) {
    if(!p) {
        printf("mish: memory allocation error\n");
        mish_exit(p);
    }
}