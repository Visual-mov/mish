#include <stdlib.h>
#include <termios.h>

#ifndef MISH_H
#define MISH_H

// String buffer
#define STR_BUF 10000
// Buffer for args list parsing
#define ARGS_BUF 100

#define USR_COLOR "\033[38;5;10m"
#define DIR_COLOR "\033[38;5;12m"
#define RESET "\033[0m"

char** parse_line(char* line);
char* get_dir();
char* read_line();
int exec_program(char** args_list);
int exec_mish_cmd(char* cmd, char** args);
int in_mish_cmds(char* cmd);
void check_alloc_ptr(char** p);
void enable_raw(int enable);

// Current status of shell
int status = 1;

struct termios orig_termios;

#endif /* mish.h */