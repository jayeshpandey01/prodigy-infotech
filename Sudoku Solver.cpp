#include <iostream>
using namespace std;

// Size of the Sudoku grid
const int N = 9;

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if it's safe to place a number in the given row and column
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if the number exists in the row or column
    for (int i = 0; i < N; ++i) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }
    
    // Check if the number exists in the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }
    
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;

    // Find an empty cell
    bool isEmpty = false;
    for (row = 0; row < N; ++row) {
        for (col = 0; col < N; ++col) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    // If no empty cell is found, puzzle is solved
    if (!isEmpty) {
        return true;
    }

    // Try placing numbers from 1 to 9
    for (int num = 1; num <= 9; ++num) {
        // Check if it's safe to place the number in the current cell
        if (isSafe(grid, row, col, num)) {
            // Place the number
            grid[row][col] = num;

            // Recur to solve the rest of the puzzle
            if (solveSudoku(grid)) {
                return true;
            }

            // If placing the number leads to an invalid solution, backtrack
            grid[row][col] = 0;
        }
    }

    // No solution found
    return false;
}

int main() {
    // Example Sudoku grid
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Sudoku puzzle before solving:" << endl;
    printGrid(grid);

    if (solveSudoku(grid)) {
        cout << "\nSudoku puzzle after solving:" << endl;
        printGrid(grid);
    } else {
        cout << "\nNo solution exists for the Sudoku puzzle." << endl;
    }

    return 0;
}
