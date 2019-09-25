/*
		Author: Jacob Morones
		Class: Computer Programming II
		Description: This program will take in starting city, ending city, vehicle type, type of road, and gasoline cost per gallon to find the distance, time it will take to get there, and the cost of gas
*/

#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

int calcDistance(int cityDistances[], char startingCity, char endingCity);
void printTime(double distance, int roadMiles[], char roadType);
void printGasCost(char vehicleType, int milesPerGal[], double distance, double gasolineCost);

int main()
{
	int cityDistances[7] = { 0, 225, 170, 220, 120, 280, 60 };
 	int milesPerGal[4] = { 35, 29, 24, 21 };
	int roadMiles[4] = { 65, 60, 55, 45 }; 
	double gasolineCost, distance;
	char startingCity = 0;
	char endingCity = 0;
	char vehicleType, roadType;

 	while (startingCity != '0')
	{
		cout << "Starting City, or 0 to end program: ";
		cin >> startingCity;

		if (startingCity == '0')
			break;

		cout << "Ending City: ";
		cin >> endingCity;

		cout << "Vehicle Type: ";
		cin >> vehicleType;

		cout << "Road Type: ";
		cin >> roadType;

	
		cout << "Gasoline Cost per Gallon: ";
		cin >> gasolineCost;
		
		distance = calcDistance(cityDistances, startingCity, endingCity);

		cout << endl << "Total miles traveled: " << distance << endl;
		printTime(distance, roadMiles, roadType);
		printGasCost(vehicleType, milesPerGal, distance, gasolineCost);
		cout << endl << endl;
	}


}
int calcDistance(int cityDistances[], char startingCity, char endingCity)
{
	int distance = 0; 
 	
	while (startingCity != endingCity)
	{
		distance = distance + cityDistances[startingCity - 64];
		startingCity++;
	}
	
	return distance;
}
void printTime(double distance, int roadMiles[], char roadType)
{

	int road = 0;
	double time = 0;
	int hours = 0;
	double minutes; 
	switch (roadType)
	{
		case'I':
			road = 0;
 			break;
		case'H':
			road = 1;
 			break;
		case'M':
			road = 2;
 			break;
		case'S':
			road = 3;
 			break;
	}
	time = distance / roadMiles[road];
	hours = time;
	minutes = (time - static_cast<int>(time)) * 60;
	
	cout << "Time: ";
	
	if (hours < 10)
		cout << "0";

	cout << hours << ":";

	
	if (minutes < 10)
		cout << "0";

	cout << setprecision(0) << minutes << endl;
}
void printGasCost(char vehicleType, int milesPerGal[], double distance, double gasolineCost)
{
	cout << "Total cost for gas: $" << fixed << setprecision(2);
	switch (vehicleType)
	{
	case'C':
		cout << distance / milesPerGal[0] * gasolineCost;
		break;
	case'M':
		cout << distance / milesPerGal[1] * gasolineCost;
		break;
	case'F':
		cout << distance / milesPerGal[2] * gasolineCost;
		break;
	case'V':
		cout << distance / milesPerGal[3] * gasolineCost;
		break;
	}
}
/*
Starting City, or 0 to end program: A
Ending City: C
Vehicle Type: M
Road Type: H
Gasoline Cost per Gallon: 3.79

Total miles traveled: 395
Time: 06:35
Total cost for gas: $51.62

Starting City, or 0 to end program: E
Ending City: F
Vehicle Type: C
Road Type: S
Gasoline Cost per Gallon: 3.69

Total miles traveled: 280.00
Time: 06:13
Total cost for gas: $29.52

Starting City, or 0 to end program: B
Ending City: E
Vehicle Type: F
Road Type: M
Gasoline Cost per Gallon: 3.59

Total miles traveled: 510.00
Time: 09:16
Total cost for gas: $76.29

Starting City, or 0 to end program: F
Ending City: G
Vehicle Type: V
Road Type: H
Gasoline Cost per Gallon: 3.89

Total miles traveled: 60.00
Time: 01:00
Total cost for gas: $11.11

Starting City, or 0 to end program: A
Ending City: G
Vehicle Type: C
Road Type: I
Gasoline Cost per Gallon: 3.63

Total miles traveled: 1075.00
Time: 16:32
Total cost for gas: $111.49

Starting City, or 0 to end program: 0
*/
