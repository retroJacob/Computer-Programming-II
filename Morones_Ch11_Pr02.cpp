/*
		Author: Jacob Morones
		Class: Computer Programming II 
		Description: This program asks for: radius, height, shipping cost per liter, and paint cost per square foot to output the shipping cost and cost of painting
*/

#include "pch.h"
#include <iostream>
#include <iomanip>
#include "cylinderType.h"

using namespace std;

int main()
{
	double radius, height = 0;
	double shippingCost;
	double paintCost;
	double total;

	cylinderType cylinder;

	cout << fixed << showpoint << setprecision(2);
	
	cout << "Enter the radius and height of the container: ";
	cin >> radius >> height;
	cout << endl;

	cylinder.setRadius(radius);
	cylinder.setHeight(height);

	//1 cubic foot = 28.32 liters or 1 liter = 0.353146667 cubic feet.
	cout << "Enter the shipping cost per liter: $";
	cin >> shippingCost;
	cout << endl;

	shippingCost = shippingCost * cylinder.volume() * 28.32;

	cout << "Enter the paint cost per square foot: $";
	cin >> paintCost;
	cout << endl;

	paintCost = paintCost * cylinder.area();

	cout << "The shipping cost is: $" << shippingCost << endl;

	cout << "The paint cost is: $" << paintCost << endl;

	total = shippingCost + paintCost;
	cout << "Your total is: $" << total << endl;



}
/*
Enter the radius and height of the container: 1.5 2.25

Enter the shipping cost per liter: $1.2

Enter the paint cost per square foot: $.75

Your total is: $567.00
*/

/*
Enter the radius and height of the container: .75 1.25

Enter the shipping cost per liter: $1.20

Enter the paint cost per square foot: $.75

Your total is: $82.14
*/

 