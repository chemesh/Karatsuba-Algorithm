#include "Multiply.h"

using namespace DSP1;


void checkAndSet(Multiply& op, char* X, char* Y)
{
	int n = op.get_n();

	cin.ignore();
	cin >> X;

	if (!op.set_X(X))
	{

		cout << "wrong output" << endl;
		exit(1);
	}

	cin.ignore();
	cin >> Y;

	while (!op.set_Y(Y))
	{

		cout << "wrong input" << endl;
		exit(1);
	}


}

int* stringToArray(string str)
{
	int len = str.size();
	int i = 0;
	int* arr = new int[len];

	
	for (i = 0; i < len; i++) {
		arr[i] = str[i] - '0';

	}
	return arr;
}
int arrayToNum(int* arr, int size)
{
	int mult = 1;
	int num = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		num += (arr[i]) * mult;
		mult *= 10;
	}
	return num;

}



int main()
{
	char* X = NULL;
	char* Y = NULL;
	int n;
	int* nArr;
	string temp;

	cin >> temp;

	if (temp[0] == '0' && temp.size() > 1)
	{
		cout << "wrong output" << endl;
		exit(0);
	}
	nArr = stringToArray(temp);
	n = arrayToNum(nArr, temp.size());
	

	X = new char[n+1];
	Y = new char[n+1];

	Multiply operation(n);

	checkAndSet(operation, X, Y);


	operation.timesLM();
	operation.LongMult();
	operation.print_product();

	operation.timesRK();
	operation.KaratsubaHelper();
	operation.print_vecProd(1);

	operation.timesIK();
	operation.nrka();
	operation.print_vecProd(2);
	
	
	delete[] X;
	delete[] Y;

	return 0;
}

