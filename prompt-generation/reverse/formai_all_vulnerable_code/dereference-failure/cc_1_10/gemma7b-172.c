//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

typedef struct Sudoku {
    int **board;
    int size;
} Sudoku;

Sudoku *sudoku_create(int size) {
    Sudoku *sudoku = malloc(sizeof(Sudoku));
    sudoku->size = size;
    sudoku->board = malloc(size * size * sizeof(int));
    for (int i = 0; i < size * size; i++) {
        sudoku->board[i] = 0;
    }
    return sudoku;
}

void sudoku_solve(Sudoku *sudoku) {
    for (int i = 0; i < sudoku->size; i++) {
        for (int j = 0; j < sudoku->size; j++) {
            if (sudoku->board[i][j] == 0) {
                for (int k = 0; k < sudoku->size; k++) {
                    if (sudoku->board[k][j] == sudoku->board[i][k] && sudoku->board[k][j] != 0) {
                        sudoku->board[i][j] = sudoku->board[k][j];
                        sudoku_solve(sudoku);
                        sudoku->board[i][j] = 0;
                    }
                }
            }
        }
    }
    if (sudoku_is_valid(sudoku)) {
        printf("Solution:\n");
        for (int i = 0; i < sudoku->size; i++) {
            for (int j = 0; j < sudoku->size; j++) {
                printf("%d ", sudoku->board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }
}

int sudoku_is_valid(Sudoku *sudoku) {
    for (int i = 0; i < sudoku->size; i++) {
        int row_sum = 0;
        for (int j = 0; j < sudoku->size; j++) {
            row_sum += sudoku->board[i][j];
        }
        if (row_sum != MAX_SIZE) {
            return 0;
        }
    }

    for (int j = 0; j < sudoku->size; j++) {
        int column_sum = 0;
        for (int i = 0; i < sudoku->size; i++) {
            column_sum += sudoku->board[i][j];
        }
        if (column_sum != MAX_SIZE) {
            return 0;
        }
    }

    return 1;
}

int main() {
    Sudoku *sudoku = sudoku_create(9);
    sudoku_solve(sudoku);

    return 0;
}