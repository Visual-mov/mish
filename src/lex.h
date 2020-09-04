#ifndef MISH_LEX_H
#define MISH_LEX_H

#define LEX_ERR(err) printf("mish: error while tokenizing, %s\n", err);
#define TOK_BUF 64

typedef struct token;
typedef enum t_type;

token* lex_line(char* src);
char peek(char* src, int index);

#endif /* lex.h */