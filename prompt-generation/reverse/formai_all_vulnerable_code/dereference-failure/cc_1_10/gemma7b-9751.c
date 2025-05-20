//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define SUDO_SIZE 9

typedef struct Sudoku {
    int **board;
    int **visited;
    int **candidates;
} Sudoku;

Sudoku* sudoku_init(int size) {
    Sudoku* s = malloc(sizeof(Sudoku));
    s->board = malloc(size * size * sizeof(int));
    s->visited = malloc(size * size * sizeof(int));
    s->candidates = malloc(size * size * sizeof(int));
    return s;
}

void sudoku_solve(Sudoku* s) {
    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            if (s->visited[i][j] == 0 && s->candidates[i][j] > 0) {
                for (int k = 1; k <= s->candidates[i][j]; k++) {
                    if (sudoku_valid(s, i, j, k)) {
                        s->board[i][j] = k;
                        s->visited[i][j] = 1;
                        sudoku_solve(s);
                        s->board[i][j] = 0;
                        s->visited[i][j] = 0;
                    }
                }
            }
        }
    }
}

int sudoku_valid(Sudoku* s, int i, int j, int k) {
    // Valid row
    for (int l = 0; l < SUDO_SIZE; l++) {
        if (s->board[i][l] == k) {
            return 0;
        }
    }

    // Valid column
    for (int m = 0; m < SUDO_SIZE; m++) {
        if (s->board[m][j] == k) {
            return 0;
        }
    }

    // Valid 3x3 box
    int box_i = i / 3;
    int box_j = j / 3;
    for (int n = box_i * 3; n < box_i * 3 + 3; n++) {
        for (int o = box_j * 3; o < box_j * 3 + 3; o++) {
            if (s->board[n][o] == k) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    Sudoku* s = sudoku_init(SUDO_SIZE);
    sudoku_solve(s);

    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            printf("%d ", s->board[i][j]);
        }
        printf("\n");
    }

    return 0;
}