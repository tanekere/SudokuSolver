#include <SFML/Graphics.hpp>

bool valid(int board[][9],int num,int x,int y);
bool getEmpty(int board[][9],int &i,int &j);

bool getEmpty(int board[][9],int &i,int &j)
{
	for ( i = 0; i < 9; i++)
	{
		for ( j = 0; j < 9; j++)
		{
			if(board[i][j]==0)
			{
				return true;
			}
		}
	}
	return false;
}

bool valid(int board[][9],int num,int x,int y)
{
	for (int i = 0; i < 9; i++)
		if (board[x][i]==num)
			return false;

	for (int i=0 ; i < 9 ; i++)
		if (board[i][y] == num)
			return false;

	int box_x = x-(x%3);
	int box_y = y-(y%3);

	for(int i=0; i<3 ; i++)
		for(int j=0 ; j<3 ; j++)
			if(board[i+box_x][j+box_y] == num)
				return false;
	if(!board[x][y]==0)
		return false;

	return true;
}

// A Backtracking program in C++ to solve Sudoku problem
#include <bits/stdc++.h>
using namespace std;

// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

// This function finds an entry in grid
// that is still unassigned
bool FindUnassignedLocation(int grid[N][N],
                            int &row, int &col);

// Checks whether it will be legal
// to assign num to the given row, col
bool isSafe(int grid[N][N], int row,
                   int col, int num);

/* Takes a partially filled-in grid and attempts
to assign values to all unassigned locations in
such a way to meet the requirements for
Sudoku solution (non-duplication across rows,
columns, and boxes) */
bool SolveSudoku(int grid[N][N])
{
    int row, col;

    // If there is no unassigned location,
    // we are done
    if (!FindUnassignedLocation(grid, row, col))
    return true; // success!

    // consider digits 1 to 9
    for (int num = 1; num <= 9; num++)
    {
        // if looks promising
        if (isSafe(grid, row, col, num))
        {
            // make tentative assignment
            grid[row][col] = num;
			sf::sleep(sf::seconds(0.2));

            // return, if success, yay!
            if (SolveSudoku(grid))
                return true;

            // failure, unmake & try again
            grid[row][col] = UNASSIGNED;
        }
    }
    return false; // this triggers backtracking
}

/* Searches the grid to find an entry that is
still unassigned. If found, the reference
parameters row, col will be set the location
that is unassigned, and true is returned.
If no unassigned entries remain, false is returned. */
bool FindUnassignedLocation(int grid[N][N],
                            int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

/* Returns a boolean which indicates whether
an assigned entry in the specified row matches
the given number. */
bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

/* Returns a boolean which indicates whether
an assigned entry in the specified column
matches the given number. */
bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

/* Returns a boolean which indicates whether
an assigned entry within the specified 3x3 box
matches the given number. */
bool UsedInBox(int grid[N][N], int boxStartRow,
               int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow]
                    [col + boxStartCol] == num)
                return true;
    return false;
}

/* Returns a boolean which indicates whether
it will be legal to assign num to the given
row, col location. */
bool isSafe(int grid[N][N], int row,
                   int col, int num)
{
    /* Check if 'num' is not already placed in
    current row, current column and current 3x3 box */
    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row % 3 ,
                      col - col % 3, num) &&
            grid[row][col] == UNASSIGNED;
}