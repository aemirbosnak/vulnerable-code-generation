//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Sudoku puzzle size.
#define N 9

// Number of possible values for each cell.
#define NUM_VALUES 9

// Data structure to represent a Sudoku puzzle.
typedef struct {
    int grid[N][N];
} Sudoku;

// Function to create a new Sudoku puzzle.
Sudoku* create_sudoku() {
    Sudoku* sudoku = malloc(sizeof(Sudoku));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sudoku->grid[i][j] = 0;
        }
    }
    return sudoku;
}

// Function to free a Sudoku puzzle.
void free_sudoku(Sudoku* sudoku) {
    free(sudoku);
}

// Function to print a Sudoku puzzle.
void print_sudoku(Sudoku* sudoku) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", sudoku->grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a Sudoku puzzle is valid.
int is_valid_sudoku(Sudoku* sudoku) {
    // Check each row.
    for (int i = 0; i < N; i++) {
        int row[NUM_VALUES] = {0};
        for (int j = 0; j < N; j++) {
            int value = sudoku->grid[i][j];
            if (value < 1 || value > NUM_VALUES) {
                return 0;
            }
            row[value - 1]++;
            if (row[value - 1] > 1) {
                return 0;
            }
        }
    }

    // Check each column.
    for (int j = 0; j < N; j++) {
        int col[NUM_VALUES] = {0};
        for (int i = 0; i < N; i++) {
            int value = sudoku->grid[i][j];
            if (value < 1 || value > NUM_VALUES) {
                return 0;
            }
            col[value - 1]++;
            if (col[value - 1] > 1) {
                return 0;
            }
        }
    }

    // Check each 3x3 box.
    for (int i = 0; i < N; i += 3) {
        for (int j = 0; j < N; j += 3) {
            int box[NUM_VALUES] = {0};
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    int value = sudoku->grid[i + k][j + l];
                    if (value < 1 || value > NUM_VALUES) {
                        return 0;
                    }
                    box[value - 1]++;
                    if (box[value - 1] > 1) {
                        return 0;
                    }
                }
            }
        }
    }

    return 1;
}

// Function to solve a Sudoku puzzle using a backtracking algorithm.
int solve_sudoku(Sudoku* sudoku) {
    // Find the first empty cell.
    int i = 0;
    int j = 0;
    while (i < N && j < N) {
        if (sudoku->grid[i][j] == 0) {
            break;
        }
        j++;
        if (j == N) {
            j = 0;
            i++;
        }
    }

    // If there are no empty cells, the puzzle is solved.
    if (i == N && j == N) {
        return 1;
    }

    // Try all possible values for the empty cell.
    for (int value = 1; value <= NUM_VALUES; value++) {
        // Check if the value is valid for the empty cell.
        if (is_valid_move(sudoku, i, j, value)) {
            // Set the value for the empty cell.
            sudoku->grid[i][j] = value;

            // Recursively solve the puzzle with the new value.
            if (solve_sudoku(sudoku)) {
                return 1;
            }

            // If the recursive call fails, reset the value for the empty cell.
            sudoku->grid[i][j] = 0;
        }
    }

    // If none of the possible values are valid for the empty cell, the puzzle is not solvable.
    return 0;
}

// Function to check if a move is valid for a given Sudoku puzzle.
int is_valid_move(Sudoku* sudoku, int i, int j, int value) {
    // Check if the value is already present in the row.
    for (int k = 0; k < N; k++) {
        if (sudoku->grid[i][k] == value) {
            return 0;
        }
    }

    // Check if the value is already present in the column.
    for (int k = 0; k < N; k++) {
        if (sudoku->grid[k][j] == value) {
            return 0;
        }
    }

    // Check if the value is already present in the 3x3 box.
    int box_i = i / 3;
    int box_j = j / 3;
    for (int k = box_i * 3; k < box_i * 3 + 3; k++) {
        for (int l = box_j * 3; l < box_j * 3 + 3; l++) {
            if (sudoku->grid[k][l] == value) {
                return 0;
            }
        }
    }

    // If the value is not present in the row, column, or 3x3 box, the move is valid.
    return 1;
}

int main() {
    // Create a new Sudoku puzzle.
    Sudoku* sudoku = create_sudoku();

    // Set the values of the puzzle.
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
    sudoku->grid[3][2] = 6;
    sudoku->grid[3][6] = 2;
    sudoku->grid[3][7] = 8;
    sudoku->grid[4][3] = 4;
    sudoku->grid[4][5] = 2;
    sudoku->grid[4][8] = 5;
    sudoku->grid[5][1] = 2;
    sudoku->grid[5][2] = 9;
    sudoku->grid[5][6] = 4;
    sudoku->grid[6][5] = 3;
    sudoku->grid[7][3] = 5;
    sudoku->grid[7][4] = 8;
    sudoku->grid[7][8] = 3;
    sudoku->grid[8][0] = 4;
    sudoku->grid[8][6] = 7;
    sudoku->grid[8][7] = 2;

    // Print the original puzzle.
    printf("Original puzzle:\n");
    print_sudoku(sudoku);

    // Solve the puzzle.
    if (solve_sudoku(sudoku)) {
        // Print the solved puzzle.
        printf("\nSolved puzzle:\n");
        print_sudoku(sudoku);
    } else {
        printf("Puzzle cannot be solved.\n");
    }

    // Free the puzzle.
    free_sudoku(sudoku);

    return 0;
}