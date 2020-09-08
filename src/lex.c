#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "lex.h"

/* Mish lexer / tokenizer */

int STR_FLAG = 0;
char* start, *cur;

/* Scans a line and returns token list. */
t_list lex_line(char* src) {
    start = src;
    cur = src;

    int buf = TOK_BUF;
    t_list tokens = {(token*) malloc(buf * sizeof(token)), 0};


    while(!at_end()) {
        if(cur[0] == '&' && peek() == '&') {
            add_token(&tokens, D_AMPER, cur, 2);
            advance();
            start = cur;
        } else if(cur[0] == '\"') {
            STR_FLAG = !STR_FLAG;
        } else if(cur[0] == '\\') {
            add_token(&tokens, ESC, cur, 1);
        } else {
            scan_arg(&tokens, src);
        }

        if(peek() == /* newline */EOL_CHAR) {
            add_token(&tokens, EOL, &cur[1], 1);
        }

        // add tok buffer realloc

        advance();
    }

    return tokens;
}

void scan_arg(t_list* list, char* src) {
    while(cur[0] != MISH_DELIM && peek() != EOL_CHAR)
        advance();

    add_token(list, ARG, start, strlen(start) - strlen(cur));

    // temp
    if(cur[0] == MISH_DELIM)
        advance();

    start = cur;
}

int is_alpha(char c) {

}

/* Constructs and adds a token to the given token list. */
void add_token(t_list* list, t_type type, char* start, int tok_len) {
    static int tok_index;
    token tok = {type, start, tok_len};
    list->tokens[tok_index] = tok;
    list->len = ++tok_index;
}

/* Return the next character to be passed by the cur pointer. */
char peek() {
    return (strlen(cur) <= 1) ? EOL_CHAR : cur[1];
}

void advance() {
    cur++;
}

int at_end() {
    return cur[0] == EOL_CHAR;
}

/* Get string from token start to tok_len. */
char* get_literal() {

}

/* Removes character at cur and shifts src string. */
void remove_char(char* src) {

}