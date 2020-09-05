#ifndef MISH_LEX_H
#define MISH_LEX_H

#define LEX_ERR(err) printf("mish: error while tokenizing, %s\n", err);
#define TOK_BUF 64

typedef enum {
    ARG, STR, D_AMPER, EOL
} t_type;

// Stores start of token in src string, and the length of the token with its type.
typedef struct {
    t_type type;
    char* start;
    int tok_len;
} token;

typedef struct {
    token* tokens;
    int len;
} t_list;

t_list lex_line(char* src);
char peek(char* src, int index);
void add_token(t_list* list, t_type type, char* start, int tok_len);

#endif /* lex.h */