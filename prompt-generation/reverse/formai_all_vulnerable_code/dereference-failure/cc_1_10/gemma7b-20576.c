//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 9

typedef struct Sudoku {
    int **board;
    int size;
    int solved;
} Sudoku;

Sudoku *sudoku_create(int size) {
    Sudoku *s = malloc(sizeof(Sudoku));
    s->board = malloc(size * size * sizeof(int));
    s->size = size;
    s->solved = 0;

    for (int i = 0; i < size * size; i++) {
        s->board[i] = 0;
    }

    return s;
}

void sudoku_solve(Sudoku *s) {
    if (s->solved) {
        return;
    }

    for (int i = 0; i < s->size * s->size; i++) {
        if (s->board[i] == 0) {
            for (int n = 1; n <= s->size; n++) {
                if (sudoku_valid(s, i, n)) {
                    s->board[i] = n;
                    sudoku_solve(s);
                    s->board[i] = 0;
                }
            }
        }
    }

    s->solved = 1;
}

int sudoku_valid(Sudoku *s, int idx, int n) {
    // Row validation
    for (int i = 0; i < s->size; i++) {
        if (s->board[idx] == n && s->board[i] == n) {
            return 0;
        }
    }

    // Column validation
    for (int j = 0; j < s->size; j++) {
        if (s->board[idx] == n && s->board[j] == n) {
            return 0;
        }
    }

    // Subgrid validation
    int x = idx / s->size;
    int y = idx % s->size;
    for (int i = x * s->size; i < x * s->size + s->size; i++) {
        for (int j = y * s->size; j < y * s->size + s->size; j++) {
            if (s->board[idx] == n && s->board[i] == n) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    Sudoku *s = sudoku_create(MAX_SIZE);

    sudoku_solve(s);

    if (s->solved) {
        for (int i = 0; i < MAX_SIZE * MAX_SIZE; i++) {
            printf("%d ", s->board[i]);
        }
        printf("\n");
    } else {
        printf("No solution found.\n");
    }

    return 0;
}