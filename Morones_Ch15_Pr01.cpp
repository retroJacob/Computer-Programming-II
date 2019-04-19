/*
		Author: Jacob Morones
		Class: Computer Programming II
		Description: this program will take in a number and finds the output using recursion
*/
#include "pch.h"
#include <iostream>

using namespace std;

int fact(int number);

int main()
{
	int number = 0;

	do {
		cout << "Enter a non-negative integer you want the factorial of: ";
		cin >> number;

		cout << number << "! = " << fact(number) << endl << endl;

	} while (number != 0);
}

int fact(int number)
{
	if (number == 0)
		return 1;
	else
		return number * fact(number - 1);
}

/*
Enter a non-negative integer you want the factorial of: 1
1! = 1

Enter a non-negative integer you want the factorial of: 2
2! = 2

Enter a non-negative integer you want the factorial of: 3
3! = 6

Enter a non-negative integer you want the factorial of: 4
4! = 24

Enter a non-negative integer you want the factorial of: 5
5! = 120

Enter a non-negative integer you want the factorial of: 6
6! = 720

Enter a non-negative integer you want the factorial of: 7
7! = 5040

Enter a non-negative integer you want the factorial of: 8
8! = 40320

Enter a non-negative integer you want the factorial of: 9
9! = 362880

Enter a non-negative integer you want the factorial of: 0
0! = 1
*/
