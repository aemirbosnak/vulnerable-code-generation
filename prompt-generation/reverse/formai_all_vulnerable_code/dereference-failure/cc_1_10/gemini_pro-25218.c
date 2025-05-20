//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 9

// Structure to represent a Sudoku puzzle
typedef struct Sudoku {
    int board[BOARD_SIZE][BOARD_SIZE];
} Sudoku;

// Function to create a new Sudoku puzzle
Sudoku* create_sudoku(int board[BOARD_SIZE][BOARD_SIZE]) {
    Sudoku* sudoku = malloc(sizeof(Sudoku));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            sudoku->board[i][j] = board[i][j];
        }
    }
    return sudoku;
}

// Function to print a Sudoku puzzle
void print_sudoku(Sudoku* sudoku) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", sudoku->board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number is valid in a cell
bool is_valid_cell(Sudoku* sudoku, int row, int col, int num) {
    // Check if the number is already present in the row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (sudoku->board[row][i] == num) {
            return false;
        }
    }

    // Check if the number is already present in the column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (sudoku->board[i][col] == num) {
            return false;
        }
    }

    // Check if the number is already present in the 3x3 box
    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
        for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
            if (sudoku->board[i][j] == num) {
                return false;
            }
        }
    }

    // If all checks pass, the number is valid
    return true;
}

// Function to solve a Sudoku puzzle
bool solve_sudoku(Sudoku* sudoku) {
    // Iterate over all cells in the puzzle
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            // If the cell is empty, try to fill it with a valid number
            if (sudoku->board[row][col] == 0) {
                for (int num = 1; num <= BOARD_SIZE; num++) {
                    // If the number is valid, fill the cell and continue solving
                    if (is_valid_cell(sudoku, row, col, num)) {
                        sudoku->board[row][col] = num;
                        if (solve_sudoku(sudoku)) {
                            return true;
                        } else {
                            // If the number is not valid, reset the cell to 0
                            sudoku->board[row][col] = 0;
                        }
                    }
                }
                // If no valid numbers can be found, the puzzle cannot be solved
                return false;
            }
        }
    }

    // If all cells are filled, the puzzle is solved
    return true;
}

int main() {
    // Define the starting state of the Sudoku puzzle
    int board[BOARD_SIZE][BOARD_SIZE] = {
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

    // Create a new Sudoku puzzle
    Sudoku* sudoku = create_sudoku(board);

    // Solve the Sudoku puzzle
    if (solve_sudoku(sudoku)) {
        // Print the solved Sudoku puzzle
        printf("Solved Sudoku puzzle:\n");
        print_sudoku(sudoku);
    } else {
        // The Sudoku puzzle cannot be solved
        printf("The Sudoku puzzle cannot be solved.\n");
    }

    // Free the allocated memory
    free(sudoku);

    return 0;
}