//Function to check whether a number can be placed in a specific cell without violating the Sudokku Rules(each number must be unique in its column)

#include <stdbool.h>

bool isUniqueInColumn(int board[9][9], int col, int num) {
    for (int row = 0; row < 9; row++) {
        if (board[row][col] == num) {
            return false; // The number already exists in the column
        }
    }
    return true; // The number is unique in the column
}


// Explanation:
// Parameters:

// board[9][9]: The 9x9 Sudoku board represented as a 2D array.
// col: The column index where you want to place the number.
// num: The number you want to place in the specific cell.
// Logic:

// The function iterates through each row in the specified column.
// If it finds the number num already present in that column, it returns false,
//  indicating that the number is not unique and cannot be placed in that column.
// If the number num is not found in the column, the function returns true, 
// indicating that the number can be placed in the specified cell without violating the Sudoku column rule.



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


//OUTPUT
Output:
If the column contains the number, the output will be:

arduino
Copy code
// in arduino, Number 8 cannot be placed in column 2 because it already exists.
If the column does not contain the number, the output will be:

javascript
Copy code
// in js Number 8 can be placed in column 2.
This function helps ensure that the Sudoku rules are followed when filling in numbers, specifically maintaining uniqueness within each column.






