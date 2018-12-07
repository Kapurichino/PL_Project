#include <stdlib.h>
#include "AST.h"
#include "interp.h"
extern int yyparse();
extern FILE* yyin;

int main()
{
    int r;
    yyin = fopen("example.txt", "r")
    yyparse();
    fclose(yyin);

    /* execute main */
    printf("execute main ...\n");
    r = executeCallFunc(lookupSymbol("main"),NULL);
    printf("execute end ...\n");
    return r;
}

void error(char *msg)
{
    printf("ERROR: %s\n",msg);
    exit(1);
}
