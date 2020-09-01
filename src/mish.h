#include <termios.h>
#include "color.h"

#ifndef MISH_H
#define MISH_H

// String buffer
#define STR_BUF 10000

// Buffer for args list parsing
#define ARGS_BUF 100

#define USR_COLOR GREEN
#define DIR_COLOR BLUE
#define MISH_ERR(msg) printf("mish: %s\n", msg);

int status = 1;
struct termios cooked;
int args_len;

char** parse_line(char* line);
char* get_dir();
char* read_line();
void exec_program(char** args_list);
void exec_mish_cmd(char* cmd, char** args);
int in_mish_cmds(char* cmd);
void enable_raw(int enable);
char* sub_string(char* str, int l, int r);
void free_args(char** args);

#endif /* mish.h */