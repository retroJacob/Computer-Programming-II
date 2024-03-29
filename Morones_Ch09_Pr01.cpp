/*
			Author: Jacob Morones
			Class: Computer Programming II
			Description: will reads students’ names followed by their test scores. Then it will output each student’s name followed by the test scores and the relevant grade. It will also find and print the highest test score and the name of the students having the highest test score.
*/

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;



struct studentType
{
	string studentFName;
	string studentLName;
	int testScore;
	char grade;

};

void readData(studentType students[], ifstream& inFile);
void assignScore(studentType students[]);
void findHighest(int& highestScore, studentType students[]);
void printNames(int highestScore, studentType students[], ofstream& outFile);

int main()
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("Ch09Pr01DataIn.txt");
	outFile.open("Ch09Pr01DataOut.txt");

	studentType students[20];
	int highestScore;

	readData(students, inFile);
	assignScore(students);
	findHighest(highestScore, students);
	printNames(highestScore, students, outFile);
	
}
void readData(studentType students[], ifstream& inFile)
{
	

	for (int j = 0; 20 > j; j++)
	{
		inFile >> students[j].studentFName;
		inFile >> students[j].studentLName;
		inFile >> students[j].testScore;
	}

}
void assignScore(studentType students[])
{
	for (int j = 0; 20 > j; j++)
	{
		if (students[j].testScore >= 90)
			students[j].grade = 'A';
		if (students[j].testScore >= 80 && students[j].testScore < 90)
			students[j].grade = 'B';
		if (students[j].testScore >= 70 && students[j].testScore < 80)
			students[j].grade = 'C';
		if (students[j].testScore >= 60 && students[j].testScore < 70)
			students[j].grade = 'D';
		if (students[j].testScore >= 0 && students[j].testScore < 60)
			students[j].grade = 'F';

		 
	}

}
void findHighest(int& highestScore, studentType students[])
{
	for (int j = 0; 19 > j; j++)
	{
		
		if (students[j].testScore >= students[j + 1].testScore)
			highestScore = students[j].testScore;
		else
			highestScore = students[j + 1].testScore;

	}
	

}
void printNames(int highestScore, studentType students[], ofstream& outFile)
{
	outFile << "Last Name, First Name  " << setw(19) << "Score     Grade " << endl;
	outFile << "---------------------------------------------------------" << endl;
	
	for (int j = 0; j < 20; j++)
	{
		outFile << setw(10) << students[j].studentLName << ", " << 
			setw(9) << left << students[j].studentFName << right << 
			setw(9)  << students[j].testScore << setw(9) << students[j].grade << endl; 

	}
	outFile << endl << "The highest scorers with a score of " << highestScore << " were: ";
	for (int j = 0; j < 20; j++)
	{
		 

		if (students[j].testScore == highestScore)
			outFile << students[j].studentFName << " " << students[j].studentLName << ", ";

	}



}
