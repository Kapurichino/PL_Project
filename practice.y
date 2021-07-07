%{
#include <stdio.h>
#include <string.h>
 
void yyerror(const char *str)
{
	fprintf(stderr,"error: %s\n",str);
}
 
int yywrap()
{
	return 1;
} 
  
main()
{
	yyparse();
} 
%}

%token INT_T FLOAT_T MAINPROG_T VAR_T ARRAY_T OF_T FUNCTION_T PROCEDURE_T BEGIN_T END_T IF_T THEN_T ELSE_T NOP_T WHILE_T RETURN_T PRINT_T
%token ID FLOAT INTEGER
%token LESS_T LOE_T GOE_T GREATER_T EQUAL_T DIFF_T PLUS_T MINUS_T MUL_T DIV_T
%token NOT_T SEMICOLON_T DOT_T COMMA_T ASSIGN_T RPARAN_T LPARAN_T 
%token LBRACKET_T RBRACKET_T COLON_T 

%%

commands: /* empty */
	| commands command
	;

command:
	statement
	;
	
statement:
	INTEGER PLUS_T INTEGER
	{
	printf("%d + %d = %d\n",$1,$3,$1+$3);
	}
	;