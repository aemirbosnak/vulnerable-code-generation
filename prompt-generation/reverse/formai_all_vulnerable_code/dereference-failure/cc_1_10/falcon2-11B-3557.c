//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: Claude Shannon
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to check if a given value is valid for a given row, column, and 3x3 box
bool isValid(int value, int row, int col, int* board) {
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = 0; i < 9; i++) {
        if (i!= row && board[i * 9 + col] == value) {
            return false;
        }
        if (i!= boxRow * 3 + boxCol && board[(i * 3 + boxCol) * 9 + boxRow] == value) {
            return false;
        }
    }
    return true;
}

// Function to solve the Sudoku puzzle
bool solveSudoku(int* board) {
    bool solved = false;
    int row, col;
    while (!solved) {
        solved = true;
        for (row = 0; row < 9; row++) {
            for (col = 0; col < 9; col++) {
                if (board[row * 9 + col] == 0) {
                    solved = false;
                    for (int value = 1; value <= 9; value++) {
                        if (isValid(value, row, col, board)) {
                            board[row * 9 + col] = value;
                            if (solveSudoku(board)) {
                                return true;
                            }
                            board[row * 9 + col] = 0;
                        }
                    }
                }
            }
        }
    }
    return false;
}

// Main function to test the solver
int main() {
    int board[81] = {0};
    int solved = solveSudoku(board);
    if (solved) {
        printf("Sudoku solved!\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", board[i * 9 + j]);
            }
            printf("\n");
        }
    } else {
        printf("Sudoku unsolvable.\n");
    }
    return 0;
}