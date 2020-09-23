%{
    #include "token.h"
%}

%%
([a-zA-Z])+   {
    token_t new = create_tok(yytext, TOK_ARG);
    print_tok(&new);
}

&& {
    token_t new = create_tok("", TOK_DAMPER);
    print_tok(&new);
}

\\ {
    token_t new = create_tok("", TOK_ESC);
    print_tok(&new);
}

\"(.*)\" {
    token_t new = create_tok(yytext, TOK_STR);
    print_tok(&new);
}
%%