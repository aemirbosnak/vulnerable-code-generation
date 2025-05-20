//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUDO_SIZE 9

typedef struct Sudoku {
    int **board;
    int **mask;
    int **visited;
} Sudoku;

Sudoku *sudoku_new() {
    Sudoku *s = malloc(sizeof(Sudoku));
    s->board = malloc(sizeof(int *) * SUDO_SIZE);
    for (int i = 0; i < SUDO_SIZE; i++) {
        s->board[i] = malloc(sizeof(int) * SUDO_SIZE);
    }
    s->mask = malloc(sizeof(int *) * SUDO_SIZE);
    for (int i = 0; i < SUDO_SIZE; i++) {
        s->mask[i] = malloc(sizeof(int) * SUDO_SIZE);
    }
    s->visited = malloc(sizeof(int *) * SUDO_SIZE);
    for (int i = 0; i < SUDO_SIZE; i++) {
        s->visited[i] = malloc(sizeof(int) * SUDO_SIZE);
    }
    return s;
}

void sudoku_free(Sudoku *s) {
    for (int i = 0; i < SUDO_SIZE; i++) {
        free(s->board[i]);
        free(s->mask[i]);
        free(s->visited[i]);
    }
    free(s->board);
    free(s->mask);
    free(s->visited);
    free(s);
}

int sudoku_solve(Sudoku *s) {
    if (s->board[0][0] == 0) {
        return 0;
    }
    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            if (s->board[i][j] == 0 && s->mask[i][j] == 0) {
                for (int k = 0; k < SUDO_SIZE; k++) {
                    if (s->visited[i][k] == 0 && s->board[k][j] == 0) {
                        s->visited[i][k] = 1;
                        s->board[i][j] = k + 1;
                        if (sudoku_solve(s) == 1) {
                            return 1;
                        }
                        s->board[i][j] = 0;
                        s->visited[i][k] = 0;
                    }
                }
            }
        }
    }
    return 0;
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