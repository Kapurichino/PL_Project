%{
  #include <stdio.h>
  #include <string.h>
  
  void yyerror(const char *str)
  {
    printf("%s",str);
  }
  
  int yywrap()
  {
    return 1;
  } 
    
  int main()
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
program : MAINPROG_T ID SEMICOLON_T declarations subprogram_declarations compound_statement
declarations :  | VAR_T identifier_list COLON_T type SEMICOLON_T declarations
identifier_list : ID | ID COMMA_T identifier_list
type : standard_type | ARRAY_T LBRACKET_T INTEGER RBRACKET_T OF_T standard_type
standard_type : INT_T | FLOAT_T
subprogram_declarations :  | subprogram_declaration subprogram_declarations

subprogram_declaration : subprogram_head declarations compound_statement
subprogram_head : FUNCTION_T ID arguments COLON_T standard_type SEMICOLON_T | PROCEDURE_T ID arguments SEMICOLON_T
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