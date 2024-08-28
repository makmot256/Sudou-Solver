#include <stdio.h>
#include <stdbool.h>

// Function to print the Sudoku board
void printSudoku(int board[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

// Function to check if placing num in board[row][col] is valid
bool isValid(int board[9][9], int row, int col, int num) {
    // Check the row
    for (int x = 0; x < 9; x++) {
        if (board[row][x] == num) {
            return false;
        }
    }
    
    // Check the column
    for (int x = 0; x < 9; x++) {
        if (board[x][col] == num) {
            return false;
        }
    }
    
    // Check the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    
    return true;
}

// Function to solve the Sudoku board using backtracking
bool solveSudoku(int board[9][9]) {
    int row, col;
    bool empty = false;
    
    // Find an empty cell
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) { // Assuming 0 is an empty cell
                empty = true;
                break;
            }
        }
        if (empty) {
            break;
        }
    }
    
    // No empty cell means the board is solved
    if (!empty) {
        return true;
    }
    
    // Try placing digits 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            
            // Recursively try to solve the rest of the board
            if (solveSudoku(board)) {
                return true;
            }
            
            // If placing num doesn't lead to a solution, undo the move
            board[row][col] = 0;
        }
    }
    
    return false; // Trigger backtracking
}

int main() {
    int board[9][9] = {
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
    
    if (solveSudoku(board)) {
        printf("Sudoku solved successfully!\n");
        printSudoku(board);
    } else {
        printf("No solution exists.\n");
    }
    
    return 0;
}

//  Explanation:
// isValid function: Checks if placing a number in a specific cell follows Sudoku rules (no duplicates in the row, column, or 3x3 subgrid).
// solveSudoku function: Implements the backtracking algorithm to solve the puzzle. It finds the first empty cell, tries each possible number, and recursively attempts to complete the puzzle. If no number works, it backtracks.
// printSudoku function: Prints the Sudoku grid.
// 4. Running the Code:
// Compile and run the C program using any standard C compiler (like GCC).
// If the puzzle is solvable, it will print the solved Sudoku grid; 
// otherwise, it will indicate that no solution exists.
// 5. Logical Reasoning Enhancement:
// Solving Sudoku in C using a 2D array helps you understand multidimensional 
// arrays, recursion, and how to systematically approach solving a problem through trial, error, 
// and logical deduction.



// This function can be integrated into a Sudoku-solving program to ensure that the number placement is valid according to the column rule.
int main() {
    int board[9][9] = {
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

    int col = 2;  // Example column index
    int num = 8;  // Example number to place

    if (isUniqueInColumn(board, col, num)) {
        printf("Number %d can be placed in column %d.\n", num, col);
    } else {
        printf("Number %d cannot be placed in column %d because it already exists.\n", num, col);
    }

    return 0;
}
