//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 9
#define COLS 9

typedef struct {
    int matrix[ROWS][COLS];
    int size;
} Sudoku;

Sudoku* create_sudoku() {
    Sudoku* sudoku = (Sudoku*)malloc(sizeof(Sudoku));
    memset(sudoku->matrix, 0, sizeof(sudoku->matrix));
    sudoku->size = ROWS * COLS;
    return sudoku;
}

void print_sudoku(Sudoku* sudoku) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (sudoku->matrix[i][j]!= 0) {
                printf("%d ", sudoku->matrix[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void solve_sudoku(Sudoku* sudoku) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (sudoku->matrix[i][j] == 0) {
                for (int k = 1; k <= 9; k++) {
                    if (is_valid(sudoku, i, j, k)) {
                        sudoku->matrix[i][j] = k;
                        solve_sudoku(sudoku);
                        if (is_solved(sudoku)) {
                            return;
                        }
                        sudoku->matrix[i][j] = 0;
                    }
                }
            }
        }
    }
}

int is_valid(Sudoku* sudoku, int row, int col, int num) {
    for (int i = 0; i < ROWS; i++) {
        if (sudoku->matrix[i][col] == num) {
            return 0;
        }
    }
    for (int i = 0; i < COLS; i++) {
        if (sudoku->matrix[row][i] == num) {
            return 0;
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (sudoku->matrix[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int is_solved(Sudoku* sudoku) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (sudoku->matrix[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    Sudoku* sudoku = create_sudoku();
    print_sudoku(sudoku);
    solve_sudoku(sudoku);
    printf("\nSolved Sudoku:\n");
    print_sudoku(sudoku);
    free(sudoku);
    return 0;
}