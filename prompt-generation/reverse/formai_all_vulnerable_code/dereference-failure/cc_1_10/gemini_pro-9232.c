//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 9

// Structure to represent a Sudoku puzzle
typedef struct {
    int grid[N][N];
    bool solved;
} Sudoku;

// Function to create a new Sudoku puzzle
Sudoku* create_sudoku() {
    Sudoku* sudoku = (Sudoku*)malloc(sizeof(Sudoku));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sudoku->grid[i][j] = 0;
        }
    }
    sudoku->solved = false;
    return sudoku;
}

// Function to print a Sudoku puzzle
void print_sudoku(Sudoku* sudoku) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", sudoku->grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number is valid in a given cell
bool is_valid(Sudoku* sudoku, int row, int col, int num) {
    // Check if the number is already present in the row
    for (int i = 0; i < N; i++) {
        if (sudoku->grid[row][i] == num) {
            return false;
        }
    }

    // Check if the number is already present in the column
    for (int i = 0; i < N; i++) {
        if (sudoku->grid[i][col] == num) {
            return false;
        }
    }

    // Check if the number is already present in the 3x3 box
    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = 3 * box_row; i < 3 * box_row + 3; i++) {
        for (int j = 3 * box_col; j < 3 * box_col + 3; j++) {
            if (sudoku->grid[i][j] == num) {
                return false;
            }
        }
    }

    // If all checks pass, the number is valid
    return true;
}

// Function to solve a Sudoku puzzle using backtracking
bool solve_sudoku(Sudoku* sudoku) {
    // Find an empty cell
    int row = -1, col = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (sudoku->grid[i][j] == 0) {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1) {
            break;
        }
    }

    // If no empty cell found, the puzzle is solved
    if (row == -1) {
        sudoku->solved = true;
        return true;
    }

    // Try all possible numbers for the empty cell
    for (int num = 1; num <= N; num++) {
        // Check if the number is valid
        if (is_valid(sudoku, row, col, num)) {
            // Set the number in the cell
            sudoku->grid[row][col] = num;

            // Solve the rest of the puzzle recursively
            if (solve_sudoku(sudoku)) {
                return true;
            }

            // If the recursive call fails, reset the cell to 0
            sudoku->grid[row][col] = 0;
        }
    }

    // If no valid number found for the empty cell, return false
    return false;
}

// Main function
int main() {
    // Create a Sudoku puzzle
    Sudoku* sudoku = create_sudoku();

    // Print the unsolved puzzle
    printf("Unsolved puzzle:\n");
    print_sudoku(sudoku);

    // Solve the puzzle
    if (solve_sudoku(sudoku)) {
        // Print the solved puzzle
        printf("Solved puzzle:\n");
        print_sudoku(sudoku);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}