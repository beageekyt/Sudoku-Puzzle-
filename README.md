# Sudoku-Puzzle-

# Introduction
These are a suite of C++ programs which deal with Sudoku Puzzles.This suite include a Sudoku solver and Sudoku validator. Sudoku solver is based on recursion and backtracking and sudoku validator is based on the basic conditioning of sudoku validation.

## Contents

* [Getting started](#Getting-started)
* [Sudoku Solver](#sudoku-solver)
    * [Getting Started (Usage)](#getting-started)
    * [How It Works](#how-it-works)
* [Sudoku Validator](#sudoku-validator)
    * [Getting Started (Usage)](#getting-started-1)
    * [How It Works](#how-it-works-1)
    

# Getting started

* Simply download the all file available in the ```Sudoku-Puzzle ``` directory.
* Once downloaded, compiled and run  ```Sudoku.cpp ``` file using any standard C++ compiler. The program will require the user to input the either you want to Sudoku solution or sudoku validation. 
* After this , the program will require the user to input the Sudoku puzzle into it. There are two ways to do this.
    * The user can either input the values manually one-by-one when the program is running.
    * The user can write all the values into a file, seperated by whitespaces. The file can have any name or extension. When the program is running, the user will be prompted to simply enter the name of the file (with extension). **Below** is an example of how the contents of such a file might look. Look at the ```sample.txt``` files in the same directory for more examples.
    
        ```
        0 0 0  0 0 0  6 8 0
        0 0 0  0 7 3  0 0 9
        3 0 9  0 0 0  0 4 5
        
        4 9 0  0 0 0  0 0 0
        8 0 3  0 5 0  9 0 2
        0 0 0  0 0 0  0 3 6
        
        9 6 0  0 0 0  3 0 8
        7 0 0  6 8 0  0 0 0
        0 2 8  0 0 0  0 0 0
        ```

* Once solved, the Sudoku puzzles shall be displayed like this.
    ```
    ++=====================================++
    || 1   7   2 || 5   4   9 || 6   8   3 ||
    ++-----------++-----------++-----------++
    || 6   4   5 || 8   7   3 || 2   1   9 ||
    ++-----------++-----------++-----------++
    || 3   8   9 || 2   6   1 || 7   4   5 ||
    ++=====================================++
    || 4   9   6 || 3   2   7 || 8   5   1 ||
    ++-----------++-----------++-----------++
    || 8   1   3 || 4   5   6 || 9   7   2 ||
    ++-----------++-----------++-----------++
    || 2   5   7 || 1   9   8 || 4   3   6 ||
    ++=====================================++
    || 9   6   4 || 7   1   5 || 3   2   8 ||
    ++-----------++-----------++-----------++
    || 7   3   1 || 6   8   2 || 5   9   4 ||
    ++-----------++-----------++-----------++
    || 5   2   8 || 9   3   4 || 1   6   7 ||
    ++=====================================++

# Sudoku-Solver
This is a program which solves 9x9 Sudoku puzzles. **Written completely in C++** and **built wholly from scratch**, this program reads input either from a user or from a file containing the Sudoku values and solves the puzzle. It employs concepts such as backtracking and recursion.

### How It Works
This particular algorithm employs the use of backtracking, one of the more common methods to solve Sudoku puzzles. I've written a simple algorithm to give an idea of how the program works.

1. Start.
2. We start with the first empty cell.
3. We put a value in that and then check is it valid or not it is valid then we move forward to next empty cell.
4. Then we perform same process on the next empty cell if we able to find the value then this means that there is something wrong with the value of the previous cell. We then move back to the previous cell and place the next value in the cell now. We repeat this step until the current cell has a valid value placed inside it.
5. We stop when we reach the 81st cell (the last cell in a Sudoku puzzle) and have placed a valid value.
6. Then we check that our sudoku solution is valid or not if solution is valid we print our sudoku otherwise our input sudoku for solution is a wrong sudoku and can't be solved.
8. Stop.

# Sudoku Validator
This is a program which validates solutions for 9x9 Sudoku puzzles. **Written completely in C++** and **built wholly from scratch**, this program takes in input from the user or from a file containing the values. It then validates the puzzle and then displays whether it is a valid solution or not.

### How It Works
The workings of the Sudoku Validator are quite simple, to be honest. Here's a simple algorithm explaining them all.

1. Start
2. The values in all the cells are checked to see if they are in the range 1-9. If not, the puzzle is invalid.
3. Every row is checked to see if it contains 1-9 atleast once. If not, the solution is invalid.
4. Every column is checked to see if it contains 1-9 atleast once. If not, the solution is invalid.
4. Every 3x3 grid is checked to see if it contains 1-9 atleast once. If not, the solution is invalid.
5. If all the criteria have been satisfied, the solution is valid.
6. Stop

