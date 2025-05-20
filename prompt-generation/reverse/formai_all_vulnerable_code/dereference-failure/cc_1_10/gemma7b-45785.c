//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 9

typedef struct Sudoku {
    int **board;
    int size;
    int is_solved;
} Sudoku;

Sudoku *sudoku_init(int size) {
    Sudoku *sudoku = malloc(sizeof(Sudoku));
    sudoku->board = malloc(size * size * sizeof(int));
    sudoku->size = size;
    sudoku->is_solved = 0;
    return sudoku;
}

void sudoku_solve(Sudoku *sudoku) {
    for (int i = 0; i < sudoku->size; i++) {
        for (int j = 0; j < sudoku->size; j++) {
            if (sudoku->board[i][j] == 0) {
                for (int k = 0; k < sudoku->size; k++) {
                    if (sudoku->board[i][k] == sudoku->board[k][j] && sudoku->board[k][k] == 0) {
                        sudoku->board[i][j] = k + 1;
                        sudoku_solve(sudoku);
                        sudoku->board[i][j] = 0;
                    }
                }
            }
        }
    }

    sudoku->is_solved = 1;
}

int main() {
    Sudoku *sudoku = sudoku_init(MAX_SIZE);
    sudoku_solve(sudoku);

    if (sudoku->is_solved) {
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

    return 0;
}