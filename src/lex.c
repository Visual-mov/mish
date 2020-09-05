#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "lex.h"

/* Mish lexer / tokenizer */

int STR_FLAG = 0;

t_list lex_line(char* src) {
    char* left, *right;
    t_list tokens = {(token*) malloc(TOK_BUF * sizeof(token)), 0};

    for(int i = 0; i < strlen(src); i++) {
        if(src[i] == '&' && peek(src, i) == '&') {
            add_token(&tokens, D_AMPER, &src[i], 2);
            i++;
        } else if(src[i] == '\n')
            add_token(&tokens, EOL, &src[i], 1);

        // tok buffer
    }

    return tokens;
}

void add_token(t_list* list, t_type type, char* start, int tok_len) {
    static int tok_index;
    token tok = {type, start, tok_len};
    list->tokens[tok_index] = tok;
    list->len = ++tok_index;
}

char peek(char* src, int index) {
    return (index > strlen(src)) ? NULL : src[index];
}

// Get string from token start to tok_len.
char* get_literal() {

}