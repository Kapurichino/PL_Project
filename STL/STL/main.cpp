#include "header.h"

int main()
{
	CheckTime measure;
	double* input;
	int count;
	cout << "Put Input Data : ";
	cin >> count;

	input = (double*)malloc(sizeof(double) * count);
	input = measure.randomInput(count);

	cout << "Vector Operation Speed : " << measure.checkVector(input, count) << endl << endl;
	cout << "List Operation Speed : " << measure.checkList(input, count) << endl << endl;
	cout << "Set Operation Speed : " << measure.checkSet(input, count) << endl << endl;
	cout << "Stack Operation Speed : " << measure.checkStack(input, count) << endl << endl;
	cout << "Queue Operation Speed : " << measure.checkQueue(input, count) << endl << endl;
}