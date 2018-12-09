
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

enum code {
    LIST,
    NUM,
	FLO,
    STR,
    SYM,
    EQ_OP,//assign
    PLUS_OP,
    MINUS_OP,
    MUL_OP,
    LT_OP,
    GT_OP,
	LOE_OP,
	GOE_OP,
	DIV_OP,
	DIFF_OP,
	EQUAL_OP,// ==
    GET_ARRAY_OP,
    SET_ARRAY_OP,
    CALL_OP,
    PRINTLN_OP,
    IF_STATEMENT,
    BLOCK_STATEMENT,
    RETURN_STATEMENT,
    WHILE_STATEMENT,
    FOR_STATEMENT
};
  

typedef struct abstract_syntax_tree {
    enum code op;
    int val;
    struct symbol *sym;
    struct abstract_syntax_tree *left,*right;
    char *str;
} AST;

typedef struct symbol {
    char *name;
    float val;
    int *addr;
    AST *func_params;
    AST *func_body;
} Symbol;

#define MAX_SYMBOLS 100

extern Symbol SymbolTable[];
extern int n_symbols;

//void ASTPrint(AST *p);

AST *makeSymbol(char *name);
Symbol *lookupSymbol(char *name);
Symbol *getSymbol(AST *p);

AST *makeNum(int val);
AST *makeFloat(float val);
//AST *makeStr(char *s);
AST *makeAST(enum code op,AST *right,AST *left);

AST *getNth(AST *p,int nth);
AST *getNext(AST *p);
AST *addLast(AST *l,AST *p);
AST *addList(AST *list1, AST* list2);

#define getFirst(p) getNth(p,0)
#define makeList1(x1) makeAST(LIST,x1,NULL)
#define makeList2(x1,x2) makeAST(LIST,x1,makeAST(LIST,x2,NULL))
#define makeList3(x1,x2,x3) makeAST(LIST,x1,makeAST(LIST,x2,makeAST(LIST,x3,NULL)))

void defineFunction(Symbol *fsym, AST *params, AST *body);
void declareVariable(Symbol *vsym, AST *init_value);
void declareArray(Symbol *asym, AST *size);