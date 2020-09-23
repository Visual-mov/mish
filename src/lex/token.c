#include "token.h"
#include <stdio.h>

void print_tok(token_t* tok) {
    printf("TOKEN(VALUE: %s, TYPE: %s)\n", tok->val, get_enum_str(tok->type));
}
char* get_enum_str(t_type type) {
    switch(type) {
        default:         return "";
        case TOK_STR:    return "TOK_STR";
        case TOK_ARG:    return "TOK_ARG";
        case TOK_DAMPER: return "TOK_DAMPER";
        case TOK_ESC:    return "TOK_ESC";
        case TOK_EOF:    return "TOK_EOF";
    }
}

token_t create_tok(char* val, t_type type) {
    token_t token = {val, type};
    return token;
}