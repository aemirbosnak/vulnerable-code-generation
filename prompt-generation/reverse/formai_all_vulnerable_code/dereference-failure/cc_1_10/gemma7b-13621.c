//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define N 9

typedef struct Sudoku {
    int **board;
    int solved;
} Sudoku;

Sudoku *sudoku_new() {
    Sudoku *s = (Sudoku *)malloc(sizeof(Sudoku));
    s->board = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        s->board[i] = (int *)malloc(N * sizeof(int));
    }
    s->solved = 0;
    return s;
}

void sudoku_solve(Sudoku *s) {
    if (s->solved) {
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (s->board[i][j] == 0) {
                for (int k = 0; k < N; k++) {
                    if (s->board[k][j] != 0 && k != i) {
                        if (s->board[i][k] != 0) {
                            continue;
                        }
                    }
                }
                s->board[i][j] = 1;
                sudoku_solve(s);
                s->board[i][j] = 0;
            }
        }
    }
    s->solved = 1;
}

int main() {
    Sudoku *s = sudoku_new();
    sudoku_solve(s);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", s->board[i][j]);
        }
        printf("\n");
    }
    return 0;
}