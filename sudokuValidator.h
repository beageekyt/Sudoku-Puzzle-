#include <bits/stdc++.h>
using namespace std;

extern vector<vector<int> > sudokuFrame;

bool validator();
bool valuesAreValid();
bool rowsAreValid();
bool columnsAreValid();
bool ThreeByThreeSquaresAreValid();
int getCellValue(int row, int col);
bool squareContains(int squareNumber, int value);
bool columnContains(int col, int value);
bool rowContains(int row, int value);

bool validator()
{
        if (valuesAreValid())
        {
                if (rowsAreValid())
                {
                        if (columnsAreValid())
                        {
                                if (ThreeByThreeSquaresAreValid())
                                {
                                        // cout << "\nYour puzzle is valid!\n\n";
                                        return true;
                                }
                                else
                                        return false;
                                // cout << "Your puzzle in invalid!\n";
                        }
                        else
                                return false;
                        // cout << "Your puzzle is invalid!\n";
                }
                else
                        return false;
                // cout << "Your puzzle is invalid!\n";
        }
        else
                // cout << "Your puzzle is invalid!\n";
                return false;
}
bool valuesAreValid()
{
        int rowIter, colIter;

        for (rowIter = 0; rowIter < 9; rowIter++)
        {
                for (colIter = 0; colIter < 9; colIter++)
                {
                        int cellValue = getCellValue(rowIter, colIter);
                        if (!(cellValue >= 0 && cellValue <= 9))
                                return false;
                }
        }
        return true;
}

bool rowsAreValid()
{

        int rowIter, colIter, valIter;

        for (rowIter = 0; rowIter < 9; rowIter++)
        { // Iterating over rows

                for (valIter = 1; valIter <= 9; valIter++)
                { // Iter over 1-9

                        if (rowContains(rowIter, valIter) == false)
                                return false;

                } // Value iteration loop ends here

        } // Row iteration loop ends here

        return true;
}

bool columnsAreValid()
{

        int rowIter, colIter, valIter;

        for (colIter = 0; colIter < 9; colIter++)
        { // Iterating over cols

                for (valIter = 1; valIter <= 9; valIter++)
                { // Iter over 1-9

                        if (columnContains(colIter, valIter) == false)
                                return false;

                } // Value iteration loops ends

        } // Col iteration loop ends here

        return true;
}
bool ThreeByThreeSquaresAreValid()
{

        int squareIter, valIter;

        for (squareIter = 0; squareIter < 9; squareIter++)
        { // Iter over squares

                for (valIter = 1; valIter <= 9; valIter++)
                { // Iter over 1-9

                        if (squareContains(squareIter, valIter) == false)
                                return false;

                } // Value iteration loop ends here

        } // Square iteration loop ends here

        return true;
}

int getCellValue(int row, int col)
{
        return sudokuFrame[row][col];
}

bool rowContains(int row, int value)
{
        int colIter;
        for (colIter = 0; colIter < 9; colIter++)
        {
                if (getCellValue(row, colIter) == value)
                        return true;
        }
        return false;
}

bool columnContains(int col, int value)
{
        int rowIter = 0;
        for (rowIter = 0; rowIter < 9; rowIter++)
        {
                if (getCellValue(rowIter, col) == value)
                        return true;
        }
        return false;
}
bool squareContains(int squareNumber, int value)
{
        int rowStart = (squareNumber / 3) * 3;
        int rowEnd = rowStart + 2;

        int colStart = (squareNumber % 3) * 3;
        int colEnd = colStart + 2;

        int rowIter, colIter;
        for (rowIter = rowStart; rowIter <= rowEnd; rowIter++)
        {
                for (colIter = colStart; colIter <= colEnd; colIter++)
                {
                        if (getCellValue(rowIter, colIter) == value)
                                return true;
                }
        }

        return false;
}