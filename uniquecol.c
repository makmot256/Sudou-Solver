#include <stdbool.h>
#include <stdio.h>

#define N 9  // Standard Sudoku grid size

// Function to check if a number can be placed in a specific column
bool isSafeInColumn(int grid[9][9], int col, int num) {
    for (int row = 0; row < 9; row++) {
        // If the number already exists in the column, return false
        if (grid[row][col] == num) {
            return false;
        }
    }
    // If the number is not found in the column, it is safe to place it
    return true;
}

int main() {
    // Sudoku grid with some cells filled and others empty (represented by 0)
    int grid[9][9] = {
          {0,0,0,0,0,0,2,0,0},
          {0,8,0,0,0,7,0,9,0},
          {6,0,2,0,0,0,5,0,0},
          {0,7,0,0,6,0,0,0,0},
          {0,0,0,9,0,1,0,0,0},
          {0,0,0,0,2,0,0,4,0},
          {0,0,5,0,0,0,6,0,3},
          {0,9,0,4,0,0,0,7,0},
          {0,0,6,0,0,0,0,0,0}
    };

    int col = 2; // Column index (0-based)
    int num = 5; // Number to check

    if (isSafeInColumn(grid, col, num)) {
        printf("The number %d can be safely placed in column %d.\n", num, col + 1);
    } else {
        printf("The number %d cannot be placed in column %d.\n", num, col + 1);
    }

    return 0;
}

        // {5, 3, 0, 0, 7, 0, 0, 0, 0},
        // {6, 0, 0, 1, 9, 5, 0, 0, 0},
        // {0, 9, 8, 0, 0, 0, 0, 6, 0},
        // {8, 0, 0, 0, 6, 0, 0, 0, 3},
        // {4, 0, 0, 8, 0, 3, 0, 0, 1},
        // {7, 0, 0, 0, 2, 0, 0, 0, 6},
        // {0, 6, 0, 0, 0, 0, 2, 8, 0},
        // {0, 0, 0, 4, 1, 9, 0, 0, 5},
        // {0, 0, 0, 0, 8, 0, 0, 7, 9}