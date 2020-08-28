#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "mish.h"

const char* mish_cmds[] = {
    "exit", "help",
    "cd", "cd..", "~", "/"
};
const int cmds_len = sizeof(mish_cmds) / sizeof(char*);

int in_mish_cmds(char* cmd) {
    for(int i = 0; i < cmds_len; i++) {
        if(strcmp(cmd, mish_cmds[i]) == 0)
            return 1;
    }
    return 0;
}

/* Builtin cmds */
void mish_cd(char** args) {
    if(chdir(args[1]) == -1) {
        switch(errno) {
            default: printf("mish: error changing to directory, \"%s\"\n", args[1]); break;
            case ENOENT: printf("mish: directory, \"%s\" does not exist\n", args[1]); break;
            case EACCES: printf("mish: can not access directory, \"%s\"\n", args[1]); break;
            case EIO: printf("mish: I/O error while changing to directory, \"%s\"\n", args[1]); break;
            case ENOTDIR: printf("mish: error, \"%s\" is not a directory\n", args[1]); break;
        }
    }
}

void mish_exit(char** args) {
    status = 0;
    free(args);
}

void mish_help() {
    printf("\nmish (Mini-shell)\nRyan Danver (Visual-mov) 2020.\n\n"
           "cd [path] - Change directory\n"
           "exit - Exit shell session\n"
           "help - Prints help text.\n\n");
}

void mish_home() {
    char* home = getenv("HOME");
    char* args[] = {"", home};
    mish_cd(args);
}

void mish_root() {
    char* args[] = {"", "/"};
    mish_cd(args);
}

// temp
void mish_cd_up() {
    char* args[] = {"", ".."};
    mish_cd(args);
}