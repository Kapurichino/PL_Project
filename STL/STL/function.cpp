#include "header.h"

double Operator::insert(int type, double* input, int count)
{
	begin = clock();
	switch (type) //switch문은 성능 측정에 크게 영향을 주지 않는 것으로 판단.
	{
	case 0:
		for (int x = 0; x < count; x++)
		{
			chkVector.push_back(input[x]);
		}
		break;
	case 1:
		for (int x = 0; x < count; x++)
		{
			chkList.push_back(input[x]);
		}
		break;
	case 2:
		for (int x = 0; x < count; x++)
		{
			chkSet.insert(input[x]);
		}
		break;
	case 3:
		for (int x = 0; x < count; x++)
		{
			chkStack.push(input[x]);
		}
		break;
	case 4:
		for (int x = 0; x < count; x++)
		{
			chkQueue.push(input[x]);
		}
		break;
	default:
		cout << "insert operation error" << endl;
	}
	end = clock();

	return ((double)(end - begin) / 1000);
}

double Operator::search(int type, double* input, int count)
{
	std::vector<double>::iterator iterVector;
	std::list<double>::iterator iterList;
	std::set<double>::iterator iterSet;
	double* data;
	int cnt = 0;

	begin = clock();
	switch (type) //switch문은 성능 측정에 크게 영향을 주지 않는 것으로 판단.
	{
	case 0:
		iterVector = find(chkVector.begin(), chkVector.end(), key);
		break;
	case 1:
		iterList = find(chkList.begin(), chkList.end(), key);
		break;
	case 2:
		binary_search(chkSet.begin(), chkSet.end(), key);
		break;
	case 3:
		data = (double*)malloc(sizeof(double));
		data[cnt] = chkStack.top();
		chkStack.pop();
		while (data[cnt] != key)
		{
			++cnt;
			data = (double*)realloc(data, (cnt + 1) * sizeof(double));
			data[cnt] = chkStack.top();
			chkStack.pop();
		}
		break;
	case 4:
		data = (double*)malloc(sizeof(double));
		data[cnt] = chkQueue.front();
		chkQueue.pop();
		while (data[cnt] != key)
		{
			++cnt;
			data = (double*)realloc(data, (cnt + 1) * sizeof(double));
			data[cnt] = chkQueue.front();
			chkQueue.pop();
		}
		break;
	default:
		cout << "search operation error" << endl;
	}
	end = clock();

	if (type == STL::stack) 
	{
		while (cnt >= 0)
			chkStack.push(data[cnt--]);
		free(data);
	}
	if (type == STL::queue)
	{
		while (cnt >= 0)
			chkQueue.push(data[cnt--]);
		free(data);
	}
	return ((double)(end - begin) / 1000);
}

double Operator::remove(int type, double* input, int count)
{
	begin = clock();
	switch (type)
	{
	case 0:
		chkVector.clear();
		break;
	case 1:
		chkList.clear();
		break;
	case 2:
		chkSet.clear();
		break;
	case 3:
		while(!chkStack.empty())
			chkStack.pop();
		break;
	case 4:
		while (!chkQueue.empty())
			chkQueue.pop();
		break;
	default:
		cout << "remove operation error" << endl;
	}
	end = clock();

	return ((double)(end - begin) / 1000);
}

double* Operator::randomInput(int count)
{
	srand(time(NULL));
	double* temp;
	temp = (double*)malloc(sizeof(double) * count);
	for (int cnt = 0; cnt < count; cnt++)
	{
		temp[cnt] = rand() % 100000 + 1;
	}
	key = rand() % 1000000 + 1;
	temp[rand() % MAXINPUT] = key;
	return temp;
}


double CheckTime::checkVector(double* input, int count)
{
	insertTime = insert(STL::vector, input, count);
	cout << "vector's insert time is " << insertTime << endl;

	searchTime = search(STL::vector, input, count);
	cout << "vector's search time is " << searchTime << endl;

	removeTime = remove(STL::vector, input, count);
	cout << "vector's remove time is " << removeTime << endl;

	totalTime = insertTime + searchTime + removeTime;
	cout << "vector's total time is " << totalTime << endl;
	return totalTime;
}

double CheckTime::checkList(double* input, int count)
{
	insertTime = insert(STL::list, input, count);
	cout << "list's insert time is " << insertTime << endl;

	searchTime = search(STL::list, input, count);
	cout << "list's search time is " << searchTime << endl;

	removeTime = remove(STL::list, input, count);
	cout << "list's remove time is " << removeTime << endl;

	totalTime = insertTime + searchTime + removeTime;
	cout << "list's total time is " << totalTime << endl;
	return totalTime;
}

double CheckTime::checkSet(double* input, int count)
{
	insertTime = insert(STL::set, input, count);
	cout << "set's insert time is " << insertTime << endl;

	searchTime = search(STL::set, input, count);
	cout << "set's search time is " << searchTime << endl;

	removeTime = remove(STL::set, input, count);
	cout << "set's remove time is " << removeTime << endl;

	totalTime = insertTime + searchTime + removeTime;
	cout << "set's total time is " << totalTime << endl;
	return totalTime;
}

double CheckTime::checkStack(double* input, int count)
{
	insertTime = insert(STL::stack, input, count);
	cout << "stack's insert time is " << insertTime << endl;

	searchTime = search(STL::stack, input, count);
	cout << "stack's search time is " << searchTime << endl;

	removeTime = remove(STL::stack, input, count);
	cout << "stack's remove time is " << removeTime << endl;

	totalTime = insertTime + searchTime + removeTime;
	cout << "stack's total time is " << totalTime << endl;
	return totalTime;
}

double CheckTime::checkQueue(double* input, int count)
{
	insertTime = insert(STL::queue, input, count);
	cout << "queue's insert time is " << insertTime << endl;

	searchTime = search(STL::queue, input, count);
	cout << "queue's search time is " << searchTime << endl;
	
	removeTime = remove(STL::queue, input, count);
	cout << "queue's remove time is " << removeTime << endl;

	totalTime = insertTime + searchTime + removeTime;
	cout << "queue's total time is " << totalTime << endl;
	return totalTime;
}