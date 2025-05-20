//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUDO_SIZE 9

typedef struct Sudoku {
    int **board;
    int **mask;
    int used;
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
    s->used = 0;
    return s;
}

void sudoku_free(Sudoku *s) {
    for (int i = 0; i < SUDO_SIZE; i++) {
        free(s->board[i]);
    }
    free(s->board);
    for (int i = 0; i < SUDO_SIZE; i++) {
        free(s->mask[i]);
    }
    free(s->mask);
    free(s);
}

int sudoku_solve(Sudoku *s) {
    if (s->used == SUDO_SIZE * SUDO_SIZE) {
        return 1;
    }
    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            if (s->mask[i][j] == 0 && s->board[i][j] == 0) {
                s->board[i][j] = 1;
                s->used++;
                if (sudoku_solve(s) == 1) {
                    return 1;
                }
                s->board[i][j] = 0;
                s->used--;
            }
        }
    }
    return 0;
}

int main() {
    Sudoku *s = sudoku_new();
    sudoku_solve(s);
    sudoku_free(s);
    return 0;
}