#include "include/token.h"
#include <stdio.h>

void print_tok(token_t* tok) {
    printf("TOKEN(VALUE: %s, TYPE: %d)", tok->val, tok->type);
}

token_t create_tok(char* val, t_type type) {
    token_t token = {val, type};
    return token;
}