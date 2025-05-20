//GPT-4o-mini DATASET v1.0 Category: Sudoku solver ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

// Function to print the Sudoku board
void printBoard(int board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

// Function to check if a number can be placed in the given position
bool isSafe(int board[SIZE][SIZE], int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (board[row][x] == num || board[x][col] == num ||
            board[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
            return false;
        }
    }
    return true;
}

// Backtracking function to solve the Sudoku
bool solveSudoku(int board[SIZE][SIZE]) {
    int row, col, empty = 0;
    bool foundEmpty = false;

    // Search for an empty cell
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == 0) {
                empty++;
                foundEmpty = true;
                break;
            }
        }
        if (foundEmpty) break;
    }

    // No empty cell means we're done
    if (!foundEmpty) return true;

    for (int num = 1; num <= SIZE; num++) {
        if (isSafe(board, row, col, num)) {
            // Place the number and try to solve further
            board[row][col] = num;

            if (solveSudoku(board)) {
                return true;
            }

            // If placing num doesn't lead to a solution, reset it
            board[row][col] = 0; // Backtrack
        }
    }
    return false; // Trigger backtracking
}

// Function to dynamically allocate and read the Sudoku board from input
int** createBoard() {
    int** board = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++) {
        board[i] = (int*)malloc(SIZE * sizeof(int));
    }

    printf("Enter the Sudoku puzzle (0 for empty cells):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    return board;
}

// Free dynamically allocated memory
void freeBoard(int** board) {
    for (int i = 0; i < SIZE; i++) {
        free(board[i]);
    }
    free(board);
}

// Main function to initiate the solving process
int main() {
    int** board = createBoard();
    printf("Original Sudoku board:\n");
    printBoard(board);

    if (solveSudoku(board)) {
        printf("Solved Sudoku board:\n");
        printBoard(board);
    } else {
        printf("No solution exists for the given Sudoku puzzle.\n");
    }

    freeBoard(board);
    return 0;
}