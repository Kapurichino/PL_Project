#include "AST.h"
#include "interp.h"
#include <setjmp.h>
#include <iostream>

using namespace std;


int envp = 0;
Environment Env[MAX_ENV];

jmp_buf *funcReturnEnv;
int funcReturnVal;

static int executeFuncArgs(AST *params,AST *args);

void defineFunction(Symbol *fsym,AST *params,AST *body)
{
    fsym->func_params = params;
    fsym->func_body = body;
}

/*
 * For environment
 */
int setValue(Symbol *var,int val)
{
    int i;
    for(i = envp-1; i >= 0; i--){
	if(Env[i].var == var){
	    Env[i].val = val;
	    return val;
	}
    }
    var->val = val;
    return val;
}

int getValue(Symbol *var)
{
    int i;
    for(i = envp-1; i >= 0; i--){
	if(Env[i].var == var) return Env[i].val;
    }
    return var->val;
}

float getArray(Symbol *var, int index)
{
	
	int i;
	for (i = envp - 1; i >= 0; i--) {
		if (Env[i].var == var) return Env[i].arrAddr[index];
	}
	return var->val;
}

float setArray(Symbol *var, int index, float value)
{
	//cout << "NAME: "<<var->name << endl;
	int i;
	for (i = envp - 1; i >= 0; i--) {
		if (Env[i].var == var) {
			//cout << "찾았당" << endl;
			Env[i].arrAddr[index] = value;
			//cout << "값 설정" << endl;
			return Env[i].arrAddr[index];
		}
	}
	return var->val;
}




int executeCallFunc(Symbol *f,AST *args)
{
	//cout << "찾아서 실행함" << endl;
    int nargs;
    int val;
    jmp_buf ret_env;
    jmp_buf *ret_env_save;
    
    nargs = executeFuncArgs(f->func_params,args);

    ret_env_save = funcReturnEnv;
    funcReturnEnv = &ret_env;

    if(setjmp(ret_env) != 0){
	val = funcReturnVal;
    } else {
		//cout << "함수의 body를 실행합니다" << endl;
	executeStatement(f->func_body);

    }
    envp -= nargs;
    funcReturnEnv = ret_env_save;
    return val;
}

static int executeFuncArgs(AST *params,AST *args)
{
  Symbol *var;
  int val;
  int nargs;

  if (params == NULL) {
	  //cout << "함수의 파라미터가 없음" << endl;
	  return 0;
  }
  val = executeExpr(getFirst(args));
  var = getSymbol(getFirst(params));
  nargs = executeFuncArgs(getNext(params),getNext(args));
  Env[envp].var = var;
  Env[envp].val = val;
  envp++;
  return nargs+1;
}

void executeReturn(AST *expr)
{
    funcReturnVal = executeExpr(expr);
    longjmp(*funcReturnEnv,1);
}

void executeStatement(AST *p)
{
    if(p == NULL) return;
    switch(p->op){
    case BLOCK_STATEMENT:
	//cout << "BLOCK_STATEMENT" << endl;
	executeBlock(p->left,p->right);
	break;
    case RETURN_STATEMENT:
	executeReturn(p->left);
	break;
    case IF_STATEMENT:
	executeIf(p->left,getNth(p->right,0),getNth(p->right,1));
	break;
    case WHILE_STATEMENT:
		//cout << "값"<<p->left->left->sym->name << endl;
		executeWhile(p->left, p->right);
	break;
    default:
		//cout << "defaultstatement" << endl;
	executeExpr(p);
    }
}

void executeBlock(AST *local_vars,AST *statements)
{
    AST *vars;
    int envp_save;

    envp_save = envp;
	for (vars = local_vars; vars != NULL; vars = getNext(vars)) {
		Symbol *temp = getSymbol(getFirst(vars));
		//cout << "로컬변수 가져옴" << endl;
		if (temp->type == I || temp->type == F) {
			Env[envp].var = temp;
		}
		else if (temp->type == IA || temp->type == FA) {
			Env[envp].var = temp;
			Env[envp].arrAddr = (float*)malloc(temp->size * sizeof(float));
			//cout << "메모리 할당 성공" << endl;
		}
		else {
			//cout << "type error" << endl;
			exit(1);
		}
		Env[envp++].type = temp->type;
	}
	for (; statements != NULL; statements = getNext(statements)) {
		//cout << "statement 가져옴" << endl;
		//cout << statements << endl;
		executeStatement(getFirst(statements));
	}
    envp = envp_save;
    return;
}

void executeIf(AST *cond, AST *then_part, AST *else_part)
{
	//cout << "cond:" << cond->right->sym->val << endl;
	if (executeExpr(cond))
		executeBlock(NULL, then_part);
	//executeStatement(then_part);
	else
		executeBlock(NULL, else_part);
	//executeStatement(else_part);
}

void executeWhile(AST *cond,AST *body)
{
	while (executeExpr(cond)) {
		//cout<<cond->left->sym->name<<endl;
		//executeStatement(body);
		executeBlock(NULL, body);
	}
}

void executeFor(AST *init,AST *cond,AST *iter,AST *body)
{
    /* not implmented */
}




