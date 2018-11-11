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
struct vartab *varlist;
extern void *malloc();

enum {
LOOKUP = 0
};
struct vartab {
	char *name;
	double value;
	int type;
    struct vartab *next; 
};

int state;
int add_var(char *name, int type);
int lookup_var(char *name);
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

%type<intValue> INT_T FLOAT_T standard_type type ARRAY_T LBRACKET_T RBRACKET_T OF_T
%token INT_T FLOAT_T MAINPROG_T VAR_T ARRAY_T OF_T FUNCTION_T PROCEDURE_T BEGIN_T END_T IF_T THEN_T ELSE_T NOP_T WHILE_T RETURN_T PRINT_T
%token LESS_T LOE_T GOE_T GREATER_T EQUAL_T DIFF_T PLUS_T MINUS_T MUL_T DIV_T
%token NOT_T SEMICOLON_T DOT_T COMMA_T ASSIGN_T RPARAN_T LPARAN_T 
%token LBRACKET_T RBRACKET_T COLON_T


%%
program : MAINPROG_T ID SEMICOLON_T declarations subprogram_declarations compound_statement
declarations :  |
VAR_T identifier_list COLON_T type SEMICOLON_T declarations {
if($<intValue>4==0){
add_var($<stringValue>2,0);
printf("int %s 등록 성공\n",$<stringValue>2);
} else if($<intValue>4==1){
add_var($<stringValue>2,1);
printf("float %s 등록 성공\n",$<stringValue>2);
} else { printf("type체킹 실패\n"); }

};

identifier_list : ID| ID COMMA_T identifier_list
type : standard_type{$$=$1;}  | ARRAY_T LBRACKET_T INTEGER RBRACKET_T OF_T standard_type {$$=2;}
standard_type : INT_T {$$=0;}| FLOAT_T {$$=1;}
subprogram_declarations :  | subprogram_declaration subprogram_declarations

subprogram_declaration : subprogram_head declarations compound_statement { printf("subprogram");}
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

%%

int add_var(char *name, int type){
    struct vartab *vp;
    if(lookup_var(name)!=LOOKUP){
        printf("!! warning: variable %s already defined \n",name);
        return 0;
    }
    
    vp=(struct vartab*)malloc(sizeof(struct vartab));
    vp->next = varlist;
    vp->value=0;
    
    vp->name=(char*)malloc(strlen(name)+1);
    strcpy(vp->name,name);
    vp->type=type;
    varlist = vp;
    return 1;
}

int lookup_var(char *name){
    struct vartab *vp = varlist;
    
    for(;vp;vp=vp->next){
        if(strcmp(vp->name,name)==0)
        return 1;
    }
    return LOOKUP;
}
