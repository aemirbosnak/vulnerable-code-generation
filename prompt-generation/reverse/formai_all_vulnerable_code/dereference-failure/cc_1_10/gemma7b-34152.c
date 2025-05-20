//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUDO_SIZE 9

typedef struct Sudoku {
    int **board;
    int size;
} Sudoku;

Sudoku *sudoku_init(int size) {
    Sudoku *sudoku = malloc(sizeof(Sudoku));
    sudoku->size = size;
    sudoku->board = malloc(size * size * sizeof(int));
    for (int i = 0; i < size * size; i++) {
        sudoku->board[i] = 0;
    }
    return sudoku;
}

void sudoku_solve(Sudoku *sudoku) {
    for (int i = 0; i < sudoku->size * sudoku->size; i++) {
        if (sudoku->board[i] == 0) {
            for (int r = 0; r < sudoku->size; r++) {
                for (int c = 0; c < sudoku->size; c++) {
                    if (sudoku->board[r * sudoku->size + c] == 0 && r != i / sudoku->size && c != (i % sudoku->size) ) {
                        sudoku->board[i] = 1 + rand() % 9;
                        sudoku_solve(sudoku);
                        sudoku->board[i] = 0;
                    }
                }
            }
            return;
        }
    }
    printf("Solved Sudoku:\n");
    for (int i = 0; i < sudoku->size; i++) {
        for (int j = 0; j < sudoku->size; j++) {
            printf("%d ", sudoku->board[i * sudoku->size + j]);
        }
        printf("\n");
    }
}

int main() {
    Sudoku *sudoku = sudoku_init(SUDO_SIZE);
    sudoku_solve(sudoku);
    free(sudoku->board);
    free(sudoku);

    return 0;
}