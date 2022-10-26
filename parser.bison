%{
#include <stdio.h>
%}
%define parse.error verbose
%token TOKEN_EOF
%token TOKEN_LEFT_BRACE
%token TOKEN_RIGHT_BRACE
%token TOKEN_LEFT_BRACKET
%token TOKEN_RIGHT_BRACKET
%token TOKEN_COMMA
%token TOKEN_COLON
%token TOKEN_STRING
%token TOKEN_NUMBER
%token TOKEN_TRUE
%token TOKEN_FALSE
%token TOKEN_NULL
%token TOKEN_ERROR

%%
program : value;

value : object
    | TOKEN_STRING;

object : TOKEN_LEFT_BRACE members TOKEN_RIGHT_BRACE
    | TOKEN_LEFT_BRACE TOKEN_RIGHT_BRACE;

members : members TOKEN_COMMA member
    | member;

member : TOKEN_STRING TOKEN_COLON value;
%%