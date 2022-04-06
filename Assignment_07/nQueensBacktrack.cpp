#include "nQueensBacktrack.h"
#include <stack>
// prototype
bool isSafe(int row, int col, int queenRow, int queenCol, char** board);

void nQueensBacktrack::nQueensBacktrackMain()
{
	int row, col, numberOfQueens;
	stack <char> pastMoves;

	int dim = inputInteger("\n\n\tEnter the dimensions of the board (n x n) from 1 to 100: ", 1, 100);
	row = dim;
	col = dim;

	// creating the dynamic 2d array
	char** board = new char* [row]; // double astrisk cause its a pointer to a pointer
	for (int i = 0; i < row; i++)
	{
		board[i] = new char[col];
	}
	// making the board into empty spaces
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}

	cout << "\n\t\tEnter the column(1..." << col << ") to place the first queen: ";
	int x = inputInteger("", 1, col);
	x--;
	board[0][x] = 'Q';
	
	for (int i = 1; i < col; i++)
	{

	}

	// printing board
	cout << "\n\tSolution: ";
	cout << "\n\t";
	for (int j = 0; j < col; j++)
	{
		cout << "--";
	}
	cout << "-" << '\n';
	for (int i = 0; i < row; i++)
	{
		cout << "\t";
		for (int j = 0; j < col; j++)
		{
			cout << "|" << board[i][j];
		}
		cout << "|" << '\n' << "\t";
		for (int j = 0; j < col; j++)
		{
			cout << "--";
		}
		cout << "-" << '\n';
	}

	int queenRow = 1;
	int queenCol = 0;

	if (isSafe(row, col, queenRow, queenCol, board))
	{
		cout << "\n\t\tIt's safe and working.";
	}
	else
	{
		cout << "\n\t\tIt's not safe and working.";
	}
	system("pause");
}

bool isSafe(int row, int col, int queenRow, int queenCol, char** board)
{
	int i, j;

	// checking if it's safe to place a queen
	// checking vertically
	for (i = 0; i < col; i++)
	{
		if (board[i][queenCol] == 'Q')
		{
			return false;
		}
	}

	// checking horizontally
	for (j = 0; j < row; j++)
	{
		if (board[queenRow][j] == 'Q')
		{
			return false;
		}
	}
	// checking diagonally (top left)
	bool temp = true;
	i = queenRow;
	j = queenCol;
	do
	{
		if ((i < 0) || (j < 0))
			temp = false;
		else if (board[i][j] == 'Q')
		{
			return false;
		}
		else
			i--, j--;
	} while (temp);
	// checking diagonally (bottom right)
	temp = true;
	i = queenRow;
	j = queenCol;
	do
	{
		if ((i > (row - 1)) || (j > (col - 1)))
			temp = false;
		else if (board[i][j] == 'Q')
		{
			return false;
		}
		else
			i++, j++;
	} while (temp);
	// checking diagonally (top right)
	temp = true;
	i = queenRow;
	j = queenCol;
	do
	{
		if ((i < 0) || (j > (col - 1)))
			temp = false;
		else if (board[i][j] == 'Q')
		{
			return false;
		}
		i--, j++;
	} while (temp);
	// checking diagonally (bottom left)
	temp = true;
	i = queenRow;
	j = queenCol;
	do
	{
		if ((i > (row - 1)) || (j < 0))
			temp = false;
		else if (board[i][j] == 'Q')
		{
			return false;
		}
		i++, j--;
	} while (temp);

	return true;
}