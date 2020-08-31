#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef BUILTINS_H
#define BUILTINS_H

#define CD_ERR(dir, msg) printf("cd: \"%s\" %s\n", dir, msg);

const char* mish_cmds[] = {
    "exit", "help",
    "cd", "..", "~", "/"
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
                CD_ERR(args[1], "error changing to directory");
                break;
            case ENOENT:
                CD_ERR(args[1], "directory does not exist");
                break;
            case EACCES:
                CD_ERR(args[1], "can not access directory");
                break;
            case ENOTDIR:
                CD_ERR(args[1], "is not a directory")
                break;
        }
    }
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

void mish_cd_up() {
    char* args[] = {"", ".."};
    mish_cd(args);
}

#endif /* builtins.h */