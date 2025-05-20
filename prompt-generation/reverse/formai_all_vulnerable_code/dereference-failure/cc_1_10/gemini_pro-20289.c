//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the size of the Sudoku board
#define N 9

// Define the data structure for the Sudoku board
typedef struct {
    int grid[N][N];
    bool solved;
} Sudoku;

// Create a new Sudoku board
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

// Free the memory allocated for the Sudoku board
void free_sudoku(Sudoku* sudoku) {
    free(sudoku);
}

// Print the Sudoku board to the console
void print_sudoku(Sudoku* sudoku) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", sudoku->grid[i][j]);
        }
        printf("\n");
    }
}

// Check if the Sudoku board is valid
bool is_valid_sudoku(Sudoku* sudoku) {
    // Check for duplicate numbers in each row
    for (int i = 0; i < N; i++) {
        int row[N] = {0};
        for (int j = 0; j < N; j++) {
            int num = sudoku->grid[i][j];
            if (num != 0 && row[num]) {
                return false;
            }
            row[num] = true;
        }
    }

    // Check for duplicate numbers in each column
    for (int i = 0; i < N; i++) {
        int col[N] = {0};
        for (int j = 0; j < N; j++) {
            int num = sudoku->grid[j][i];
            if (num != 0 && col[num]) {
                return false;
            }
            col[num] = true;
        }
    }

    // Check for duplicate numbers in each 3x3 subgrid
    for (int i = 0; i < N; i += 3) {
        for (int j = 0; j < N; j += 3) {
            int subgrid[N] = {0};
            for (int k = i; k < i + 3; k++) {
                for (int l = j; l < j + 3; l++) {
                    int num = sudoku->grid[k][l];
                    if (num != 0 && subgrid[num]) {
                        return false;
                    }
                    subgrid[num] = true;
                }
            }
        }
    }

    return true;
}

// Solve the Sudoku board using a recursive backtracking algorithm
bool solve_sudoku(Sudoku* sudoku) {
    // Check if the board is already solved
    if (sudoku->solved) {
        return true;
    }

    // Find the first empty cell
    int row = -1;
    int col = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (sudoku->grid[i][j] == 0) {
                row = i;
                col = j;
                break;
            }
        }
    }

    // If there are no empty cells, the board is solved
    if (row == -1 || col == -1) {
        sudoku->solved = true;
        return true;
    }

    // Try all possible values for the empty cell
    for (int value = 1; value <= N; value++) {
        // Check if the value is valid for the empty cell
        if (is_valid_sudoku(sudoku)) {
            // Set the value for the empty cell
            sudoku->grid[row][col] = value;

            // Recursively solve the board
            if (solve_sudoku(sudoku)) {
                return true;
            }

            // If the board is not solved, unset the value for the empty cell
            sudoku->grid[row][col] = 0;
        }
    }

    // If none of the values are valid for the empty cell, the board is not solvable
    return false;
}

int main() {
    // Create a new Sudoku board
    Sudoku* sudoku = create_sudoku();

    // Initialize the Sudoku board with some given values
    sudoku->grid[0][0] = 5;
    sudoku->grid[0][1] = 3;
    sudoku->grid[0][4] = 7;
    sudoku->grid[1][0] = 6;
    sudoku->grid[1][3] = 1;
    sudoku->grid[1][4] = 9;
    sudoku->grid[1][5] = 5;
    sudoku->grid[2][1] = 9;
    sudoku->grid[2][2] = 8;
    sudoku->grid[2][7] = 6;
    sudoku->grid[3][0] = 8;
    sudoku->grid[3][4] = 6;
    sudoku->grid[3][8] = 3;
    sudoku->grid[4][0] = 4;
    sudoku->grid[4][3] = 8;
    sudoku->grid[4][5] = 3;
    sudoku->grid[4][8] = 1;
    sudoku->grid[5][0] = 7;
    sudoku->grid[5][4] = 2;
    sudoku->grid[5][8] = 6;
    sudoku->grid[6][2] = 6;
    sudoku->grid[6][6] = 2;
    sudoku->grid[6][7] = 8;
    sudoku->grid[7][3] = 4;
    sudoku->grid[7][4] = 1;
    sudoku->grid[7][5] = 9;
    sudoku->grid[7][8] = 5;
    sudoku->grid[8][4] = 8;
    sudoku->grid[8][7] = 7;
    sudoku->grid[8][8] = 9;

    // Print the unsolved Sudoku board to the console
    printf("Unsolved Sudoku board:\n");
    print_sudoku(sudoku);
    printf("\n");

    // Solve the Sudoku board
    if (solve_sudoku(sudoku)) {
        // Print the solved Sudoku board to the console
        printf("Solved Sudoku board:\n");
        print_sudoku(sudoku);
        printf("\n");
    } else {
        printf("The Sudoku board is not solvable.\n");
    }

    // Free the memory allocated for the Sudoku board
    free_sudoku(sudoku);

    return 0;
}