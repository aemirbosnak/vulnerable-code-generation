//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 9
#define UNASSIGNED 0

// Structure to represent a Sudoku puzzle
typedef struct Sudoku {
    int grid[BOARD_SIZE][BOARD_SIZE];
    bool solved;
} Sudoku;

// Function to create a new Sudoku puzzle
Sudoku* create_sudoku() {
    Sudoku* sudoku = (Sudoku*)malloc(sizeof(Sudoku));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            sudoku->grid[i][j] = UNASSIGNED;
        }
    }
    sudoku->solved = false;
    return sudoku;
}

// Function to free the memory allocated for a Sudoku puzzle
void free_sudoku(Sudoku* sudoku) {
    free(sudoku);
}

// Function to print a Sudoku puzzle
void print_sudoku(Sudoku* sudoku) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", sudoku->grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a value is safe to assign to a cell
bool is_safe(Sudoku* sudoku, int row, int col, int value) {
    // Check row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (sudoku->grid[row][i] == value) {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (sudoku->grid[i][col] == value) {
            return false;
        }
    }

    // Check box
    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = 3 * box_row; i < 3 * box_row + 3; i++) {
        for (int j = 3 * box_col; j < 3 * box_col + 3; j++) {
            if (sudoku->grid[i][j] == value) {
                return false;
            }
        }
    }

    return true;
}

// Recursive function to solve a Sudoku puzzle
bool solve_sudoku(Sudoku* sudoku, int row, int col) {
    // If the puzzle is already solved, return true
    if (sudoku->solved) {
        return true;
    }

    // If the row or column is out of bounds, return false
    if (row >= BOARD_SIZE || col >= BOARD_SIZE) {
        return false;
    }
    
    // If the cell is already assigned, skip it
    if (sudoku->grid[row][col] != UNASSIGNED) {
        return solve_sudoku(sudoku, row + (col + 1) / BOARD_SIZE, (col + 1) % BOARD_SIZE); // Move to the next cell
    }

    // Try all possible values for the cell
    for (int value = 1; value <= BOARD_SIZE; value++) {
        // If the value is safe to assign, assign it and recurse
        if (is_safe(sudoku, row, col, value)) {
            sudoku->grid[row][col] = value;
            if (solve_sudoku(sudoku, row + (col + 1) / BOARD_SIZE, (col + 1) % BOARD_SIZE)) {
                return true; // Puzzle solved
            }
            sudoku->grid[row][col] = UNASSIGNED; // Backtrack
        }
    }

    return false; // No solution found
}

// Function to solve a Sudoku puzzle
bool solve(Sudoku* sudoku) {
    return solve_sudoku(sudoku, 0, 0);
}

int main() {
    // Create a new Sudoku puzzle
    Sudoku* sudoku = create_sudoku();

    // Set the values of the puzzle
    sudoku->grid[0][0] = 5;
    sudoku->grid[0][1] = 3;
    sudoku->grid[0][4] = 7;
    sudoku->grid[1][0] = 6;
    sudoku->grid[1][3] = 1;
    sudoku->grid[1][4] = 9;
    sudoku->grid[1][5] = 5;
    sudoku->grid[2][1] = 9;
    sudoku->grid[2][2] = 8;
    sudoku->grid[2][7] = 1;
    sudoku->grid[3][0] = 1;
    sudoku->grid[3][6] = 3;
    sudoku->grid[3][7] = 6;
    sudoku->grid[3][8] = 4;
    sudoku->grid[4][3] = 2;
    sudoku->grid[4][5] = 6;
    sudoku->grid[5][0] = 8;
    sudoku->grid[5][3] = 4;
    sudoku->grid[5][5] = 1;
    sudoku->grid[5][8] = 3;
    sudoku->grid[6][0] = 3;
    sudoku->grid[6][4] = 8;
    sudoku->grid[6][6] = 5;
    sudoku->grid[6][7] = 9;
    sudoku->grid[7][5] = 7;
    sudoku->grid[8][0] = 4;
    sudoku->grid[8][6] = 9;
    sudoku->grid[8][7] = 2;

    // Print the initial puzzle
    printf("Initial puzzle:\n");
    print_sudoku(sudoku);

    // Solve the puzzle
    bool solved = solve(sudoku);

    // Print the solved puzzle
    if (solved) {
        printf("\nSolved puzzle:\n");
        print_sudoku(sudoku);
    } else {
        printf("\nPuzzle could not be solved.\n");
    }

    // Free the memory allocated for the puzzle
    free_sudoku(sudoku);

    return 0;
}