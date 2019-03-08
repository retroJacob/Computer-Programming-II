/*
			Author: Jacob Morones
			Class: Computer Programming II
			Description: This program will ask you for a roman number and then it will print out the corresponding roman numeral
*/
#include "pch.h"
#include <iostream>
#include <string>


using namespace std;

// romanType class definition
class romanType
{
public:
	void setRoman(string);
	void romanToDecimal();
	void printDecimal() const;
	void printRoman() const;
	romanType();
	romanType(string);

private:
	string romanNum;
	int decimalNum;
};


// main function
int main()
{
	/******
	* First pass using default constructor.
	******/

	// Student adds code to declare an object of the class romanType, that will use the default constructor.
	romanType romanOne;
	// Student adds code to declare a string variable to hold Roman Number entered by user.
	string inputRoman;


	// Student add code to prompt user to enter Roman Number and then receive it from the keyboard.
	cout << "Enter a Roman Number: ";
	cin >> inputRoman;
	cout << endl;


	// Student add code to invoke the setRoman member function of the romanType class,
	// passing the value entered by the user.
	romanOne.setRoman(inputRoman);


	cout << "The equivalent of the Roman numeral ";
	// Student add code to call the appropriate member function to print the Roman Number
	romanOne.romanToDecimal();
	romanOne.printRoman();
	cout << " is ";

	// Student add code to call the appropriate member function to print the Decimal Number
	romanOne.printDecimal();
	cout << endl << endl;

	/******
	* Second pass using custom constructor.
	******/

	// Student add code to prompt user to enter Roman Number and then receive it from the keyboard.
	cout << "Enter a Roman Number: ";
	cin >> inputRoman;

	// Student adds code to declare an object of the class romanType, that will use the constructor with parameter.
	romanType romanTwo(inputRoman);


	cout << "The equivalent of the Roman numeral ";
	// Student add code to call the appropriate member function to print the Roman Number

	romanTwo.printRoman();
	cout << " is ";

	// Student add code to call the appropriate member function to print the Decimal Number

	romanTwo.printDecimal();
	cout << endl << endl;

	return 0;
}


// romanType class member functions
// default constructor - Initialize both private member variables to a value of 1.
romanType::romanType()
{
	// Student add code to initialize the private member variables.
	romanNum = "I";
	decimalNum = 1;
}


// constructor with passed parameter
romanType::romanType(string rString)
{
	// Student add code to set private member variable to passed value.
	romanNum = rString;
	// Student add code to call the appropriate member function to convert the Roman value to Decimal value.
	romanToDecimal();

}


// member function to initialize private member variable and convert to decimal
void romanType::setRoman(string rString)
{
	// Student add code to set private member variable to passed value.
	romanNum = rString;
	// Student add code to call the appropriate member function to convert the Roman value to Decimal value.
	romanToDecimal();

}


// member function to calculate decimal value of roman number
void romanType::romanToDecimal()
{
	int sum = 0;
	int length = romanNum.length();
	int i;

	int previous = 1000;

	for (i = 0; i < length; i++)
	{
		switch (romanNum[i])
		{
		case 'M':
			sum += 1000;
			if (previous < 1000)
				sum -= 2 * previous;
			previous = 1000;
			break;
		case 'D':

			// Student add code for processing Roman Numeral D, similar to how Roman Number M is processed.
			sum += 500;
			if (previous < 500)
				sum -= 2 * previous;
			previous = 500;
			break;

		case 'C':
			// Student add code for processing Roman Numeral C, similar to how Roman Number M is processed.
			sum += 100;
			if (previous < 100)
				sum -= 2 * previous;
			previous = 100;
			break;

		case 'L':
			// Student add code for processing Roman Numeral L, similar to how Roman Number M is processed.
			sum += 50;
			if (previous < 50)
				sum -= 2 * previous;
			previous = 50;
			break;

		case 'X':
			// Student add code for processing Roman Numeral X, similar to how Roman Number M is processed.
			sum += 10;
			if (previous < 10)
				sum -= 2 * previous;
			previous = 10;
			break;

		case 'V':
			// Student add code for processing Roman Numeral V, similar to how Roman Number M is processed.
			sum += 5;
			if (previous < 5)
				sum -= 2 * previous;
			previous = 5;
			break;

		case 'I':
			// Student add code for processing Roman Numeral I, similar to how Roman Number M is processed.
			sum += 1;
			if (previous < 1)
				sum -= 2 * previous;
			previous = 1;
			break;
		}
	}

	decimalNum = sum;
}

// member function to cout the value of private member variable romanNum
void romanType::printRoman() const
{
	cout << romanNum;
}

// member function to cout the value of private member variable decimalNum
void romanType::printDecimal() const
{
	cout << decimalNum;
}
/*
Enter a Roman Number: MCXIV

The equivalent of the Roman numeral MCXIV is 1114

Enter a Roman Numeral: MCMXLIX
The equivalent of the Roman numeral MCMXLIX is 1949

*/

/*
Enter a Roman Number: CCCLIX

The equivalent of the Roman numeral CCCLIX is 359

Enter a Roman Numeral: MCMXLIII
The equivalent of the Roman numeral MCMXLIII is 1943
*/

/*
Enter a Roman Number: MDCLXVI

The equivalent of the Roman numeral MDCLXVI is 1666

Enter a Roman Numeral: MCMLXIV
The equivalent of the Roman numeral MCMLXIV is 1964
*/

/*
Enter a Roman Number: MMXIV

The equivalent of the Roman numeral MMXIV is 2014

Enter a Roman Numeral: MCMLVII
The equivalent of the Roman numeral MCMLVII is 1957

*/
