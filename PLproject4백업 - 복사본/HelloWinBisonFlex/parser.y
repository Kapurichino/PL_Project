%defines "parser.h"


%{

#include "AST.h"
	#include <iostream>
	  #define NULL 0
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
	#pragma warning (disable: 4005)
	#pragma warning (disable: 4996)
	

	extern int yylex(); // lexical analyzer
	 

	void yyerror(const char *str) {
	printf("%s", str);
	}

	using namespace std;

	extern FILE *yyin;



%}
%union{
AST *val;
}

%right '='
%left '<' '>'
%left '+' '-'
%left '*' '/'


%token ID INTEGER FLOAT

%type<val> factor parameter_list ID identifier_list statement_list global_declarations local_declarations
%type<val> compound_statement statement expression primary_expression subprogram_declarations subprogram_declaration

%token INT_T FLOAT_T MAINPROG_T VAR_T ARRAY_T OF_T FUNCTION_T PROCEDURE_T BEGIN_T END_T IF_T THEN_T ELSE_T NOP_T WHILE_T RETURN_T PRINT_T
%token LESS_T LOE_T GOE_T GREATER_T EQUAL_T DIFF_T PLUS_T MINUS_T MUL_T DIV_T
%token NOT_T SEMICOLON_T DOT_T COMMA_T ASSIGN_T RPARAN_T LPARAN_T 
%token LBRACKET_T RBRACKET_T COLON_T
%%
program : MAINPROG_T ID SEMICOLON_T global_declarations subprogram_declarations compound_statement{

}
global_declarations :  |
VAR_T identifier_list COLON_T standard_type SEMICOLON_T global_declarations {
	//declareVariable(getSymbol($2),NULL);
}
|
VAR_T identifier_list COLON_T ARRAY_T LBRACKET_T INTEGER RBRACKET_T OF_T standard_type SEMICOLON_T global_declarations{
	//declareArray(getSymbol($2),$6);
}
identifier_list : ID {
					//$$ = makeList1($1);
				}
				| identifier_list COMMA_T ID {
					//$$ = addLast($1,$3);
				};
type : standard_type { }
		| ARRAY_T LBRACKET_T INTEGER RBRACKET_T OF_T standard_type {
    
		}
		



standard_type : INT_T {}| FLOAT_T {}
subprogram_declarations :  | subprogram_declaration subprogram_declarations
subprogram_declaration :
FUNCTION_T ID arguments COLON_T standard_type SEMICOLON_T local_declarations compound_statement
{
//defineFunction(getSymbol($2),$3,$8);
}
|
PROCEDURE_T ID arguments SEMICOLON_T local_declarations compound_statement
{
//defineFunction(getSymbol($2),$3,$6);
}
local_declarations :  |
VAR_T identifier_list COLON_T standard_type SEMICOLON_T local_declarations {
//?????????????????????
}
|
VAR_T identifier_list COLON_T ARRAY_T LBRACKET_T INTEGER RBRACKET_T OF_T standard_type SEMICOLON_T local_declarations{
	//declareArray(getSymbol($2),$6);
}

arguments : | LPARAN_T parameter_list RPARAN_T
parameter_list : identifier_list COLON_T standard_type
| identifier_list COLON_T standard_type SEMICOLON_T parameter_list
| identifier_list COLON_T ARRAY_T LBRACKET_T INTEGER RBRACKET_T OF_T standard_type
| identifier_list COLON_T ARRAY_T LBRACKET_T INTEGER RBRACKET_T OF_T standard_type SEMICOLON_T parameter_list
compound_statement : BEGIN_T statement_list END_T



statement_list : 
statement{
//$$=makeList1($1);
}
| 
statement_list SEMICOLON_T statement{
//$$=addLast($1,$3);
}


statement : 
ID ASSIGN_T expression {
//$$ = makeAST(EQ_OP,$1,$3);
}
| PRINT_T {
//
}
| PRINT_T LPARAN_T expression RPARAN_T{
//$$ = makeAST(PRINTLN_OP,$3,NULL);
}
| ID LPARAN_T actual_parameter_expression RPARAN_T {
//$$ = makeAST(CALL_OP,$1,$3);
}
| ID LPARAN_T RPARAN_T{
//$$ = makeAST(CALL_OP,$1, NULL);
}
| compound_statement
| IF_T expression THEN_T statement ELSE_T statement {
//$$ = makeAST(IF_STATEMENT,$2,makeList2($4,$6));
}
| WHILE_T LPARAN_T expression RPARAN_T statement {
//$$ = makeAST(WHILE_STATEMENT,$3,$5);
}
| RETURN_T expression {
//$$ = makeAST(RETURN_STATEMENT,$2,NULL);
}
| RETURN_T {
//$$ = makeAST(RETURN_STATEMENT,NULL,NULL);
}
| NOP_T


actual_parameter_expression :
expression {
	//$$ = makeList1($1);
}
|
actual_parameter_expression COMMA_T expression {
	//$$ = addLast($1,$3);

}
//assignment : variable ASSIGN_T expression


expression : primary_expression
| ID LBRACKET_T expression RBRACKET_T ASSIGN_T expression
| expression PLUS_T expression
| expression MINUS_T expression
| expression MUL_T expression
| expression DIV_T expression
| expression LESS_T expression
| expression GREATER_T expression
| expression LOE_T expression
| expression GOE_T expression
| expression EQUAL_T expression
| expression NOT_T ASSIGN_T expression

primary_expression : 
INTEGER 
| FLOAT
| ID { $$ = makeAST(SYM,$1); }
| ID LPARAN_T actual_parameter_expression RPARAN_T{
	
}
| NOT_T primary_expression
| sign primary_expression

sign : PLUS_T | MINUS_T

%%

int main(int argc, char **argv) {
	yyin = fopen("example.txt", "r");
	yyparse();
	fclose(yyin);

	return 0;
}