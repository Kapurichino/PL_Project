%defines "parser.h"


%{
#include <cmath>
	#include <cstdio>
	#include <iostream>
	#include <deque>
	  #define NULL 0
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <sstream>
	#pragma warning (disable: 4005)
	#pragma warning (disable: 4996)
	
	// this function will be generated
	// by flex
	extern int yylex(); // lexical analyzer
	 
	 // we have to code this function
	extern void yyerror(const char*);

	using namespace std;
	char* getToken(char *input,int num);
	int getTokenCount(char *input);
	int add_var(string name, int type, int size);
	void printList();
	extern FILE *yyin;

	deque<char*> idlist;

%}


%union{
char *stringValue;
int intValue;
float floatValue;
struct vartab *vart;
}
%token <symp> NAME
%token<intValue> INTEGER
%token<floatValue> FLOAT
%token<stringValue> ID
%nonassoc INT_T FLOAT_T
%type<intValue> INT_T FLOAT_T
%type<stringValue> identifier_list type standard_type
%token INT_T FLOAT_T MAINPROG_T VAR_T ARRAY_T OF_T FUNCTION_T PROCEDURE_T BEGIN_T END_T IF_T THEN_T ELSE_T NOP_T WHILE_T RETURN_T PRINT_T
%token LESS_T LOE_T GOE_T GREATER_T EQUAL_T DIFF_T PLUS_T MINUS_T MUL_T DIV_T
%token NOT_T SEMICOLON_T DOT_T COMMA_T ASSIGN_T RPARAN_T LPARAN_T 
%token LBRACKET_T RBRACKET_T COLON_T
%%
program : MAINPROG_T ID SEMICOLON_T declarations subprogram_declarations compound_statement{

}
declarations :  |
VAR_T identifier_list COLON_T type SEMICOLON_T declarations {
		int i=0;
		for(i=0;i<idlist.size();i++){
			cout << idlist.at(i) << " ";
		}
	
	  /*int varType = atoi(getToken($<stringValue>4,0));
	
	\

	  int varSize = atoi(getToken($<stringValue>4,1));

	  int tokens = getTokenCount($<stringValue>2);

	  printf("identifier_list= %s ��ū����:%d\n",$<stringValue>2,tokens);
		char *varName = getToken($<stringValue>2,0);
		add_var(varName,varType,varSize);
		int i=1;
	if(varSize == 0)  varSize = 1;
	  do{
		varName = getToken($<stringValue>2,i);
		printf("varName=%s, varType=%d, varSize=%d\n",varName,varType,varSize);
		add_var(varName,varType,varSize);
		i++;
	  }while(i<tokens);*/
};
identifier_list : ID {
				cout << $<stringValue>1 << " �ϳ���" << endl;
				idlist.push_back($<stringValue>1);
				}
				| ID COMMA_T identifier_list {
				idlist.push_back($<stringValue>1);
				cout << $<stringValue>1 << " list:" << $<stringValue>3 << endl;
				};
type : standard_type { $$ = $<stringValue>1; }
		| ARRAY_T LBRACKET_T INTEGER RBRACKET_T OF_T standard_type {
      $$ = strdup("");
			if(strcmp($<stringValue>6,"1")==0){
				strcat($$,"3@");
			} else {
				strcat($$,"4@");
			}
			char *temp = (char*)malloc(sizeof(int));
			sprintf(temp,"%d",$<intValue>3);
			strcat($$,temp);
			free(temp);
		}
		



standard_type : INT_T {$$="1";}| FLOAT_T {$$="2";}
subprogram_declarations :  | subprogram_declaration subprogram_declarations
subprogram_declaration : subprogram_head declarations compound_statement
subprogram_head : FUNCTION_T ID arguments COLON_T standard_type SEMICOLON_T {printf("@@@@@@@@ FUNCTION DECLARED!! @@@@@@@@@\n"); } | PROCEDURE_T ID arguments SEMICOLON_T
arguments : | LPARAN_T parameter_list RPARAN_T
parameter_list : identifier_list COLON_T type | identifier_list COLON_T type SEMICOLON_T parameter_list
compound_statement : BEGIN_T statement_list END_T
statement_list : statement | statement SEMICOLON_T statement_list
statement : variable ASSIGN_T expression | print_statement | procedure_statement | compound_statement
| IF_T expression THEN_T statement ELSE_T statement | WHILE_T LPARAN_T expression RPARAN_T statement | RETURN_T expression | NOP_T
print_statement : PRINT_T | PRINT_T LPARAN_T expression RPARAN_T
variable : ID | ID LBRACKET_T expression RBRACKET_T
procedure_statement : ID LPARAN_T actual_parameter_expression RPARAN_T
actual_parameter_expression :  | expression_list
expression_list : expression | expression COMMA_T expression_list
expression : simple_expression | simple_expression relop simple_expression
simple_expression : term | term addop simple_expression
term : factor | factor multop term
factor : INTEGER | FLOAT | variable | procedure_statement | NOT_T factor | sign factor
sign : PLUS_T | MINUS_T
relop : GREATER_T | GOE_T | LESS_T | LOE_T | EQUAL_T | DIFF_T
addop : PLUS_T | MINUS_T
multop : MUL_T | DIV_T
%%

int main(int argc, char **argv) {
	yyin = fopen("example.txt", "r");
	yyparse();
	fclose(yyin);
	printList();
	return 0;
}