#include <time.h>
#include <math.h>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAXINPUT 3000000


enum STL
{
	vector,
	list,
	set,
	stack,
	queue
};

class Operator
{
private:
	clock_t begin;
	clock_t end;
	std::vector<double> chkVector;
	std::list<double> chkList;
	std::set<double> chkSet;
	std::stack<double> chkStack;
	std::queue<double> chkQueue;
	double key;
public:
	double insert(int type, double* input, int count);
	double search(int type, double* input, int count);
	double remove(int type, double* input, int count);
	double* randomInput(int count);
};

class CheckTime : public Operator
{
private:
	double insertTime;
	double searchTime;
	double removeTime;
	double totalTime;
public:
	double checkVector(double* input, int count);
	double checkList(double* input, int count);
	double checkSet(double* input, int count);
	double checkStack(double* input, int count);
	double checkQueue(double* input, int count);
};