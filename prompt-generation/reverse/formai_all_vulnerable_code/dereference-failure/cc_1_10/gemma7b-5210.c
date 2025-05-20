//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

typedef struct Sudoku {
    int **board;
    int size;
    int solved;
} Sudoku;

Sudoku *sudoku_new(int size) {
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
            for (int j = 0; j < s->size * s->size; j++) {
                if (s->board[j] == 0 && i != j) {
                    s->board[i] = s->board[j] = 2;
                    sudoku_solve(s);
                    s->board[i] = s->board[j] = 0;
                }
            }
        }
    }

    s->solved = 1;
}

int main() {
    Sudoku *s = sudoku_new(9);
    sudoku_solve(s);

    for (int i = 0; i < s->size * s->size; i++) {
        printf("%d ", s->board[i]);
    }

    printf("\n");

    return 0;
}