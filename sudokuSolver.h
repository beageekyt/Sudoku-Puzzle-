#include <bits/stdc++.h>
using namespace std;

extern vector<vector<int> > sudokuFrame;

bool sudoku_solver();
bool isValid(int row, int col, int c);

bool isValid(int row, int col, int c)
{
        for (int i = 0; i < 9; i++)
        {
                if (sudokuFrame[i][col] == c)
                        return false;

                if (sudokuFrame[row][i] == c)
                        return false;

                if (sudokuFrame[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                        return false;
        }
        return true;
}

bool sudoku_solver()
{
        for (int i = 0; i < 9; i++)
        {
                for (int j = 0; j < 9; j++)
                {
                        if (sudokuFrame[i][j] == 0)
                        {
                                for (int c = 1; c <= 9; c++)
                                {
                                        if (isValid(i, j, c))
                                        {
                                                sudokuFrame[i][j] = c;

                                                if (sudoku_solver())
                                                        return true;
                                                else
                                                        sudokuFrame[i][j] = 0;
                                        }
                                }
                                return false;
                        }
                }
        }
        return true;
}
