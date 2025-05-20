//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: portable
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

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            s->board[i][j] = 0;
        }
    }

    return s;
}

void sudoku_solve(Sudoku *s) {
    if (sudoku_is_solved(s)) {
        return;
    }

    for (int i = 0; i < s->size; i++) {
        for (int j = 0; j < s->size; j++) {
            if (s->board[i][j] == 0) {
                for (int k = 1; k <= s->size; k++) {
                    if (sudoku_is_valid(s, i, j, k)) {
                        s->board[i][j] = k;
                        sudoku_solve(s);
                        s->board[i][j] = 0;
                    }
                }
            }
        }
    }
}

int sudoku_is_solved(Sudoku *s) {
    for (int i = 0; i < s->size; i++) {
        for (int j = 0; j < s->size; j++) {
            if (s->board[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int sudoku_is_valid(Sudoku *s, int i, int j, int k) {
    // Row validation
    for (int l = 0; l < s->size; l++) {
        if (s->board[i][l] == k) {
            return 0;
        }
    }

    // Column validation
    for (int m = 0; m < s->size; m++) {
        if (s->board[m][j] == k) {
            return 0;
        }
    }

    // Subgrid validation
    int x = i / 3;
    int y = j / 3;
    for (int n = x * 3; n < x * 3 + 3; n++) {
        for (int o = y * 3; o < y * 3 + 3; o++) {
            if (s->board[n][o] == k) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    Sudoku *s = sudoku_init(9);
    sudoku_solve(s);

    for (int i = 0; i < s->size; i++) {
        for (int j = 0; j < s->size; j++) {
            printf("%d ", s->board[i][j]);
        }
        printf("\n");
    }

    return 0;
}