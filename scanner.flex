%{
#include "token.h"
%}
DIGIT [0-9]
CHAR [^\"^\\]
%%
(" "|\t|\n) /* skip whitespace */
\"{CHAR}*\" { return TOKEN_STRING; }
{DIGIT}+ { return TOKEN_NUMBER; }
\{ { return TOKEN_LEFT_BRACE; }
\} { return TOKEN_RIGHT_BRACE; }
\[ { return TOKEN_LEFT_BRACKET; }
\] { return TOKEN_RIGHT_BRACKET; }
: { return TOKEN_COLON; }
, { return TOKEN_COMMA; }
. { return TOKEN_ERROR; }
(true|TRUE) { return TOKEN_TRUE; }
(false|FALSE) { return TOKEN_FALSE; }
%%
int yywrap() { return 1; }
