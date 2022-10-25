#include "token.h"
#include <stdio.h>

char* token_names[] = {
    "TOKEN_EOF",
    "TOKEN_LEFT_BRACE",
    "TOKEN_RIGHT_BRACE",
    "TOKEN_LEFT_BRACKET",
    "TOKEN_RIGHT_BRACKET",
    "TOKEN_WHITESPACE",
    "TOKEN_COMMA",
    "TOKEN_COLON",
    "TOKEN_STRING",
    "TOKEN_NUMBER",
    "TOKEN_TRUE",
    "TOKEN_FALSE",
    "TOKEN_NULL",
    "TOKEN_ERROR"
};

extern FILE *yyin;
extern int yylex();
extern char *yytext;
int main() {
    yyin = fopen("sample.json","r");
    if(!yyin) {
        printf("could not open sample.json!\n");
        return 1;
    }
    while(1) {
        token_t t = yylex();
        if(t==TOKEN_EOF) break;
        printf("token: %s text: %s\n",token_names[t],yytext);
    }
}
