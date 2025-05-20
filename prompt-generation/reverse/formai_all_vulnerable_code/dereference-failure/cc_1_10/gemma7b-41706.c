//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUDO_SIZE 9

typedef struct Sudoku {
    int **board;
    int **cache;
    int **solve;
    int level;
    int score;
} Sudoku;

Sudoku *sudoku_new(int level) {
    Sudoku *s = malloc(sizeof(Sudoku));
    s->board = malloc(sizeof(int *) * SUDO_SIZE);
    for (int i = 0; i < SUDO_SIZE; i++) {
        s->board[i] = malloc(sizeof(int) * SUDO_SIZE);
    }
    s->cache = malloc(sizeof(int *) * SUDO_SIZE);
    for (int i = 0; i < SUDO_SIZE; i++) {
        s->cache[i] = malloc(sizeof(int) * SUDO_SIZE);
    }
    s->solve = malloc(sizeof(int *) * SUDO_SIZE);
    for (int i = 0; i < SUDO_SIZE; i++) {
        s->solve[i] = malloc(sizeof(int) * SUDO_SIZE);
    }
    s->level = level;
    s->score = 0;
    return s;
}

void sudoku_solve(Sudoku *s) {
    int i, j, k;
    for (i = 0; i < SUDO_SIZE; i++) {
        for (j = 0; j < SUDO_SIZE; j++) {
            if (s->board[i][j] == 0) {
                for (k = 0; k < SUDO_SIZE; k++) {
                    if (s->cache[i][k] == 0 && s->solve[k][j] == 0) {
                        s->board[i][j] = k + 1;
                        s->cache[i][k] = 1;
                        sudoku_solve(s);
                        s->board[i][j] = 0;
                        s->cache[i][k] = 0;
                    }
                }
            }
        }
    }
    if (s->score < s->level) {
        s->score++;
    }
}

int main() {
    Sudoku *s = sudoku_new(5);
    sudoku_solve(s);
    printf("Score: %d\n", s->score);
    return 0;
}