#ifndef MISH_LEX_H
#define MISH_LEX_H

#define LEX_ERR(err) printf("mish: error while tokenizing, %s\n", err);
#define MISH_DELIM ' '
#define TOK_BUF 64
// temp
#define EOL_CHAR '|'

typedef enum {
    EOL, ARG, STR, ESC, D_AMPER
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
void scan_arg(t_list* list, char* src);
char peek();
void advance();
int at_end();
void add_token(t_list* list, t_type type, char* start, int tok_len);

#endif /* lex.h */