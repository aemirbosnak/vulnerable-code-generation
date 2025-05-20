//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define SUDO_SIZE 9

typedef struct Sudoku {
    int **board;
    int **visited;
    int **candidates;
} Sudoku;

Sudoku *sudoku_new() {
    Sudoku *s = malloc(sizeof(Sudoku));
    s->board = malloc(sizeof(int *) * SUDO_SIZE);
    s->visited = malloc(sizeof(int *) * SUDO_SIZE);
    s->candidates = malloc(sizeof(int *) * SUDO_SIZE);

    for (int i = 0; i < SUDO_SIZE; i++) {
        s->board[i] = malloc(sizeof(int) * SUDO_SIZE);
        s->visited[i] = malloc(sizeof(int) * SUDO_SIZE);
        s->candidates[i] = malloc(sizeof(int) * SUDO_SIZE);
    }

    return s;
}

void sudoku_free(Sudoku *s) {
    for (int i = 0; i < SUDO_SIZE; i++) {
        free(s->board[i]);
        free(s->visited[i]);
        free(s->candidates[i]);
    }

    free(s->board);
    free(s->visited);
    free(s->candidates);
    free(s);
}

int sudoku_solve(Sudoku *s) {
    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            if (s->board[i][j] == 0 && !s->visited[i][j] && s->candidates[i][j] != 0) {
                s->visited[i][j] = 1;

                for (int k = 0; k < SUDO_SIZE; k++) {
                    if (s->candidates[i][j] & (1 << k) && k != i) {
                        s->board[k][j] = s->candidates[i][j] & ~(1 << k);
                        if (sudoku_solve(s) == 1) {
                            return 1;
                        }
                        s->board[k][j] = 0;
                    }
                }

                s->visited[i][j] = 0;
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    Sudoku *s = sudoku_new();

    s->board[0][0] = 5;
    s->board[0][1] = 3;
    s->board[0][2] = 0;
    s->board[1][0] = 6;
    s->board[1][1] = 0;
    s->board[1][2] = 0;
    s->board[2][0] = 0;
    s->board[2][1] = 0;
    s->board[2][2] = 0;

    sudoku_solve(s);

    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            printf("%d ", s->board[i][j]);
        }
        printf("\n");
    }

    sudoku_free(s);

    return 0;
}