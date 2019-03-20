#pragma once

#include <string>
#include <iostream>
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
