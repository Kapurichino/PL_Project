%{
#include <stdlib.h>
void yyerror(char *);
#include "project.tab.h"
%}

%%
int return INT_T;
float return FLOAT_T;
mainprog return MAINPROG_T;
var return VAR_T;
array return ARRAY_T;
of return OF_T;
function return FUNCTION_T;
procedure return PROCEDURE_T;
begin return BEGIN_T;
end    printf("end ");return END_T;
if return IF_T;
then return THEN_T;
else    return ELSE_T;
nop return NOP_T;
while   return WHILE_T;
return return RETURN_T;
print   return PRINT_T;
[a-z|A-Z][0-9|a-z|A-Z]*  return ID;
[0-9]+"."[0-9]+		   yylval=atof(ttext); return FLOAT;
[0-9]+			     yylval=atoi(yytext); return INTEGER;
"+" return PLUS_T;
"-" return MINUS_T;
"*" return MUL_T;
"/" return DIV_T;
"<"     return LESS_T;
"<="    return LOE_T;
">="    return GOE_T;
">"     return GREATER_T;
"=="    return EQUAL_T;
"!"   return NOT_T; 
"!="    return DIFF_T;  
";" return SEMICOLON_T;
"." return DOT_T;
"," return COMMA_T;
"=" return ASSIGN_T;
"(" return RPARAN_T;
")" return LPARAN_T;
"[" return LBRACKET_T;
"]" return RBRACKET_T;
":" return COLON_T;

" "|\t|\n|#[^\n]*\n ;
