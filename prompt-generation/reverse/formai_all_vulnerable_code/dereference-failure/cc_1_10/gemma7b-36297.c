//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

typedef struct Sudoku {
    int **board;
    int size;
} Sudoku;

Sudoku *sudoku_init(int size) {
    Sudoku *s = malloc(sizeof(Sudoku));
    s->size = size;
    s->board = malloc(size * size * sizeof(int));
    for (int i = 0; i < size * size; i++) {
        s->board[i] = 0;
    }
    return s;
}

void sudoku_solve(Sudoku *s) {
    for (int i = 0; i < s->size * s->size; i++) {
        if (s->board[i] == 0) {
            for (int r = 0; r < s->size; r++) {
                for (int c = 0; c < s->size; c++) {
                    if (sudoku_valid(s, i, r, c) && s->board[i] == 0) {
                        s->board[i] = r + 1;
                        sudoku_solve(s);
                        s->board[i] = 0;
                    }
                }
            }
            return;
        }
    }
    return;
}

int sudoku_valid(Sudoku *s, int i, int r, int c) {
    // Row valid
    for (int x = 0; x < s->size; x++) {
        if (s->board[i] == s->board[x] && x != i) {
            return 0;
        }
    }

    // Column valid
    for (int y = 0; y < s->size; y++) {
        if (s->board[i] == s->board[y] && y != i) {
            return 0;
        }
    }

    // Subgrid valid
    int sr = i / s->size;
    int sc = i % s->size;
    for (int k = sr; k < sr + 3; k++) {
        for (int l = sc; l < sc + 3; l++) {
            if (s->board[i] == s->board[k * s->size + l] && k * s->size + l != i) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    Sudoku *s = sudoku_init(9);
    sudoku_solve(s);
    for (int i = 0; i < 81; i++) {
        printf("%d ", s->board[i]);
    }
    printf("\n");
    free(s);
    return 0;
}