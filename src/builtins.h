#ifndef BUILTINS_H
#define BUILTINS_H

#define CD_ERR(dir, msg) printf("cd: \"%s\" %s\n", dir, msg);

extern const char* mish_cmds[];
extern const int cmds_len;

int in_mish_cmds(char* cmd);
void mish_cd(char** args);
void mish_help();
void mish_home();
void mish_root();
void mish_cd_up();

#endif /* builtins.h */