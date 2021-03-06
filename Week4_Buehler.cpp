#include "stdafx.h" 
#include <iostream>
#include <string>
using namespace std;

//4.13
int main(int argc, char* argv[])
{
	int milesTrip{ 0 }, gallonsTrip{ 0 }, milesTotal{ 0 }, gallonsTotal{ 0 };
	do
	{
		cout << "Enter miles driven (-1 to quit): ";
		cin >> milesTrip;
		if (milesTrip != -1)
		{
			milesTotal += milesTrip;
			cout << "Enter gallons used: ";
			cin >> gallonsTrip;
			gallonsTotal += gallonsTrip;
			cout << "MPG this trip: " << 1.0f * milesTrip / gallonsTrip << endl;
			cout << "Total MPG: " << 1.0f * milesTotal / gallonsTotal << endl << endl;
		}
	} while (milesTrip != -1);

	return 0;
}

//4.17
int main(int argc, char* argv[])
{
	int counter{ 1 }, number{ 0 }, largest{ 0 };
	while (counter <= 10)
	{
		cout << "Enter a number (" << counter << "): ";
		cin >> number;
		if (counter == 1 || largest < number)
		{
			largest = number;
		}
		counter++;
	}
	cout << "The largest number was: " << largest << endl;
	return 0;
}

//4.26
int main(int argc, char* argv[])
{
	int size{ 0 };
	while (size < 1 || size > 20)
	{
		cout << "Input size of square (1-20): ";
		cin >> size;
	}

	for (int x = 1; x <= size; x++)
	{
		for (int y = 1; y <= size; y++)
		{
			if (x == 1 || x == size || y == 1 || y == size)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}

//4.35
int main(int argc, char* argv[])
{
	int inputNumber{ -1 }, number{ -1 }, factorial{ 1 };
	float natural{ 1.0f };
	while (inputNumber < 0)
	{
		cout << "What is your non-negative number?: ";
		cin >> inputNumber;
	}
	number = inputNumber;
	while (number > 1)
	{
		factorial *= number;
		natural += 1.0f / number;
		number--;
	}
	cout << "The factorial of " << inputNumber << " is " << factorial << endl;
	cout << "The natural number constant (accuracy of " << inputNumber << ") is " << natural << endl;
	return 0;
}