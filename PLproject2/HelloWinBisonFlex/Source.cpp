#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string.h>
#include <string>
#include <stdio.h>
#include <deque>

#pragma warning (disable: 4005)
#pragma warning (disable: 4996)

#define NULL 0

// this function will be generated
// by flex
extern int yyparse();

using namespace std;



struct Symtab {
	
	string name;
	int *ivalarr;
	float *fvalarr;
	int type;
	int size;
	int address;
	int args;
};
int instline = 0;
int basesize = 10;
int globaldoubled = 1;
int localdoubled = 1;
int globalnum = 0;
int localnum = 0;
vector<Symtab> gTable;
vector<Symtab> lTable;

int state;
int add_var(string name, int type, int size);
int lookup_global_exist(string name);
Symtab lookup_var(string name);
void printList();
void yyerror(const char *str) {
	printf("%s", str);
}


enum {
	LOOKUP = 0,
	INTVAL,
	FLOATVAL,
	INTARR,
	FLOATARR
};
// this function is called syntax parser
// just the parser, the parse
extern int yyparse();



// we have to code this function

char* getToken(char *input,int num) {//3@8 , 1 일경우
	int i = 0;
	int startat = 0;
	int numcount = -1;
	int strcount = 0;

	int beforetoken = 0;
	cout << "input string : " << input << endl;
	while (input[i]) {
		cout << "input[i]=" << input[i] << "i=" << i << "starat" << startat << "  numcount" << numcount << "  strcount" << strcount << "  beforetoken" << beforetoken << endl;
		if (input[i] == '@') {
			startat = i - strcount;
			numcount++;
			beforetoken = 1;
		} else if (beforetoken == 1) {
			cout << "초기화";
			strcount = 0;
			beforetoken = 0;
			startat = i-strcount;
		}
		if (numcount == num) break;
		i++;
		strcount++;
	}
	
	string temp(input);
	cout << "TEMP : " << temp << endl;
	string temp2 = temp.substr(startat, i);
	cout << "TEMP2 : " << temp2 << endl;
	cout << "TEMP2는 " << startat << " 과 " << i << "로 짤림" << endl;
	char *temp3 = new char(temp2.length()+1);
	strcpy(temp3, temp2.c_str());
	cout << "RETURN STRING : " << temp3 << endl;
	return temp3;
}

int getTokenCount(char *input) {
	int i = 0;
	int count = 1;
	while (input[i]) {
		if (input[i] == '@') {
			count++;
		}
		i++;
	}
	cout << "return token count : " << count << endl;
	return count;
}

int add_var(string name, int type, int size) {

	if (lookup_global_exist(name)) {
		printf("!! warning: variable %s already defined \n", name);
		return 0;
	}

	

	Symtab vp;

	vp.name = name;
	vp.type = type;
	vp.size = size;

	/**/
	if (type == INTVAL || type == INTARR) {
		vp.ivalarr = (int*)malloc(sizeof(int)*size);
	}
	else if (type == FLOATVAL || type == FLOATARR) {
		vp.fvalarr = (float*)malloc(sizeof(float)*size);
	}

	gTable.push_back(vp);
	globalnum++;
	return 1;
}
int lookup_global_exist(string name) {
	Symtab temp;
	int i;
	for (i = 0; i<globalnum; i++) {
		temp = gTable[i];
		if(temp.name == name)
			return 1;
	}
	return 0;
}
Symtab lookup_var(string name) {
	Symtab temp;
	int i;
	for (i = 0; i<globalnum; i++) {
		temp = gTable[i];
		if (temp.name == name)
			return temp;
	}
}

void printList() {
	
	printf("global num : %d\n", globalnum);
	int cnt;
	for (cnt = 0; cnt<globalnum; cnt++) {
		if (gTable[cnt].type == INTVAL || gTable[cnt].type == INTARR) {
			int i = 0;
			for (i = 0; i < gTable[cnt].size; i++) {
				printf("%s[%d] %d\n", gTable[cnt].name, i, gTable[cnt].ivalarr[i]);
			}
		}
		else if (gTable[cnt].type == FLOATVAL || gTable[cnt].type == FLOATARR) {
			int i = 0;
			for (i = 0; i < gTable[cnt].size; i++) {
				printf("%s[%d] %f\n", gTable[cnt].name, i, gTable[cnt].fvalarr[i]);
			}
		}
	}
	printf("# of variable is %d\n", cnt);

	return;
}