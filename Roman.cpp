/*
			 Author: Jacob Morones
			 Class: Computer Programming II
			 Description: This program will ask you for a roman number and then it will print out the corresponding roman numeral
*/
#include "pch.h"
#include <iostream>
#include <string>
#include "Roman.h"

using namespace std;

class romanType
{
public:
	void inputRoman();
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
int main()
{
	
	romanType number;

	number.inputRoman();

	return 0;
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
