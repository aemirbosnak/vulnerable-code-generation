//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

typedef struct Sudoku {
    int **board;
    int size;
} Sudoku;

Sudoku *sudoku_new(int size) {
    Sudoku *s = malloc(sizeof(Sudoku));
    s->board = malloc(size * size * sizeof(int));
    s->size = size;
    return s;
}

void sudoku_init(Sudoku *s) {
    int i, j;
    for (i = 0; i < s->size; i++) {
        for (j = 0; j < s->size; j++) {
            s->board[i][j] = 0;
        }
    }
}

void sudoku_solve(Sudoku *s) {
    int i, j, k, r, c;
    for (i = 0; i < s->size; i++) {
        for (j = 0; j < s->size; j++) {
            if (s->board[i][j] == 0) {
                for (k = 0; k < s->size; k++) {
                    r = i / 3;
                    c = j / 3;
                    if (s->board[k][r] == 0 && s->board[k][c] == 0) {
                        s->board[i][j] = k + 1;
                        sudoku_solve(s);
                        s->board[i][j] = 0;
                    }
                }
            }
        }
    }
    if (s->board[0][0] != 0) {
        printf("Solution:\n");
        for (i = 0; i < s->size; i++) {
            for (j = 0; j < s->size; j++) {
                printf("%d ", s->board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }
}

int main() {
    Sudoku *s = sudoku_new(9);
    sudoku_init(s);
    s->board[0][0] = 5;
    s->board[2][2] = 6;
    s->board[4][4] = 1;
    s->board[6][6] = 3;
    sudoku_solve(s);
    return 0;
}