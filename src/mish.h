#include <stdlib.h>

#ifndef MISH_H
#define MISH_H

// String buffer
#define STR_BUF 10000
// Buffer for args list parsing
#define TOK_BUF 100

#define USR_COLOR "\033[38;5;10m"
#define DIR_COLOR "\033[38;5;12m"
#define RESET "\033[0m"

// Current status of shell
int status = 1;

void parse_line(char* line);
int exec_program(char** args_list);
int exec_mish_cmd(char* cmd, char** args);
void check_alloc_ptr(char** p);
int in_mish_cmds(char* cmd);

#endif /* mish.h */