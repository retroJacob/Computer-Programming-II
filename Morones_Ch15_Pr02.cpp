/*
		Author: Jacob Morones
		Class: Computer Programming II
		Description: this program will take in a number and generate a pattern of stars using recursion
*/
#include "pch.h"
#include <iostream>

using namespace std;

void starPattern(int num, bool& firstTime, int idx);

int main()
{
	int num = 0;
	bool firstTime;
	int idx = 0; 
	do {
		firstTime = true; // makes first time true again if you are running it multiple times
		cout << "Enter the non-negative integer: ";
		cin >> num;
		cout << endl;

		starPattern(num, firstTime, idx);
		firstTime = false;
		starPattern(num, firstTime, idx);
		cout << endl;
 	} while (num > 0);


}
void starPattern(int num, bool& firstTime, int idx)
{
	
	if (firstTime == true) 
	{
		if (num > 0) 
		{
			for (int x = num; x > 0; x--)
				cout << "*";

			cout << endl;
			num--;
			starPattern(num, firstTime, idx);

		}

	}
	else if (idx != num)
		
	{
		for (int x = idx; 0 <= x; x--)
		{
			cout << "*";
			if (x == num)
				break;
		}

		cout << endl;
		idx++;
		starPattern(num, firstTime, idx);

	}
	
}
/*
Enter the non-negative integer: 1

*
*

Enter the non-negative integer: 2

**
*
*
**

Enter the non-negative integer: 3

***
**
*
*
**
***

Enter the non-negative integer: 4

****
***
**
*
*
**
***
****

Enter the non-negative integer: 5

*****
****
***
**
*
*
**
***
****
*****

Enter the non-negative integer: 6

******
*****
****
***
**
*
*
**
***
****
*****
******

Enter the non-negative integer: 7

*******
******
*****
****
***
**
*
*
**
***
****
*****
******
*******

Enter the non-negative integer: 8

********
*******
******
*****
****
***
**
*
*
**
***
****
*****
******
*******
********

Enter the non-negative integer: 9

*********
********
*******
******
*****
****
***
**
*
*
**
***
****
*****
******
*******
********
*********

Enter the non-negative integer: 0
*/
