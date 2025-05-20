//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define SUDO_SIZE 9

typedef struct Sudoku {
    int **board;
    int **visited;
    int **candidates;
} Sudoku;

Sudoku *sudoku_create() {
    Sudoku *s = malloc(sizeof(Sudoku));
    s->board = malloc(sizeof(int *) * SUDO_SIZE);
    for (int i = 0; i < SUDO_SIZE; i++) {
        s->board[i] = malloc(sizeof(int) * SUDO_SIZE);
    }
    s->visited = malloc(sizeof(int *) * SUDO_SIZE);
    for (int i = 0; i < SUDO_SIZE; i++) {
        s->visited[i] = malloc(sizeof(int) * SUDO_SIZE);
    }
    s->candidates = malloc(sizeof(int *) * SUDO_SIZE);
    for (int i = 0; i < SUDO_SIZE; i++) {
        s->candidates[i] = malloc(sizeof(int) * SUDO_SIZE);
    }
    return s;
}

void sudoku_solve(Sudoku *s) {
    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            if (s->board[i][j] == 0 && s->visited[i][j] == 0) {
                for (int k = 0; k < SUDO_SIZE; k++) {
                    if (s->candidates[i][k] && s->visited[k][j] == 0) {
                        s->board[i][j] = s->candidates[i][k];
                        s->visited[i][j] = 1;
                        sudoku_solve(s);
                        s->board[i][j] = 0;
                        s->visited[i][j] = 0;
                    }
                }
            }
        }
    }
    return;
}

int main() {
    Sudoku *s = sudoku_create();
    sudoku_solve(s);
    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            printf("%d ", s->board[i][j]);
        }
        printf("\n");
    }
    return 0;
}