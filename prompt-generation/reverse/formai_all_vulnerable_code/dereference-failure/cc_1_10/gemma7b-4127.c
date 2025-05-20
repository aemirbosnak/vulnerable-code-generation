//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define N 9

typedef struct Sudoku {
    int **board;
    int solved;
} Sudoku;

Sudoku *sudoku_init(int n) {
    Sudoku *s = malloc(sizeof(Sudoku));
    s->board = malloc(n * n * sizeof(int));
    s->solved = 0;
    return s;
}

void sudoku_set(Sudoku *s, int x, int y, int value) {
    s->board[x][y] = value;
}

int sudoku_get(Sudoku *s, int x, int y) {
    return s->board[x][y];
}

int sudoku_solve(Sudoku *s) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (sudoku_get(s, i, j) == 0) {
                for (int k = 0; k < N; k++) {
                    if (sudoku_get(s, k, j) != 0 && sudoku_get(s, i, k) != 0 && sudoku_get(s, k, k) != 0) {
                        if (sudoku_get(s, k, j) == s->board[i][k] && sudoku_get(s, i, k) == s->board[k][k]) {
                            sudoku_set(s, i, j, s->board[k][k]);
                            if (sudoku_solve(s) == 1) {
                                return 1;
                            } else {
                                sudoku_set(s, i, j, 0);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

int main() {
    Sudoku *s = sudoku_init(N);
    sudoku_set(s, 0, 0, 5);
    sudoku_set(s, 2, 2, 3);
    sudoku_set(s, 4, 4, 2);
    sudoku_set(s, 6, 6, 4);
    sudoku_set(s, 8, 8, 6);

    if (sudoku_solve(s) == 1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", sudoku_get(s, i, j));
            }
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }

    return 0;
}