#include <stdlib.h>
#include "AST.h"
#include <iostream>

using namespace std;

Symbol SymbolTable[MAX_SYMBOLS];
int n_symbols = 0;

AST *makeNum(int val)
{
	cout << "int AST만들어짐" << endl;
    AST *p;
    p = (AST *)malloc(sizeof(AST));
    p->op = NUM;
    p->val = val;
    return p;
}
AST *makeFloat (float val)
{
	AST *p;
	p = (AST *)malloc(sizeof(AST));
	p->op = FLO;
	p->val = val;
	return p;
}



AST *makeAST(enum code op,AST *left,AST *right)
{

    AST *p;
    p = (AST *)malloc(sizeof(AST));
    p->op = op;
    p->right = right;
    p->left = left;
    return p;
}

AST *getNth(AST *p,int nth)
{
    if(p->op != LIST){
	fprintf(stderr,"bad access to list\n");
	exit(1);
    }
    if(nth > 0) return(getNth(p->right,nth-1));
    else return p->left;
}

AST *addLast(AST *l,AST *p)
{
    AST *q;

    if(l == NULL) return makeAST(LIST,p,NULL);
    q = l;
    while(q->right != NULL) q = q->right;
    q->right = makeAST(LIST,p,NULL);
    return l;
}

AST *getNext(AST *p)
{
    if(p->op != LIST){
	fprintf(stderr,"bad access to list\n");
	exit(1);
    }
    else return p->right;
}

Symbol *lookupSymbol(char *name)
{
    int i;
    Symbol *sp;

    sp = NULL;
    for(i = 0; i < n_symbols; i++){
	if(strcmp(SymbolTable[i].name,name) == 0){
	    sp = &SymbolTable[i];
		cout << "심볼 중복됨" << endl;
	    break;
	}
    }
    if(sp == NULL){//못찾았을경우
	sp = &SymbolTable[n_symbols++];
	sp->name = _strdup(name);
    }
    return sp;
}

AST *makeSymbol(char *name)
{

	cout << "심볼만들어짐" << name << endl;
    AST *p;

    p = (AST *)malloc(sizeof(AST));
    p->op = SYM;
    p->sym = lookupSymbol(name);
    return p;
}

Symbol *getSymbol(AST *p)
{
	cout << p->op << endl;
    if(p->op != SYM){
	fprintf(stderr,"bad access to symbol\n");
	exit(1);
    }
    else return p->sym;
}