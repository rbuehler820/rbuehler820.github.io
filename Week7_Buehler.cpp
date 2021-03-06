#include "stdafx.h"  // only required for Visual Studio
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

//6.24
int calcRem(int a, int b)
{
	return a % b;
}

//6.24
int calcWhole(int a, int b)
{
	return (a - calcRem(a, b)) / b;
}

//6.25
int secondsSince12(int h, int m, int s)
{
	return (h * 3600) + ((60 - m) * 60) + s;
}

//6.26
int fahrToCels(int tempF)
{
	return (tempF - 32) * 5 / 9;
}

//6.26
int celsToFahr(int tempC)
{
	return (tempC * 9 / 5) + 32;
}

//6.28
vector<int> getDivisors(int number)
{
	vector<int> divisors = { 1 };
	for (int x = 2; x < number; x++)
	{
		if (number % x == 0)
		{
			divisors.push_back(x);
		}
	}
	return divisors;
}

//6.28
bool isPerfect(int number)
{
	int sum{ 0 };
	bool answer{ false };
	for (int x : getDivisors(number))
	{
		sum += x;
	}
	if (sum == number)
	{
		answer = true;
	}
	else
	{
		answer = false;
	}
	return answer;
}

//6.30
int reverseDigits(int number)
{
	int x{ number };
	int rem{ 0 };
	int reverse{ 0 };
	while (x != 0)
	{
		rem = x % 10;
		reverse = reverse * 10 + rem;
		x /= 10;
	}
	return reverse;
}

//6.36
int power(int base, int exp)
{
	int total{ base };
	for (int x = exp; x > 1; x--)
	{
		total *= base;
	}
	return total;
}

//6.40
unsigned long factorial(unsigned long number) {
	if (number <= 1) { // test for base case     
		cout << "1\n";
		return 1; // base cases: 0! = 1 and 1! = 1
	}
	else { // recursion step        
		cout << number << "*";
		return number * factorial(number - 1);
	}
}

//6.42
double distance(double x1, double y1, double x2, double y2)
{
	double distancex = pow(x2 - x1, 2.0);
	double distancey = pow(y2 - y1, 2.0);
	double distance = sqrt(distancex + distancey);
	return distance;
}

int main(int argc, char* argv[])
{
	//6.24
	int input{ 0 };
	while (input < 1 || input > 32767)
	{
		cout << "Enter a number (1-32767): ";
		cin >> input;
	}

	string number{ to_string(input) };
	for (char c : number)
	{
		cout << c << "  ";
	}
	cout << endl;

	//6.25
	cout << "Time difference between 04:35:13 and 09:27:42 is... " << secondsSince12(9, 27, 42) - secondsSince12(4, 35, 13) << " seconds." << endl;

	//6.26
	cout << "Celsius to Fahrenheit(0 - 100 degrees)" << endl;
	cout << "| F  " << " C |" << " F  " << " C |" << " F  " << " C |" << " F  " << " C |" << endl;
	cout << "|--- " << "---|" << "--- " << "---|" << "--- " << "---|" << "--- " << "---|" << endl;
	for (int x = 1; x <= 25; x++)
	{
		printf("|%3d %3d|%3d %3d|%3d %3d|%3d %3d|\n", x, celsToFahr(x), x + 25, celsToFahr(x + 25), x + 50, celsToFahr(x + 50), x + 75, celsToFahr(x + 75));
	}

	cout << "Fahrenheit to Celsius(32 - 212 degrees)" << endl;
	cout << "| C  " << " F |" << " C  " << " F |" << " C  " << " F |" << " C  " << " F |" << endl;
	cout << "|--- " << "---|" << "--- " << "---|" << "--- " << "---|" << "--- " << "---|" << endl;
	for (int x = 32; x <= 212; x++)
	{
		if (x > 32 && x % 4 == 0)
		{
			cout << "|" << endl;
		}
		printf("|%3d %3d", x, fahrToCels(x));
	}
	cout << "|" << endl << endl;

	//6.28
	for (int x = 1; x <= 10000; x++)
	{
		if (isPerfect(x))
		{
			vector<int> divisors = getDivisors(x);
			cout << x << " is perfect: ";
			vector<int>::iterator ptr;
			for (ptr = divisors.begin(); ptr < divisors.end(); ptr++)
			{
				cout << *ptr;
				if (ptr < divisors.end() - 1)
				{
					cout << "+";
				}
				else
				{
					cout << endl;
				}
			}
		}
	}

	//6.30
	int num{ 0 };
	cout << "Pick an integer: ";
	cin >> num;
	cout << "It's reverse is: " << reverseDigits(num) << endl;

	//6.36
	cout << power(3, 4) << endl;

	//6.40
	for (unsigned int counter{ 0 }; counter <= 10; ++counter) {
		cout << counter << "! = " << factorial(counter) << endl;
	}

	//6.42
	cout << "Distance between (3,2) and (5,4): " << distance(3, 2, 5, 4) << endl;

	return 0;
}

//6.47
unsigned int rollDice(); // rolls dice, calculates and displays sum
enum class Status { CONTINUE, WON, LOST }; // all caps in constants

Status craps() {
	// scoped enumeration with constants that represent the game status 


											   // randomize random number generator using current time
	srand(static_cast<unsigned int>(time(0)));

	unsigned int myPoint{ 0 }; // point if no win or loss on first roll
	Status gameStatus; // can be CONTINUE, WON or LOST
	unsigned int sumOfDice{ rollDice() }; // first roll of the dice

										  // determine game status and point (if needed) based on first roll
	switch (sumOfDice) {
	case 7: // win with 7 on first roll
	case 11: // win with 11 on first roll           
		gameStatus = Status::WON;
		break;
	case 2: // lose with 2 on first roll
	case 3: // lose with 3 on first roll
	case 12: // lose with 12 on first roll             
		gameStatus = Status::LOST;
		break;
	default: // did not win or lose, so remember point
		gameStatus = Status::CONTINUE; // game is not over
		myPoint = sumOfDice; // remember the point
		cout << "Point is " << myPoint << endl;
		break; // optional at end of switch  
	}

	// while game is not complete
	while (Status::CONTINUE == gameStatus) { // not WON or LOST
		sumOfDice = rollDice(); // roll dice again

								// determine game status
		if (sumOfDice == myPoint) { // win by making point
			gameStatus = Status::WON;
		}
		else {
			if (sumOfDice == 7) { // lose by rolling 7 before point
				gameStatus = Status::LOST;
			}
		}
	}

	return gameStatus;
}

//6.47
int main()
{
	int balance{ 1000 };
	int wager{ 0 };
	while (balance > 0)
	{
		while (wager < 1 || wager > balance)
		{
			cout << "Enter a wager (Balance: $" << balance << ") - ";
			cin >> wager;
		}

		Status gameStatus = craps();
		// display won or lost message
		if (Status::WON == gameStatus) {
			balance += wager;
			cout << "Player wins! New balance: $" << balance << endl;
		}
		else {
			balance -= wager;
			cout << "Player loses! ";
			if (balance == 0)
			{
				cout << "You're broke like a joke!" << endl;
			}
			else if (balance < 100)
			{
				cout << "Almost out of $$$$$!" << endl;
			}
			else if (balance < 500)
			{
				cout << "Maybe its time to walk away..." << endl;
			}
			else
			{
				cout << "Losin' money quickly!" << endl;
			}
		}
		wager = 0;
	}

	return 0;
}

// roll dice, calculate sum and display results
unsigned int rollDice() {
	int die1{ 1 + rand() % 6 }; // first die roll
	int die2{ 1 + rand() % 6 }; // second die roll
	int sum{ die1 + die2 }; // compute sum of die values

							// display results of this roll
	cout << "Player rolled " << die1 << " + " << die2
		<< " = " << sum << endl;
	return sum;
}