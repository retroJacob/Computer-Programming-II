/*
		Author: Jacob Morones
		Class: Computer Programming II
		Description: This program will take in a nonnegative integer and then it returns the sum of the squares of the numbers from 0 to num
*/
#include "pch.h"
#include <iostream>

using namespace std;

int sumSquares(int num);

int main()
{
	int num;

	do 
	{
		cout << "Enter the nonnegative integer: ";
		cin >> num;
		 
		cout << "The sum of the squares is: " << sumSquares(num) << endl << endl;
	}
	while (num > 0);
}
int sumSquares(int num)
{
	if (num == 1)
		return 1;
	else
		return num * num + sumSquares(num - 1);
}