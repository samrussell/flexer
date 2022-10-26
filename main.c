#include "token.h"
#include <stdio.h>

char* token_names[] = {
    "TOKEN_EOF",
    "TOKEN_LEFT_BRACE",
    "TOKEN_RIGHT_BRACE",
    "TOKEN_LEFT_BRACKET",
    "TOKEN_RIGHT_BRACKET",
    "TOKEN_COMMA",
    "TOKEN_COLON",
    "TOKEN_STRING",
    "TOKEN_NUMBER",
    "TOKEN_TRUE",
    "TOKEN_FALSE",
    "TOKEN_NULL",
    "TOKEN_ERROR"
};

typedef enum yytokentype token_t;

extern FILE *yyin;
extern int yylex();
extern int yyparse();
extern char *yytext;
int main(int argc, char** argv) {
    if(argc != 2){
        printf("Usage: %s filename\n", argv[0]);
        return -1;
    }
    yyin = fopen(argv[1],"r");
    if(!yyin) {
        printf("could not open %s\n", argv[1]);
        return 1;
    }
    yyparse()
    return 0;

    while(1) {
        token_t t = yylex();
        if(t==TOKEN_EOF || !t){
            printf("EOF\n");
            break;
        }
        if(t-TOKEN_EOF < 0 || t-TOKEN_EOF > sizeof(token_names)){
            printf("Got token %d but isn't in array!\n", t);
        }
        printf("token: %s text: %s\n",token_names[t-TOKEN_EOF],yytext);
    }
}

void yyerror (char const *s) {
    fprintf (stderr, "%s\n", s);
}

