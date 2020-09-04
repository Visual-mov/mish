#include <stdlib.h>
#include <string.h>

#include "lex.h"

/* Mish lexer / tokenizer */

typedef enum {
    ARG, STR, D_AMPER, EOF
} t_type;

// Stores start of token in src string, and the length of the token with its type.
typedef struct {
    t_type type;
    char* start;
    int tok_len;
} token;

token* lex_line(char* src) {
    char* left, *right;
    token* tokens = malloc(TOK_BUF * sizeof(token));

    return tokens;
}

char peek(char* src, int index) {
    return (index > strlen(src)) ? NULL : src[index];
}