/*
			Author: Jacob Morones
			Class: Computer Programming II
			Description: This program implements a game of Tic-Tac-Toe using TicTacToe class.
*/
#include "pch.h"
#include <iostream>
#include "TicTacToe.h"

using namespace std;

//TicTacToe.h / Tic-Tac-Toe Header file  
 
enum status { WIN, DRAW, CONTINUE };

class ticTacToe
{
public:
	void play();
	//Function to start the play.

	void displayBoard() const;
	//Function to print the board.

	bool isValidMove(int x, int y) const;
	//Function to determine if a move is valid.

	bool getXOMove(char moveSymbol);
	//Function to get a move for a player

	status gameStatus();
	//Function to determine the current status of the game.

	void reStart();
	//Function to restart the game.

	ticTacToe();
	//Default constructor.
	//Postcondition: Initializes the board to an empty state.

private:
	char board[3][3];
	int noOfMoves;
};

int main()
{
	ticTacToe game;

	game.play();

	return 0;
}
