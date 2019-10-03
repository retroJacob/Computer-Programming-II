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

//TicTacToeImp.cpp // Tic-Tac-Toe Implementation file

void ticTacToe::play()
{
	// declare a bool variable to control when the game is over.
	bool done = false;
	// declare a char variable to keep track of whose turn it is; initialize to 'X'.
	char player = 'X';

	// STUDENT write code to call the appropriate function to display the board.
	displayBoard();


	while (!done)
	{
		done = getXOMove(player);

		if (player == 'X')
			player = 'O';
		else
			player = 'X';
	}
}

void ticTacToe::displayBoard() const
{
	// Display the column number headings.
	cout << "   1    2    3" << endl << endl;


	// STUDENT write a for-loop to display the rows of the board
	for (int row = 0; 3 > row; row++)
	{

		cout << row + 1;

		// STUDENT write a for-loop to display the columns of the board
		for (int col = 0; col < 3; col++)
		{
			cout << setw(3) << board[col][row];

			if (col != 2)
				cout << " |";
		}

		cout << endl;

		if (row != 2)
			cout << " ____|____|____" << endl
			<< "     |    |    " << endl;
	}

	cout << endl;
}
  
bool ticTacToe::isValidMove(int row, int col) const
{
	// STUDENT write code to verify row and column are valid numbers and the space is not already taken.
	if (3 >= row && row >=1 && 3>= col && col >= 1 && board[row - 1][col - 1] != 'X' && board[row - 1][col - 1] != 'O')
		return true;
	else 
		return false;
	
	 
	// return TRUE if a valid move.
	// return FALSE if not a valid move

}
 
bool ticTacToe::getXOMove(char playerSymbol)
{
	// Declare int variables to store player's row and column choice.
	int row, col;


	// STUDENT write a do-loop to;
	//  - ask the playerSymbol player to enter a move,
	//  - and keep asking if it is not a valid move
	do
	{
		cout << "Enter a move: ";
		cin >> row;
		cin >> col;

		while (isValidMove(row, col) == false) 
		{
			cout << endl << "Your move was incorrect, please try again: ";
			cin >> row;
			cin >> col;
			
		}
		
	} while (isValidMove(row,col) == false);

	//  The player is entering row/col numbers from 1 to 3, but array indexes are 0 to 2.
	row--;
	col--;

	//  Increment the number of moves.
	noOfMoves++;

	//  STUDENT write code to put the playerSymbol players choice on the board.
	board[row][col] = playerSymbol;

	//  Display the updated board.
	displayBoard();

	//  Check the status of the game.
	status gStatus = gameStatus();


	//  STUDENT write an IF-ELSE-statement to;
	//  - Announce the winner, and return true.
	//  - Announce a draw, and return true.
	//  - If no winner and no draw, return false.
	if (gameStatus() == WIN)
	{
		if (noOfMoves % 2 == 0)
			cout << "Player O wins! ";
		else
			cout << "Player X wins! ";
		return true;

	}
	else if (gameStatus() == DRAW)
	{
		cout << "The game ends in a draw. ";
		return true;
	}
	else
		return false;
}

status ticTacToe::gameStatus()
{
	//Check rows for a win
	for (int row = 0; row < 3; row++) 
	{
		// STUDENT write an IF-statement to check for a win on the row
		if ((board[row][0] == 'X' && board[row][1] == 'X' && board[row][2] == 'X') || (board[row][0] == 'O' && board[row][1] == 'O' && board[row][2] == 'O'))

			return WIN;
	}
	//Check columns for a win
	for (int col = 0; col < 3; col++)
		// STUDENT write an IF-statement to check for a win on the column
		if ((board[0][col] == 'X' && board[1][col] == 'X' && board[2][col] == 'X') || (board[0][col] == 'O' && board[1][col] == 'O' && board[2][col] == 'O'))

	

	//Check diagonals for a win
		return WIN;
// IF-statement to check for a win on first diagonal
	if((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'))
		return WIN;

	// IF-statement to check for a win on first diagonal
	if((board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
		return WIN;

	if (noOfMoves < 9)
		return CONTINUE;

	return DRAW;
}

void ticTacToe::reStart()
{
	//  nested for-loop to reinitialize the board to spaces.
	for (int row = 0; 3 > row; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			board[row][col] = ' ';

		}



	}



	noOfMoves = 0;
}

ticTacToe::ticTacToe()
{
	//   nested for-loop to initialize the board to spaces.
	for (int row = 0; 3 > row; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			board[row][col] = ' ';

		}



	}


	noOfMoves = 0;
}
