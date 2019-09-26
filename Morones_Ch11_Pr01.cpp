/*
		Author: Jacob Morones
		Class: Computer Programming II
		Description: this program will calculate and print the surface area and volume of a cylinder when given the radius of the base and the height of the cylinder.  
*/
 #include <iostream>
#include "circleType.h"
#include "cylinderType.h"

using namespace std;

int main()
{
	double radius;
	double height;
 
	cylinderType startTwo;

	
	cout << "Enter radius and height: ";
	cin >> radius >> height;
	cylinderType startOne(radius, height);
	startOne.print();
	

	cout << endl << "Enter radius and height: ";
	cin >> radius >> height;
	startTwo.setRadius(radius);
	startTwo.setHeight(height);
	startTwo.print();


	return 0;
}
/*
Enter radius and height: 4.5 6.75
radius = 4.5, height = 6.75, surface area = 318.087, volume = 429.417

Enter radius and height: 3.75 8.25
radius = 3.75, height = 8.25, surface area = 282.744, volume = 364.475

*/