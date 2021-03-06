#include "stdafx.h"  
#include <iostream>
using namespace std;

//7.13
const int ARRAYSIZE = 20;

bool checkDuplicate(const int numbers[ARRAYSIZE], int x, int index)
{
	bool result{ false };
	for (int i = 0; i < index; i++)
	{
		if (numbers[i] == x)
		{
			result = true;
		}
	}
	return result;
}

int main()
{
	int num{ 0 };
	int index{ 0 };
	int numbers[ARRAYSIZE];

	cout << "Enter " << ARRAYSIZE << " integers (10 - 100) - " << endl << endl;
	for (int i = 0; i < ARRAYSIZE; i++)
	{
		while (num < 10 || num > 100)
		{
			cout << i + 1 << ")" << " Enter an integer: ";
			cin >> num;
		}
		if (!checkDuplicate(numbers, num, index))
		{
			numbers[index] = num;
			index++;
		}
		num = 0;
	}

	cout << endl << "Unique values entered: " << endl;
	for (int i = 0; i < index; i++)
	{
		cout << numbers[i] << endl;
	}

	return 0;
}