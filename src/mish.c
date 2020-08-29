#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <termios.h>


#include "mish.h"
#include "builtins.h"

/* mish (Mini-shell)
 *  Simplistic Linux/Unix shell as well as
 *  my personal shell.
 *  Ryan Danver (Visual-mov) 2020.
 */

int main(int argc, char* argv[]) {
    //signal(SIGINT, SIG_IGN);
    char* cwd;
    char* usr = getenv("USER");
    char* line;

    while(status) {
        cwd = get_dir();
        printf(USR_COLOR "%s%s : %s%s%s $ ", usr, RESET, DIR_COLOR, cwd, RESET);

        line = read_line();

        char** args = parse_line(line);
        if(args[0] != NULL) {
            if(in_mish_cmds(args[0]))
                exec_mish_cmd(args[0], args);
            else
                exec_program(args);
        }

        free(args);
        free(line);
        free(cwd);
    }
    return 0;
}

// Split line into args
char** parse_line(char* line) {
    // this shit don't work lol
    // Issue copying token to args list

    // int args_index = 0, i = 0;
    // char** args = (char**) malloc(args_buf * sizeof(char*));
    // char* token = malloc(strlen(line));

    // while(i < strlen(line)) {
    //     if (line[i] == ' ' || line[i] == '\n') {
    //         strncpy(args[args_index], token, 1);
    //         free(token);
    //         token = malloc(strlen(line));
    //         args_index++;
    //     } else
    //         strncat(token, &line[i], 1);
    //     i++;
    // }
    // args[args_index+1] = NULL;
    // free(token);

    int args_buf = ARGS_BUF;
    char** args = (char**) malloc(args_buf * sizeof(char*));
    char* tok = strtok(line, " ");
    int index = 0;

    check_alloc_ptr(args);
    while(tok != NULL) {
        args[index] = tok;
        if(index == args_buf-1) {
            args_buf += ARGS_BUF;
            args = (char**) realloc(args, args_buf * sizeof(char*));
            check_alloc_ptr(args);
        }
        tok = strtok(NULL, " ");
        index++;
    }
    args[index] = NULL;
    return args;
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

// TODO: Replace with different line parsing method.
char* read_line() {
    char* line = NULL;
    size_t n;
    getline(&line, &n, stdin);

    // only if using strtok
    line[strlen(line)-1] = '\0';

    return line;
}

// Get current working directory
char* get_dir() {
    int cwd_buf = STR_BUF;
    char* cwd = (char*) malloc(cwd_buf);

    while(getcwd(cwd, cwd_buf) == NULL && errno == ERANGE) {
        cwd_buf += STR_BUF;
        cwd = realloc(cwd, cwd_buf * sizeof(char));
    }
    check_alloc_ptr((char**) cwd);

    return cwd;
}

void check_alloc_ptr(char** p) {
    if(!p) {
        printf("mish: memory allocation error\n");
        mish_exit(p);
    }
}


// Set the terminal to raw or cooked mode. (without using stty)
void enable_raw(int enable) {
    if(enable) {
        tcgetattr(STDIN_FILENO, &orig_termios);
        struct termios raw;
        tcgetattr(STDIN_FILENO, &raw);
        raw.c_lflag &= ~(ECHO);
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    } else {
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
    }
}