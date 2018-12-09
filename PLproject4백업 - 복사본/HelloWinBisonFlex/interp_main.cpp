#include <stdlib.h>
#include "AST.h"
#include "interp.h"
#include <iostream>

using namespace std;

extern int yyparse();
extern FILE* yyin;

void _printAST(AST *p);

int main()
{
    int r;
	yyin = fopen("example.txt", "r");
	yyparse();
	fclose(yyin);


    /* execute main */
	//cout << lookupSymbol("main")->func_body->right->left->left->val << endl;

    printf("execute main ...\n");
    r = executeCallFunc(lookupSymbol("main"),NULL);
	//cout << "!!!!!!!!!!!!: " << lookupSymbol("main")->func_body->right->op << endl;
	//_printAST(lookupSymbol("main")->func_body);
    printf("execute end ...\n");
    return r;
}

void error(char *msg)
{
    printf("ERROR: %s\n",msg);
    exit(1);
}

void _printAST(AST *p)
{
	if (p == NULL) {
		printf("()");
		return;
	}
	switch (p->op) {
	case NUM:
		printf("%d", p->val);
		break;
	case STR:
		printf("'%s'", p->str);
		break;
	case SYM:
		printf("'%s'", p->sym->name);
		break;
	case LIST:
		printf("(LIST ");
		while (p != NULL) {
			_printAST(p->left);
			p = p->right;
			if (p != NULL) {
				printf(" ");
			}
		}
		printf(")");
		break;
	default:
		printf("(%s ", p->op);
		_printAST(p->left);
		printf(" ");
		_printAST(p->right);
		printf(")");
	}
	fflush(stdout);
}