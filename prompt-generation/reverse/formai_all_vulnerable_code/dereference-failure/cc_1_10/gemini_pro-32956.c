//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// define the size of the sudoku puzzle
#define SIZE 9

// create a structure to represent a sudoku puzzle
typedef struct {
    int grid[SIZE][SIZE];
    int solved;
} Puzzle;

// create a new sudoku puzzle
Puzzle* new_puzzle() {
    Puzzle* puzzle = malloc(sizeof(Puzzle));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            puzzle->grid[i][j] = 0;
        }
    }
    puzzle->solved = 0;
    return puzzle;
}

// print a sudoku puzzle
void print_puzzle(Puzzle* puzzle) {
    for (int i = 0; i < SIZE; i++) {
        if (i % 3 == 0) {
            printf("+-------+-------+-------+\n");
        }
        for (int j = 0; j < SIZE; j++) {
            if (j % 3 == 0) {
                printf("| ");
            }
            printf("%d ", puzzle->grid[i][j]);
        }
        printf("|\n");
    }
    printf("+-------+-------+-------+\n");
}

// check if a sudoku puzzle is valid
int valid_puzzle(Puzzle* puzzle) {
    // check if each row contains all the digits from 1 to 9
    for (int i = 0; i < SIZE; i++) {
        int row_digits[SIZE] = {0};
        for (int j = 0; j < SIZE; j++) {
            if (puzzle->grid[i][j] < 1 || puzzle->grid[i][j] > SIZE) {
                return 0;
            }
            row_digits[puzzle->grid[i][j] - 1]++;
        }
        for (int j = 0; j < SIZE; j++) {
            if (row_digits[j] != 1) {
                return 0;
            }
        }
    }

    // check if each column contains all the digits from 1 to 9
    for (int i = 0; i < SIZE; i++) {
        int col_digits[SIZE] = {0};
        for (int j = 0; j < SIZE; j++) {
            col_digits[puzzle->grid[j][i] - 1]++;
        }
        for (int j = 0; j < SIZE; j++) {
            if (col_digits[j] != 1) {
                return 0;
            }
        }
    }

    // check if each 3x3 subgrid contains all the digits from 1 to 9
    for (int i = 0; i < SIZE; i += 3) {
        for (int j = 0; j < SIZE; j += 3) {
            int subgrid_digits[SIZE] = {0};
            for (int k = i; k < i + 3; k++) {
                for (int l = j; l < j + 3; l++) {
                    subgrid_digits[puzzle->grid[k][l] - 1]++;
                }
            }
            for (int k = 0; k < SIZE; k++) {
                if (subgrid_digits[k] != 1) {
                    return 0;
                }
            }
        }
    }

    return 1;
}

// solve a sudoku puzzle using backtracking
int solve_puzzle(Puzzle* puzzle) {
    // find the first empty cell
    int row = -1;
    int col = -1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (puzzle->grid[i][j] == 0) {
                row = i;
                col = j;
                break;
            }
        }
    }

    // if there is no empty cell, the puzzle is solved
    if (row == -1 && col == -1) {
        puzzle->solved = 1;
        return 1;
    }

    // try all possible values for the empty cell
    for (int value = 1; value <= SIZE; value++) {
        // check if the value is valid for the empty cell
        int valid = 1;
        for (int i = 0; i < SIZE; i++) {
            if (puzzle->grid[row][i] == value || puzzle->grid[i][col] == value) {
                valid = 0;
                break;
            }
        }
        int start_row = row - row % 3;
        int start_col = col - col % 3;
        for (int i = start_row; i < start_row + 3; i++) {
            for (int j = start_col; j < start_col + 3; j++) {
                if (puzzle->grid[i][j] == value) {
                    valid = 0;
                    break;
                }
            }
        }

        // if the value is valid, try it
        if (valid) {
            puzzle->grid[row][col] = value;

            // recursively solve the puzzle
            if (solve_puzzle(puzzle)) {
                return 1;
            }

            // if the recursive call failed, reset the value to 0
            puzzle->grid[row][col] = 0;
        }
    }

    // if no valid values were found, the puzzle is unsolvable
    return 0;
}

int main() {
    // create a new sudoku puzzle
    Puzzle* puzzle = new_puzzle();

    // print the puzzle
    printf("Initial puzzle:\n");
    print_puzzle(puzzle);

    // solve the puzzle
    if (solve_puzzle(puzzle)) {
        printf("Solved puzzle:\n");
        print_puzzle(puzzle);
    } else {
        printf("Puzzle is unsolvable.\n");
    }

    return 0;
}