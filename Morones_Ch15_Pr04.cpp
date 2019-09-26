/*
			Author: Jacob Morones
			Class: Computer Programming II
			Description: This programm will take in a string and will tell if you it is a palindrome or not
*/

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

bool isPalidrome(string& input);

int main()
{
	string input;

	cout << "Type in the string to check whether or not it is a palindrome, type  \"quit\" to end program" << endl << endl;
	
	do
	{
		cout << "String: ";
		getline(cin, input);
		cout << input;
		if (isPalidrome(input) == 0) 
		{
			cout << " is not a palindrome" << endl << endl;
		}
		else 
			cout << " is a palindrome." << endl << endl;

	} while (input.compare("quit") != 0);

}
bool isPalidrome(string& input)
{
	for (int x = input.size(); x >= 0; x--) //Removes spaces, non-alphabetical characters, and makes all characters lowercase to make the isPaldrome function work properly
	{
		if (input[x] > 122 || input[x] < 65 || (97 > input[x] && input[x] > 89))//removes whitespace and other non-alphabetical characters
			if (input[x] > 57 || input[x] < 48) // to make sure program wont remove the numbers
					input.erase(x, 1);
		if (input[x] < 91 && input[x] > 64) //adds 32 to the capital letters to make them lower case
			input[x] += 32; 
	}
 	
	if (input.size() != 0) 
	{
		if (input[input.size() - 1] == input[0] && input.size() != 2)
		{
			input.erase(input.size() - 1, 1); // Removes the first and last letter, then will compare the next
			input.erase(0, 1);
			if (input.size() == 1) // returns true when the last character is 1 letter
				return true;
			isPalidrome(input);				
		}
		else
			return false;
	}

}
/*
Type in the string to check whether or not it is a palindrome, type  "quit" to end program

String: Madam
Madam is a palindrome.

String: Madam, I'm Adam
Madam, I'm Adam is a palindrome.

String: A Toyota
A Toyota is a palindrome.

String: Olathe South Falcons
Olathe South Falcons is not a palindrome

String: A man, A plan, A canal, Panama!
A man, A plan, A canal, Panama! is a palindrome.

String: Go hang a salami, I'm a lasagna hog.
Go hang a salami, I'm a lasagna hog. is not a palindrome

String: 123454321
123454321 is a palindrome.

String: Quit
Quit is not a palindrome
*/
 