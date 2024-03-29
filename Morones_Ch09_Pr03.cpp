/*
		Name: Jacob Morones
		Class: Computer Programming II
		Description: This program reads a text and outputs the letters with their counts
*/

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct letterType
{
	char letter;
	int count;
};

void openFile(ifstream& inFile, ofstream& outFile);
void count(letterType letterArray[], ifstream& inFile, int& numOfChars);
void printResult(ofstream& outFile, letterType letterArray[], int& numOfChars);

int main()
{

	ifstream inFile;
	ofstream outFile;
	letterType letterArray[52] = { 0 };
	int numOfChars = 0;


	openFile(inFile, outFile);
	count(letterArray, inFile, numOfChars);
	printResult(outFile, letterArray, numOfChars);

}
void openFile(ifstream& inFile, ofstream& outFile)
{
	string fileName;
	

	cout << "Enter the input file name: ";
	cin >> fileName;

	inFile.open(fileName);
	if (inFile)
	{
		cout << "Enter the output file name: ";
		cin >> fileName;
		outFile.open(fileName);
	}
	else 
		cout << "File could not be opened";
}
void count(letterType letterArray[], ifstream& inFile, int& numOfChars)
{
	char ch; //file identifier


	for (int x = 0; 52 > x; x++)
	{
		if (26 > x)
		{
			letterArray[x].letter = 65 + x;
		}
		else
		{
			letterArray[x].letter = 71 + x;
		}


	}


	while (!inFile.eof())
	{
		inFile >> ch;

		if (ch > 0)
			numOfChars++;

		for (char x = 0; 52 > x; x++)
		{
			if (letterArray[x].letter == ch)
				letterArray[x].count++;


		}


	}


}
void printResult(ofstream& outFile, letterType letterArray[], int& numOfChars)
{
	outFile << fixed << showpoint << setprecision(2);

	outFile << "Letter  Count   Pecentage of Occurance" << endl;
	for (char x = 0; 52 > x; x++)
	{
		outFile << right << setw(4) << letterArray[x].letter << right << setw(7) << letterArray[x].count << right << setw(19) << static_cast<double>(letterArray[x].count) / numOfChars * 100 << "%" << endl;


	}

}