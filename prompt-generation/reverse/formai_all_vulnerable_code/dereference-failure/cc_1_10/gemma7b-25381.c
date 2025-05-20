//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 9

typedef struct Sudoku {
    int **board;
    int size;
    int **solution;
} Sudoku;

Sudoku *sudoku_new(int size) {
    Sudoku *sudoku = malloc(sizeof(Sudoku));
    sudoku->board = malloc(size * size * sizeof(int));
    sudoku->size = size;
    sudoku->solution = malloc(size * size * sizeof(int));
    return sudoku;
}

void sudoku_solve(Sudoku *sudoku) {
    for (int i = 0; i < sudoku->size; i++) {
        for (int j = 0; j < sudoku->size; j++) {
            if (sudoku->board[i][j] == 0) {
                for (int k = 0; k < sudoku->size; k++) {
                    if (sudoku->board[k][j] != 0 && sudoku->board[i][k] != 0) {
                        if (sudoku->solution[i][j] == 0) {
                            sudoku->solution[i][j] = sudoku->board[k][j];
                            sudoku_solve(sudoku);
                            sudoku->solution[i][j] = 0;
                        }
                    }
                }
            }
        }
    }
    return;
}

int main() {
    Sudoku *sudoku = sudoku_new(MAX_SIZE);
    sudoku->board[0][0] = 5;
    sudoku->board[0][1] = 3;
    sudoku->board[0][2] = 0;
    sudoku->board[1][0] = 6;
    sudoku->board[1][1] = 0;
    sudoku->board[1][2] = 0;
    sudoku->board[2][0] = 0;
    sudoku->board[2][1] = 9;
    sudoku->board[2][2] = 0;

    sudoku_solve(sudoku);

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%d ", sudoku->solution[i][j]);
        }
        printf("\n");
    }

    free(sudoku->board);
    free(sudoku->solution);
    free(sudoku);

    return 0;
}