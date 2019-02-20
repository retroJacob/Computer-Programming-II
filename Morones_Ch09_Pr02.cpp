/*
		Author: Jacob Morones
		Class: Computer Programming II
		Description: This project will take food names and prices from an input file then it will output the menu and a way for you to choose what you want and will then show your total
*/
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
const double TAX = .05; // 5%
struct menuItemType
{
	string menuItem;
	double menuPrice;
};

void getData(ifstream& inFile, menuItemType menuList[]);
void showMenu(menuItemType menuList[], int foodItemQuantity[]);
void printCheck(menuItemType menuList[], int foodItemQuantity[], double TAX);

int main()
{
	ifstream inFile;
	inFile.open("Ch09Pr02DataIn.txt");
	menuItemType menuList[8];
	int foodItemQuantity[8] = { 0 };
	cout << fixed << showpoint << setprecision(2);

	getData(inFile, menuList);
	showMenu(menuList, foodItemQuantity);
	printCheck(menuList, foodItemQuantity, TAX);
}
void getData(ifstream& inFile, menuItemType menuList[])
{
	char ch = ' ';
	for (int x = 0; x < 8; x++)
	{
		getline(inFile, menuList[x].menuItem);
		inFile >> menuList[x].menuPrice;
		inFile.get(ch);

	}
}
void showMenu(menuItemType menuList[], int foodItemQuantity[])
{

	int quantity = 1;
	char foodItem = ' ';
	char letterVariables = 'A';
	for (int x = 0; x < 8; x++)
	{
		cout << "(" << letterVariables << ")" << setw(13) << left << menuList[x].menuItem << " $";
		letterVariables += 1;
		cout << setw(4) << right << menuList[x].menuPrice << endl;

	}
	letterVariables = 'A';
 
	cout << endl << "Type in the quantity of the item then the corresponding letter for the item. Type in 0 when you are done. " << endl;

	while (quantity != 0) {
		 
			
		cin >> quantity;
 

		if (quantity != 0 && quantity != '*')
			cin >> foodItem;


		switch (foodItem) {
		case 'A': //Plain Egg
			foodItemQuantity[0] = foodItemQuantity[0] + quantity;
			break;
		case 'B': // Bacon and Egg
			foodItemQuantity[1] = foodItemQuantity[1] + quantity;
			break;
		case 'C': //Muffin
			foodItemQuantity[2] = foodItemQuantity[2] + quantity;
			break;
		case 'D': //French Toast
			foodItemQuantity[3] = foodItemQuantity[3] + quantity;
			break;
		case 'E': //Fruit Basket
			foodItemQuantity[4] = foodItemQuantity[4] + quantity;
			break;
		case 'F': //Cereal
			foodItemQuantity[5] = foodItemQuantity[5] + quantity;
			break;
		case 'G': //Coffee
			foodItemQuantity[6] = foodItemQuantity[6] + quantity;
			break;
		case 'H': //Tea
			foodItemQuantity[7] = foodItemQuantity[7] + quantity;
			break;
		}

	}


}


void printCheck(menuItemType menuList[], int foodItemQuantity[], double TAX)
{
	double totalPrice = 0;

	cout << endl << "Welcome to Jacobs's Resturaunt" << endl;
	for (int x = 0; x < 8; x++)
	{
		if (foodItemQuantity[x] != 0) {
			totalPrice = totalPrice + (foodItemQuantity[x] * menuList[x].menuPrice);

			cout << foodItemQuantity[x] << " "<< setw(16) << left <<  menuList[x].menuItem << " ";
			cout << setw(7) << right << "$" << (foodItemQuantity[x] * menuList[x].menuPrice) << endl;
		}
	}
	cout << "  Tax" << "(" << TAX << "%)             $" << totalPrice * TAX << endl;
	totalPrice = totalPrice + (totalPrice * TAX);
	cout << endl << "Your total will be:   $" << totalPrice;
}
/*
Welcome to Jacobs's Resturaunt
1 Bacon and Egg          $2.45
2 Muffin                 $1.98
1 Coffee                 $0.50
  Tax(0.05%)             $0.25

Your total will be:   $5.18
*/