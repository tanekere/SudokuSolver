#include <SFML/Graphics.hpp>
#include "json.hpp"
#include <bits/stdc++.h>

using namespace std;
using json = nlohmann::json;



bool FindUnassignedLocation(json &grid, int &row, int &col);

bool isSafe(json &grid, int row, int col, int num);


bool SolveSudoku(json &grid)
{
	int row, col;


	if (!FindUnassignedLocation(grid, row, col))
	return true;


	for (int num = 1; num <= 9; num++)
	{

		if (isSafe(grid, row, col, num))
		{

			grid[row][col] = num;
			sf::sleep(sf::seconds(0.2));


			if (SolveSudoku(grid))
				return true;


			grid[row][col] = 0;
		}
	}
	return false;
}


bool FindUnassignedLocation(json &grid, int &row, int &col)
{
	for (row = 0; row < 9; row++)
		for (col = 0; col < 9; col++)
			if (grid[row][col] == 0)
				return true;
	return false;
}


bool UsedInRow(json &grid, int row, int num)
{
	for (int col = 0; col < 9; col++)
		if (grid[row][col] == num)
			return true;
	return false;
}


bool UsedInCol(json &grid, int col, int num)
{
	for (int row = 0; row < 9; row++)
		if (grid[row][col] == num)
			return true;
	return false;
}


bool UsedInBox(json &grid, int boxStartRow, int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row + boxStartRow]
					[col + boxStartCol] == num)
				return true;
	return false;
}


bool isSafe(json &grid, int row,
				   int col, int num)
{

	return !UsedInRow(grid, row, num) &&
		   !UsedInCol(grid, col, num) &&
		   !UsedInBox(grid, row - row % 3 ,
					  col - col % 3, num) &&
			grid[row][col] == 0;
}