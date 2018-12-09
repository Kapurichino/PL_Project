%defines "parser.h"


%{

#include "AST.h"
#include "interp.h"
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
enum Type type;
int intValue;
}

%right '='
%left '<' '>'
%left '+' '-'
%left '*' '/'


%token ID FLOAT
%type<intValue> sign
%type<val> factor parameter_list ID identifier_list statement_list
%type<val> compound_statement statement expression primary_expression subprogram_declarations subprogram_declaration
%type<val> actual_parameter_expression local_declarations arguments block program
%type<val> compound_statement_list
%type<type> standard_type

%token MAINPROG_T VAR_T ARRAY_T OF_T FUNCTION_T PROCEDURE_T BEGIN_T END_T IF_T THEN_T ELSE_T NOP_T WHILE_T RETURN_T PRINT_T
%token LESS_T LOE_T GOE_T GREATER_T EQUAL_T DIFF_T MUL_T DIV_T
%token NOT_T SEMICOLON_T DOT_T COMMA_T ASSIGN_T RPARAN_T LPARAN_T 
%token LBRACKET_T RBRACKET_T COLON_T
%token<val> INTEGER
%token<type> INT_T FLOAT_T 
%token<intValue> PLUS_T MINUS_T
%%
program : MAINPROG_T ID SEMICOLON_T local_declarations subprogram_declarations BEGIN_T statement_list END_T{
	AST *maintemp = makeAST(BLOCK_STATEMENT,$4,$7);
	AST *temp = makeSymbol("main");
	defineFunction(getSymbol(temp),NULL,maintemp);
}

identifier_list : ID {
					$$ = makeList1($1);
				}
				| identifier_list COMMA_T ID {
					$$ = addLast($1,$3);
				};
type : standard_type { }
		| ARRAY_T LBRACKET_T INTEGER RBRACKET_T OF_T standard_type {
			
		}
		
standard_type : INT_T {$$=I;}| FLOAT_T {$$=F;}
subprogram_declarations :  | subprogram_declaration subprogram_declarations
subprogram_declaration :
FUNCTION_T ID arguments COLON_T standard_type SEMICOLON_T block
{
defineFunction(getSymbol($2),$3,$7);
}
|
|
PROCEDURE_T ID arguments SEMICOLON_T block
{
defineFunction(getSymbol($2),$3,$5);
}

block: local_declarations BEGIN_T statement_list END_T{
	$$ = makeAST(BLOCK_STATEMENT,$1,$3);
	//cout<<"block op : "<<$$->op<<endl;
}

local_declarations :  {$$=NULL;} | 
VAR_T identifier_list COLON_T standard_type SEMICOLON_T local_declarations {
	for(AST *l = $2; l != NULL; l = l->right){ 
		l->left->sym->type = $4;
	}	
	$$=addList($2,$6);
}
|
VAR_T identifier_list COLON_T ARRAY_T LBRACKET_T INTEGER RBRACKET_T OF_T standard_type SEMICOLON_T local_declarations{
	for(AST *l = $2; l != NULL; l = l->right){ 
		if($9==I){
		l->left->sym->type = IA;
		} else {
		l->left->sym->type = FA;
		}
		l->left->sym->size=$6->val;
	}	
	
	$$=addList($2,$11);

	//지역 변수 배열
}

arguments : { $$ = NULL; } 
| LPARAN_T parameter_list RPARAN_T{
	$$ = $2;
}
parameter_list : identifier_list COLON_T standard_type{
	$$ = $1;
}
| identifier_list COLON_T standard_type SEMICOLON_T parameter_list{
	$$ = addList($1,$5);
}
| identifier_list COLON_T ARRAY_T LBRACKET_T INTEGER RBRACKET_T OF_T standard_type{
	$$ = $1;
}
| identifier_list COLON_T ARRAY_T LBRACKET_T INTEGER RBRACKET_T OF_T standard_type SEMICOLON_T parameter_list{
	$$ = addList($1,$10);
}


statement_list : 
statement{
$$=makeList1($1);
}
| 
statement_list SEMICOLON_T statement{
$$=addLast($1,$3);
}
|
compound_statement SEMICOLON_T statement_list{
$$=addList($1,$3);
}
|
statement_list SEMICOLON_T compound_statement {
$$=addList($1,$3);
}
|
compound_statement{
$$=$1;
}

compound_statement: BEGIN_T statement_list END_T{
$$=$2;
cout<<"COMP"<<endl;
}


statement : 
ID LBRACKET_T expression RBRACKET_T ASSIGN_T expression{
//setArray
	$$ = makeAST(SET_ARRAY_OP,makeList2($1,$3),$6);
}
|
ID ASSIGN_T expression {
//cout<<"assign expression"<<endl;
$$ = makeAST(EQ_OP,$1,$3);
}
| PRINT_T {
}
| PRINT_T LPARAN_T expression RPARAN_T{
$$ = makeAST(PRINTLN_OP,$3,NULL);
}
| IF_T expression THEN_T statement ELSE_T statement {
$$ = makeAST(IF_STATEMENT,$2,makeList2(makeList1($4),makeList1($6)));
}
| IF_T expression THEN_T BEGIN_T statement_list END_T ELSE_T statement {
$$ = makeAST(IF_STATEMENT,$2,makeList2($5,makeList1($8)));
}
| IF_T expression THEN_T statement ELSE_T BEGIN_T statement_list END_T {
$$ = makeAST(IF_STATEMENT,$2,makeList2(makeList1($4),$7));
}
| IF_T expression THEN_T BEGIN_T statement_list END_T ELSE_T BEGIN_T statement_list END_T {
$$ = makeAST(IF_STATEMENT,$2,makeList2($5,$9));
}

| WHILE_T LPARAN_T expression RPARAN_T statement {
$$ = makeAST(WHILE_STATEMENT,$3,makeList1($5));
}
| WHILE_T LPARAN_T expression RPARAN_T BEGIN_T statement_list END_T {
$$ = makeAST(WHILE_STATEMENT,$3,$6);
}

| RETURN_T expression {
$$ = makeAST(RETURN_STATEMENT,$2,NULL);
}
| RETURN_T {
$$ = makeAST(RETURN_STATEMENT,NULL,NULL);
}
|
NOP_T


actual_parameter_expression :
expression {
	$$ = makeList1($1);
}
|
actual_parameter_expression COMMA_T expression {
	$$ = addLast($1,$3);

}
//assignment : variable ASSIGN_T expression


expression : primary_expression
|  expression PLUS_T expression{
	$$ = makeAST(PLUS_OP,$1,$3); 
}
| expression MINUS_T expression{
$$ = makeAST(MINUS_OP,$1,$3); 
}
| expression MUL_T expression{
	$$ = makeAST(MUL_OP,$1,$3); 
}
| expression DIV_T expression{
	$$ = makeAST(DIV_OP,$1,$3); 
}
| expression LESS_T expression{
$$ = makeAST(LT_OP,$1,$3); 
}
| expression GREATER_T expression{
	$$ = makeAST(GT_OP,$1,$3); 
}
| expression LOE_T expression{
	$$ = makeAST(LOE_OP,$1,$3); 
}
| expression GOE_T expression{
	$$ = makeAST(GOE_OP,$1,$3); 
}
| expression EQUAL_T expression{ // ==
	$$ = makeAST(EQUAL_OP,$1,$3); 
}
| expression DIFF_T expression{ // !=
	$$ = makeAST(DIFF_OP,$1,$3); 
}
| sign primary_expression{
	if($1==-1){
	$$ = makeAST(MINUS_OP,makeNum(0),$2);
	} else {
	$$ = $2;
	}
}
| NOT_T primary_expression{
cout<<"NOT_TTTTT"<<endl;
	$$ = makeAST(NOT_OP,$2,NULL);
}

primary_expression : 
INTEGER
| FLOAT
| ID
| ID LBRACKET_T expression RBRACKET_T {
//getArray
	$$ = makeAST(GET_ARRAY_OP,$1,$3);
}
| ID LPARAN_T actual_parameter_expression RPARAN_T{
	$$ = makeAST(CALL_OP,$1,$3);
}
| ID LPARAN_T RPARAN_T{
	$$ = makeAST(CALL_OP,$1,NULL);
}

sign : PLUS_T { $$ = 1;}|
		MINUS_T {$$ = -1;}

%% 
