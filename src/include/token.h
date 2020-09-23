
typedef enum {
    TOK_ARG, TOK_STR, TOK_DAMPER, TOK_ESC, TOK_EOF
} t_type;

typedef struct {
    char* val;
    t_type type;
} token_t;

void print_tok(token_t* tok);
token_t create_tok(char* val, t_type type);