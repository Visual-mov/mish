#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "mish.h"

#define CD_ERR(dir, msg) printf("cd: \"%s,\" %s", dir, msg);

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
            default:
                printf("cd: error changing to directory, \"%s\"\n", args[1]);
                break;
            case ENOENT:
                printf("cd: \"%s\" does not exist\n", args[1]);
                break;
            case EACCES:
                printf("cd: can not access directory, \"%s\"\n", args[1]);
                break;
            case ENOTDIR:
                printf("cd: error, \"%s\" is not a directory\n", args[1]);
                break;
        }
    }
}

void mish_exit(char** args) {
    status = 0;
}

void mish_help() {
    printf(USR_COLOR "\nmish (Mini-shell)\n" RESET "Ryan Danver (Visual-mov) 2020.\n\n"
           "Builtin cmds:\n"
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