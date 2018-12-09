%option noyywrap

%{
#include <stdlib.h>
#include "AST.h"
#include "interp.h"
#include "parser.h"
#pragma warning (disable: 4005)
	#pragma warning (disable: 4996)


%}

%%
int     printf("int");      return INT_T;
float   printf("float");    return FLOAT_T;
mainprog    printf("mainprog"); return MAINPROG_T;
var     printf("var");      return VAR_T;
array   printf("array");    return ARRAY_T;
of      printf("of");       return OF_T;
function    printf("function");    return FUNCTION_T;
procedure   printf("procedure");    return PROCEDURE_T;
begin   printf("begin");    return BEGIN_T;
end     printf("end "); return END_T;
if      printf("if");   return IF_T;
then    printf("then"); return THEN_T;
else    printf("else"); return ELSE_T;
nop     printf("nop");  return NOP_T;
while   printf("while");    return WHILE_T;
return  printf("return");   return RETURN_T;
print   printf("print");    return PRINT_T;

[a-z|A-Z][0-9|a-z|A-Z]*  {
yylval.val=makeSymbol(yytext);
printf("%s ",yytext);
return ID;
}

[0-9]+"."[0-9]+ {
yylval.val = makeFloat(atof(yytext));
printf("%s" , yytext);
return FLOAT;
}

[-][0-9]+ {
yylval.val = makeNum(atoi(yytext));
printf("%s", yytext);
return INTEGER;
}
[0-9]+ {
yylval.val = makeNum(atoi(yytext));
printf("%s", yytext);
return INTEGER;
}
"+" printf("+");    return PLUS_T;
"-" printf("-");    return MINUS_T;
"*" printf("*");    return MUL_T;
"/" printf("/");    return DIV_T;
"<"     printf("<");    return LESS_T;
"<="    printf("<=");   return LOE_T;
">="    printf(">=");   return GOE_T;
">"     printf(">");    return GREATER_T;
"=="    printf("==");   return EQUAL_T;
"!"     printf("!");    return NOT_T; 
"!="    printf("!=");    return DIFF_T;  
";" printf(";");    return SEMICOLON_T;
"." printf(".");    return DOT_T;
"," printf(",");    return COMMA_T;
"=" printf("="); return ASSIGN_T;
"(" printf("("); return LPARAN_T;
")" printf(")"); return RPARAN_T;
"[" printf("["); return LBRACKET_T;
"]" printf("]"); return RBRACKET_T;
":" printf(":"); return COLON_T;

\n  printf("\n");
" "|\t|#[^\n]*\n printf(" ");


%%