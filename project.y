%{
  #define NULL 0
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  struct vartab {
	char *name;
	int *ivalarr;
	float *fvalarr;
	int type;
  int size;
  struct vartab *next; 
};
 struct vartab *varlist;
extern void *malloc();
int state;
int add_var(char *name, int type, int size);
struct vartab * lookup_var(char *name);
void printList(struct vartab *);
void yyerror(const char *str){
  printf("%s",str);
}
int yywrap(){
  return 1;
} 
int main(){
  printf("!%d!",sizeof(struct vartab));
  yyparse();
  printList(varlist);
  return 0;
} 
enum {
LOOKUP = 0,
INTVAL,
FLOATVAL,
INTARR,
FLOATARR
};

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
program : MAINPROG_T ID SEMICOLON_T declarations subprogram_declarations compound_statement
declarations :  |
VAR_T identifier_list COLON_T type SEMICOLON_T declarations {
	printf("identifier_list = %s\n",$<stringValue>2);
  int varType = atoi(strtok($<stringValue>4,"@"));
  int varSize = atoi(strtok(NULL,"@"));
	char *varName = strtok($<stringValue>2,"@");
  if(varSize == 0)  varSize = 1;
  do{
    printf("varName=%s, varType=%d, varSize=%d\n",varName,varType,varSize);
    add_var(varName,varType,varSize);
  }while(varName = strtok(NULL,"@"));
};
identifier_list : ID {$$ = $1;}
				| ID COMMA_T identifier_list {
				strcat($$,"@");
				strcat($$,$<stringValue>3);
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
int add_var(char *name, int type, int size){
    struct vartab *vp;
    if(lookup_var(name)){
        printf("!! warning: variable %s already defined \n",name);
        return 0;
    }
    vp=(struct vartab*)malloc(sizeof(struct vartab));
    vp->next = varlist;
    vp->name=(char*)malloc(strlen(name)+1);
    strcpy(vp->name,name);
    vp->type=type;
    vp->size=size;
    varlist = vp;
    /**/
    if(type == INTVAL || type == INTARR){
      vp->ivalarr = (int*)malloc(sizeof(int)*size);
    }
    else if(type == FLOATVAL || type == FLOATARR){
      vp->fvalarr = (float*)malloc(sizeof(float)*size);
    }

    return 1;
}
struct vartab * lookup_var(char *name){
    struct vartab *vp = varlist;
    
    for(;vp;vp=vp->next){
        if(strcmp(vp->name,name)==0)
        return vp;
    }
    return 0;
}

void printList(struct vartab* vp){
  int cnt = 0;
  while(vp){
    if(vp->type == INTVAL || vp-> type == INTARR){
      for(int i = 0; i < vp->size; i++){
        printf("%s[%d] %d\n",vp->name,i, vp->ivalarr[i]);
      } 
    }
    else if(vp->type == FLOATVAL || vp-> type == FLOATARR){
      for(int i = 0; i < vp->size; i++){
        printf("%s[%d] %f\n",vp->name,i, vp->ivalarr[i]);
      } 
    }
    vp = vp->next;
    cnt++;
  }
  printf("# of variable is %d\n", cnt);
  return;
}