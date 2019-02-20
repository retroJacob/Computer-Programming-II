/*
			Author: Jacob Morones
			Class: Computer Programming II
			Description: This program will take test scores and names from a file, then output the names and their average score and grade.
*/
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void getData(string names[], double testScores[][6]);
void calcAverage(double testScores[][6]);
void calcGrade(char letterGrade[], double testScores[][6]);
void printData(string names[], double testScores[][6], char letterGrade[]);

int main()
{

	string names[10];
	double testScores[10][6];
	char letterGrade[10];


	getData(names, testScores);
	calcAverage(testScores);
	calcGrade(letterGrade, testScores);
	printData(names, testScores, letterGrade);
}
void getData(string names[], double testScores[][6])
{
	ifstream inFile;
	inFile.open("Ch08Pr01DataIn.txt");
	int y = 0;
	int idx = 0;

	for (int x = 0; x <= 10; x++)
	{

		inFile >> names[x];

		while (5 > y)
		{
			inFile >> testScores[idx][y];

			y++;
		}
		y = 0;
		idx++;
	}



}
void calcAverage(double testScores[][6])
{
	int student = 0;
	int grades = 0;


	while (student != 10)
	{


		testScores[student][5] = (testScores[student][0] + testScores[student][1] + testScores[student][2] + testScores[student][3] + testScores[student][4]) / 5;


		student++;
	}




}
void calcGrade(char letterGrade[], double testScores[][6])
{
	int student = 0;
	int score;
	while (student != 10)
	{
		score = testScores[student][5] / 10;

		switch (score)
		{
		case 9:
			letterGrade[student] = 'A';
			break;
		case 8:
			letterGrade[student] = 'B';
			break;
		case 7:
			letterGrade[student] = 'C';
			break;
		case 6:
			letterGrade[student] = 'D';
			break;
		default:
			letterGrade[student] = 'F';
			break;

		}

		student++;
	}

}
void printData(string names[], double testScores[][6], char letterGrade[])
{
	ofstream outFile;
	outFile.open("Morones_Ch08Pr01DataOut.txt");
	int s = 0;
	int x = 0;
	outFile << "Student	 Score1 Score2 Score3 Score4 Score5 Average Grade" << endl;
	outFile << "----------------------------------------------------------" << endl;
	outFile << fixed << showpoint << setprecision(2);
	

	while (s <= 10)
	{
		outFile << names[s] << "	 ";  

			for( x = 0; 5 != x; x++)
			{
				outFile << testScores[s][x]<< "  ";
				
			}
		outFile << " " << testScores[s][5] << "    " << letterGrade[s] << endl;
		s++;
	}

}
