//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

typedef struct Sudoku {
    int **board;
    int size;
    int solved;
} Sudoku;

Sudoku *sudoku_new(int size) {
    Sudoku *s = malloc(sizeof(Sudoku));
    s->board = malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        s->board[i] = malloc(sizeof(int) * size);
    }
    s->size = size;
    s->solved = 0;
    return s;
}

void sudoku_set(Sudoku *s, int x, int y, int value) {
    if (x < 0 || x >= s->size || y < 0 || y >= s->size || value < 0 || value > 9) {
        return;
    }
    s->board[x][y] = value;
}

int sudoku_solve(Sudoku *s) {
    if (s->solved) {
        return 1;
    }

    for (int x = 0; x < s->size; x++) {
        for (int y = 0; y < s->size; y++) {
            if (s->board[x][y] == 0) {
                for (int v = 1; v <= 9; v++) {
                    if (sudoku_valid(s, x, y, v) && sudoku_solve(s) == 1) {
                        s->board[x][y] = v;
                        s->solved = 1;
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

int sudoku_valid(Sudoku *s, int x, int y, int value) {
    // Row validation
    for (int i = 0; i < s->size; i++) {
        if (s->board[x][i] == value) {
            return 0;
        }
    }

    // Column validation
    for (int i = 0; i < s->size; i++) {
        if (s->board[i][y] == value) {
            return 0;
        }
    }

    // Subgrid validation
    int subgrid_x = x / 3;
    int subgrid_y = y / 3;
    for (int i = subgrid_x * 3; i < subgrid_x * 3 + 3; i++) {
        for (int j = subgrid_y * 3; j < subgrid_y * 3 + 3; j++) {
            if (s->board[i][j] == value) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    Sudoku *s = sudoku_new(9);
    sudoku_set(s, 0, 0, 5);
    sudoku_set(s, 2, 2, 3);
    sudoku_set(s, 4, 4, 9);
    sudoku_set(s, 6, 6, 1);
    sudoku_set(s, 8, 8, 4);

    sudoku_solve(s);

    for (int x = 0; x < s->size; x++) {
        for (int y = 0; y < s->size; y++) {
            printf("%d ", s->board[x][y]);
        }
        printf("\n");
    }

    return 0;
}