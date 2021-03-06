// Week2_Buehler.cpp : Week 2 Assignments.

#include "stdafx.h"
#include <iostream>
using namespace std;

/// 2.16
int main()
{
	int a, b;
	cout << "Please enter 2 integers: ";
	cin >> a >> b;
	cout << "The values you entered were: " << a << " and " << b << endl;
	cout << "The sum of the values: " << a + b << endl;
	cout << "The difference of the values: " << a - b << endl;
	cout << "The product of the values: " << a * b << endl;
	cout << "The quotient of the values: " << a / b << endl;
    return 0;
}

/// 2.17
int main()
{
	cout << "1 2 3 4\n";
	cout << "1" << " 2" << " 3" << " 4\n";
	cout << "1";
	cout << " 2";
	cout << " 3";
	cout << " 4\n";

	return 0;
}

/// 2.18
int main()
{
	int a, b;
	cout << "Please enter 2 integers: ";
	cin >> a >> b;
	if (a == b)
		cout << "The numbers are equal.\n";
	else if (a > b)
		cout << a << " is the larger number.\n";
	else
		cout << b << " is the larger number.\n";
	return 0;
}

/// 2.19
int main()
{
	int a, b, c;
	cout << "Input three different integers: ";
	cin >> a >> b >> c;

	int sum = a + b + c;
	int avg = sum / 3;
	int prd = a * b * c;

	int sml = a;
	int lrg = a;

	if (b < sml) sml = b;
	if (c < sml) sml = c;

	if (b > lrg) lrg = b;
	if (b > lrg) lrg = c;

	cout << "Sum is " << sum << endl;
	cout << "Average is " << avg << endl;
	cout << "Product is " << prd << endl;
	cout << "Smallest is " << sml << endl;
	cout << "Largest is " << lrg << endl;
    return 0;
}

/// 2.20
int main()
{
	const float pi = 3.14159;
	int r;
	cout << "Please enter the radius of a circle: ";
	cin >> r;
	cout << "Diameter: " << 2 * r << "\n";
	cout << "Circumference: " << 2 * pi * r << "\n";
	cout << "Area: " << pi * r * r << "\n";
	return 0;
}

/// 2.28
int main()
{
	int n;

	cout << "Enter a five-digit number: ";
	cin >> n;
	cout << n / 10000 << "   ";
	n = n % 10000;
	cout << n / 1000 << "   ";
	n = n % 1000;
	cout << n / 100 << "   ";
	n = n % 100;
	cout << n / 10 << "   ";
	n = n % 10;
	cout << n / 1 << "\n";

	return 0;
}

/// 2.30
int main()
{
	int weight, height;
	cout << "Please enter your weight (in pounds): ";
	cin >> weight;
	cout << "Please enter your height (in inches): ";
	cin >> height;
	float bmi;
	bmi = weight * 703.0 / (height * height);
	cout << "Your BMI: " << bmi << "\n\n";
	cout << "BMI VALUES\n";
	cout << "Underweight: less than 18.5\n";
	cout << "Normal:      between 18.5 and 24.9\n";
	cout << "Overweight:  between 25 and 29.9\n";
	cout << "Obese:       30 or greater\n";
	return 0;
}