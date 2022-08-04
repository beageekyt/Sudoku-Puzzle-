#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "sudokuSolver.h"
#include "sudokuValidator.h"
using namespace std;
vector<vector<int> > sudokuFrame;
vector<int> sudokuRow;

void menu();
void read_sudoku();
void read_sudoku_file();
void displaySudoku();

void menu()
{
        int i;
        cout << "\n\n\n===========================================================\n";
        cout << "         Welcome to Sudoku Solver and Validator\n";
        cout << "===========================================================\n\n\n";
        cout << "\nPress 1 to validate your sudoku solution :\n";
        cout << "\nPress 2 to solve your sudoku: \n";
        cout << "\n--------> ";
        cin >> i;

        cout << "\nWelcome!!! \n\n";
        cout << "Before we start, you will have to input the puzzle into this program.\n\n";
        cout << "You can either:-\n";
        cout << "\tPress 1 to Input the puzzle by entering the values manually. \n\n";
        cout << "\tPress 2 to Input the puzzle by reading a file with values in it. \n\n";
        cout << "\tFile Specification-\n\n";
        cout << "\tThe file must not have a name > 20 characters.\n";
        cout << "\t          The file must be in the same directory as this C++ file.\n";
        cout << "\t          The file must have all 81 values seperated with spaces.\n";
        cout << "\t          Blank cells must be filled in as 0 (eg; 1 0 0 2 0 0 ...).\n";
        cout << "\t          ------> ";

        int option;
        cin >> option;

        if (option == 1)
                read_sudoku();
        else if (option == 2)
        {
                read_sudoku_file();
        }

        else
        {
                while (true)
                {
                        cout << "\nYou seem to have entered an invalid option. Try again.\n";
                        cout << "\t   --> ";
                        cin >> option;

                        if (option == 1)
                                read_sudoku();
                        else if (option == 2)
                                read_sudoku_file();
                        else
                                continue;

                        break;
                }
        }

        if (i == 2)
        {
                sudoku_solver();
                if (validator())
                        displaySudoku();
                else
                {
                        cout << "Your sudoku does't have any solution because entered sudoku is not valid.";
                }
        }
        else
        {
                bool valid = validator();
                if (valid == true)
                        cout << "\nvalid sudoku\n";
                else
                        cout << "\njab solve karna ni aata to karaa kyu\n ";
        }
}

void read_sudoku()
{
        cout << "\nEnter the specified value when prompted.\n";
        cout << "Enter 0 if cell is empty.\n\n";

        int rowIter, colIter;

        for (rowIter = 0; rowIter < 9; rowIter++)
        { // Iterating over cells to read vals.
                for (colIter = 0; colIter < 9; colIter++)
                {
                        int enteredValue;

                        cout << "Enter value for cell[" << rowIter + 1 << "][" << colIter + 1 << "] --> ";
                        cin >> enteredValue;

                        if (!(enteredValue >= 0 && enteredValue <= 9))
                        { // Checking for bounds in input.
                                while (true)
                                { // We loop until valid input is read from user.
                                        cout << "Oops! You seem to have entered a wrong value! Try again.\n";
                                        cout << "Enter value for cell [" << rowIter + 1 << "][" << colIter + 1 << "] --> ";
                                        cin >> enteredValue;

                                        if (enteredValue >= 0 && enteredValue <= 9)
                                                break;
                                }
                        }

                        sudokuRow.push_back(enteredValue);

                     
                }
                sudokuFrame.push_back(sudokuRow);
                sudokuRow.clear();
                cout << "-------\n"; 
        }
}
void read_sudoku_file()
{
        char filename[30]; // Getting filename.
        cout << "\nEnter the name of the file that contains the Sudoku Puzzle.\n";
        cout << "\t  -------> ";
        cin >> filename;

        ifstream sudokuFile; // Opening file for reading.
        sudokuFile.open(filename, ios::in);

        int rowIter, colIter;

        for (rowIter = 0; rowIter < 9; rowIter++)
        { // Iterating over file values.
                for (colIter = 0; colIter < 9; colIter++)
                {
                        int readValue;

                        sudokuFile >> readValue;

                        if (!(readValue >= 0 && readValue <= 9))
                        { // Checking bounds for input.
                                cout << "\nValue " << ((rowIter * 9) + colIter + 1) << " in " << filename;
                                cout << " seems to be wrong! Correct the value and try again!\n";
                                exit(EXIT_FAILURE);
                        }
                        sudokuRow.push_back(readValue);
                }
                sudokuFrame.push_back(sudokuRow);
                sudokuRow.clear();
        }
        sudokuFile.close();
}

void displaySudoku()
{

        cout << "\033[35m++=====================================++";
        int rowIter, colIter;

        for (rowIter = 0; rowIter < 9; rowIter++)

        {
                int cellIter = 1;

                cout << "\n\033[35m||";
                for (colIter = 0; colIter < 9; colIter++)
                {
                        if (cellIter == 3)
                        {
                                cout << "\033[0m " << sudokuFrame[rowIter][colIter] << " ";
                                cout << "\033[35m||";
                                cellIter = 1;
                        }
                        else
                        {
                                cout << "\033[0m " << sudokuFrame[rowIter][colIter] << "  ";
                                cellIter++;
                        }
                }

                if (rowIter % 3 != 2)
                        cout << "\n\033[35m++"
                             << "\033[36m-----------"
                             << "\033[35m++"
                             << "\033[36m-----------"
                             << "\033[35m++"
                             << "\033[36m-----------"
                             << "\033[35m++";

                else
                        cout << "\n\033[35m++=====================================++";

                        
        }
}

int main()
{

        menu();
        return 0;
}