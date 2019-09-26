/*
		Author: Jacob Morones
		Class: Computer Programming II
		Description: This program prompts the user to enter time in 12-hour notation, then the program then outputs the time in 24-hour notation
*/

#include "pch.h"
#include <iostream>
#include <string>
#include"invalidSec.h"
#include"invalidMin.h"
#include"invalidHr.h"

int getHours();
int getMinutes();
int getSeconds();

using namespace std;

int main()
{
	int hours, minutes, seconds = 0;
	string dayTime;

	hours = getHours();
	minutes = getMinutes();
	seconds = getSeconds();

 
	cout << "AM or PM: ";
	cin >> dayTime;

	cout << endl << "24 hour clock time: ";

	if (dayTime == "PM" && 12 > hours)
	{
		hours += 12;
	}

		if (hours == 12 && dayTime == "AM") 
			cout << "00:";
		else if (hours >= 10)
			cout << hours << ":";
		else 
			cout << 0 << hours << ":";

		if (minutes > 10)
			cout << minutes << ":";
		else
			cout << 0 << minutes << ":";

		if (seconds > 10)
			cout << seconds;
		else
			cout << 0 << seconds;
}
int getHours()
{
	int hours;
	bool finish = false;

	do
		try {
		cout << "Enter hours: ";
		cin >> hours;


		if (hours > 12 || hours < 0)
			throw invalidHr();
		else
		 finish = true;
	    }
	catch (invalidHr invalid)
	{
		cout << invalid.what() << endl << endl;
	}
	 
	while (!finish);

	cout << endl;

	return hours;
}
int getMinutes()
{
	int minutes;
	bool finish = false;

	do
		try {
		cout << "Enter minutes: ";
		cin >> minutes;


		if (minutes > 59 || minutes < 0)
			throw invalidMin();
		else
			finish = true;
	}
	catch (invalidMin invalid)
	{
		cout << invalid.what() << endl << endl;
	}

	while (!finish);

	cout << endl;

	return minutes;
}
int getSeconds()
{
	int seconds;
	bool finish = false;

	do
		try {
		cout << "Enter seconds: ";
		cin >> seconds;


		if (seconds > 59 || seconds < 0)
			throw invalidSec();
		else
			finish = true;
	}
	catch (invalidSec invalid)
	{
		cout << invalid.what() << endl << endl;
	}

	while (!finish);

	cout << endl;

	return seconds;
}
 /*
Enter hours: 900
The value of hours must be between 0 and 12

Enter hours: 10

Enter minutes: -5
The value of minutes must be between 0 and 59

Enter minutes: 6

Enter seconds: 60
The value of seconds must be between 0 and 59

Enter seconds: 59

AM or PM: AM

24 hour clock time: 10:06:59
*/