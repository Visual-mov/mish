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

#define LISH_ERR(msg) printf("lish: %s", msg);

// Current status of shell
int status = 1;

struct termios cooked;
int args_len;

char** parse_line(char* line);
char* get_dir();
char* read_line();
int exec_program(char** args_list);
int exec_mish_cmd(char* cmd, char** args);
int in_mish_cmds(char* cmd);
int check_alloc_ptr(void* p);
void enable_raw(int enable);
char* sub_string(char* str, int l, int r);
void free_args(char** args);

#endif /* mish.h */