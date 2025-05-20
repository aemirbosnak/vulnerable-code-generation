//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 9

typedef struct Sudoku {
    int **board;
    int size;
} Sudoku;

Sudoku *sudoku_init(int size) {
    Sudoku *s = (Sudoku *)malloc(sizeof(Sudoku));
    s->board = (int **)malloc(size * sizeof(int *));
    s->size = size;
    for (int i = 0; i < size; i++) {
        s->board[i] = (int *)malloc(size * sizeof(int));
    }
    return s;
}

void sudoku_solve(Sudoku *s) {
    for (int i = 0; i < s->size; i++) {
        for (int j = 0; j < s->size; j++) {
            if (s->board[i][j] == 0) {
                for (int k = 0; k < s->size; k++) {
                    if (s->board[k][j] == 0 && k != i) {
                        for (int l = 0; l < s->size; l++) {
                            if (s->board[i][l] == 0 && l != j) {
                                if (sudoku_valid(s, i, j, k, l)) {
                                    s->board[i][j] = k + 1;
                                    sudoku_solve(s);
                                    s->board[i][j] = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return;
}

int sudoku_valid(Sudoku *s, int i, int j, int k, int l) {
    // Row valid
    for (int r = 0; r < s->size; r++) {
        if (s->board[r][j] == k) {
            return 0;
        }
    }

    // Column valid
    for (int c = 0; c < s->size; c++) {
        if (s->board[i][c] == k) {
            return 0;
        }
    }

    // Subgrid valid
    int subgrid_x = i / 3;
    int subgrid_y = j / 3;
    for (int r = subgrid_x * 3; r < subgrid_x * 3 + 3; r++) {
        for (int c = subgrid_y * 3; c < subgrid_y * 3 + 3; c++) {
            if (s->board[r][c] == k) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    Sudoku *s = sudoku_init(9);
    s->board[0][0] = 5;
    s->board[0][1] = 3;
    s->board[0][2] = 0;
    s->board[0][3] = 0;
    s->board[0][4] = 0;
    s->board[1][0] = 6;
    s->board[1][1] = 0;
    s->board[1][2] = 0;
    s->board[1][3] = 0;
    s->board[1][4] = 0;
    s->board[2][0] = 0;
    s->board[2][1] = 0;
    s->board[2][2] = 0;
    s->board[2][3] = 0;
    s->board[2][4] = 0;
    sudoku_solve(s);

    for (int i = 0; i < s->size; i++) {
        for (int j = 0; j < s->size; j++) {
            printf("%d ", s->board[i][j]);
        }
        printf("\n");
    }

    return 0;
}