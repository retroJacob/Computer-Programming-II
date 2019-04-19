//		Author: Jacob Morones
//      Class: Computer Programming II 
//      Description: this program prompts the user to enter a length in feet and inches and outputs the equivalent length in centimeters

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

 double getLength();

int main()
{
	double feet = 0;
	double inches = 0;
	double length = 0;

	cout << fixed << showpoint << setprecision(2);

	cout << "Feet: ";
	feet = getLength();

	cout <<  endl << "Inches: ";
	inches = getLength();


	length = feet * 12 + inches;

	//there are 2.54 centimeters per inch.  
	cout << "Centimeter: " << length * 2.54;
} 

double getLength()
{	
	double x;
	bool finish = false;

	do
	try {
		cout << "Enter a non-negative number: ";
		cin >> x;
	 

		if (0 >= x)
			throw x;
		if (!cin)
			throw string("The input stream is in the fail state.");
		
		finish = true;
		return x;

	}
	catch (double j)
	{
		cout << "Invalid input: " << j << endl << endl;
		cin.clear();
		cin.ignore(75, '\n');
	}
	catch (string y)
	{
		cout << "Invalid input: " << y << endl << endl;
		 
	} while (!finish);
}
/*
Feet: Enter a non-negative number: a
Invalid input: 0.00

Enter a non-negative number: -1
Invalid input: -1.00

Enter a non-negative number: 5.5

Inches: Enter a non-negative number: b
Invalid input: 0.00

Enter a non-negative number: -3
Invalid input: -3.00

Enter a non-negative number: 1
Centimeter: 170.18
*/


/*
Feet: Enter a non-negative number: a
Invalid input: 0.00

Enter a non-negative number: -1
Invalid input: -1.00

Enter a non-negative number: 10

Inches: Enter a non-negative number: -2
Invalid input: -2.00

Enter a non-negative number: c
Invalid input: 0.00

Enter a non-negative number: 13
Centimeter: 337.82
*/