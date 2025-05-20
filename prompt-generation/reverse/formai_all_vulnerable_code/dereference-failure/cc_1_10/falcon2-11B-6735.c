//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Function to initialize the board
void initializeBoard(int **board, int size) {
    for (int i = 0; i < size; i++) {
        board[i] = (int *)malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++) {
            board[i][j] = 1;
        }
    }
}

// Function to print the board
void printBoard(int **board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to update the board
void updateBoard(int **board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int neighbors = 0;
            if (i > 0 && board[i - 1][j] == 1) {
                neighbors++;
            }
            if (j > 0 && board[i][j - 1] == 1) {
                neighbors++;
            }
            if (i < size - 1 && board[i + 1][j] == 1) {
                neighbors++;
            }
            if (j < size - 1 && board[i][j + 1] == 1) {
                neighbors++;
            }
            if (i > 0 && j > 0 && board[i - 1][j - 1] == 1) {
                neighbors++;
            }
            if (i > 0 && j < size - 1 && board[i - 1][j + 1] == 1) {
                neighbors++;
            }
            if (i < size - 1 && j > 0 && board[i + 1][j - 1] == 1) {
                neighbors++;
            }
            if (i < size - 1 && j < size - 1 && board[i + 1][j + 1] == 1) {
                neighbors++;
            }
            if (neighbors == 3) {
                board[i][j] = 1;
            } else if (neighbors == 2 && board[i][j] == 1) {
                board[i][j] = 0;
            }
        }
    }
}

int main() {
    int size = 20;
    int **board = (int **)malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        board[i] = (int *)malloc(sizeof(int) * size);
    }
    initializeBoard(board, size);
    printf("Initial board:\n");
    printBoard(board, size);
    int steps = 100;
    for (int i = 0; i < steps; i++) {
        updateBoard(board, size);
        printf("Step %d:\n", i + 1);
        printBoard(board, size);
    }
    free(board);
    return 0;
}