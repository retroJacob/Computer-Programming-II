/*
			Author: Jacob Morones
			Class: Computer Programming II
			Description: will find the number of ways, r, can be chosen from a set of n items
*/

#include "pch.h"
#include <iostream>

using namespace std;

int combination(int n, int r);

int main()
{
	int n, r;
	cout << "Enter n (the number of things that can be chosen), followed by r (the total amount). Type 0 to end program. r >= n" << endl;
	do {

		cout << "Integers: ";
		cin >> n;
		if (n == 0)
			break;
		cin >> r;


		cout << "Combinations: " << combination(n, r) << endl << endl;
	} while (n != 0);

}

int combination(int n, int r)
{
	if (r == 0)
		return 1;
	if (r == n)
		return 1;
	else
		return  combination(n - 1, r - 1) + combination(n - 1, r);	
}
/*
Enter n (the number of things that can be chosen), followed by r (the total amount). Type 0 to end program. r >= n
Integers: 52 5
Combinations: 2598960

Integers: 10 2
Combinations: 45

Integers: 120 4
Combinations: 8214570

Integers: 0
*/
