#include <stdlib.h>
#include "AST.h"
#include "interp.h"
#include <iostream>

using namespace std;

static void printFunc(AST *args);

int executeExpr(AST *p)
{
	//cout << "P의 op는 = " << p->op << endl;
    if(p == NULL) return 0;
    switch(p->op){
    case NUM:
	return p->val;
    case SYM:
	return getValue(getSymbol(p));
	case NOT_OP:
		return !executeExpr(p->left);
    case EQ_OP:
	return setValue(getSymbol(p->left),executeExpr(p->right));
    case PLUS_OP:
	return executeExpr(p->left) + executeExpr(p->right);
    case MINUS_OP:
	return executeExpr(p->left) - executeExpr(p->right);
    case MUL_OP:
	return executeExpr(p->left) * executeExpr(p->right);
    case LT_OP:
	return executeExpr(p->left) < executeExpr(p->right);
    case GT_OP:
	return executeExpr(p->left) > executeExpr(p->right);
	case DIFF_OP:
		return executeExpr(p->left) != executeExpr(p->right);
	case LOE_OP:
		return executeExpr(p->left) <= executeExpr(p->right);
	case GOE_OP:
		return executeExpr(p->left) >= executeExpr(p->right);
	case EQUAL_OP:
		return executeExpr(p->left) == executeExpr(p->right);
    case GET_ARRAY_OP:
	return getArray(getSymbol(p->left),(int)executeExpr(p->right));
    case SET_ARRAY_OP:
	return setArray(getSymbol(getNth(p->left,0)),
			(int)executeExpr(getNth(p->left,1)),
			executeExpr(p->right));
    case CALL_OP:
	return executeCallFunc(getSymbol(p->left),p->right);
    case PRINTLN_OP:
	printFunc(p->left);
	return 0;
    default:
		//cout << "DEFAULT" << endl;
		;
    }
}

static void printFunc(AST *args)
{
    AST *p;
	//puts("");
    //p = getNth(args,0);
	//if (p->op != STR);
    //printf(p->str,executeExpr(getNth(args,1)));

	printf("%d", executeExpr(args));

    printf("\n");
}

/*
 * global variable
 */
void declareVariable(Symbol *vsym,AST *init_value)
{

	//cout << "변수AST만들어짐" << endl;
    if(init_value != NULL){
	vsym->val = executeExpr(init_value);
    }
}

/* 
 * Array
 */
/*void declareArray(Symbol *a, AST *size)
{
    a->addr = (float*)malloc(sizeof(float)*executeExpr(size));
}*/

