//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    return s;
}

void sudoku_solve(Sudoku *s) {
    if (s->solved) {
        return;
    }

    for (int i = 0; i < s->size; i++) {
        for (int j = 0; j < s->size; j++) {
            if (s->board[i][j] == 0) {
                for (int k = 0; k < s->size; k++) {
                    if (s->board[i][k] == s->board[k][j] && s->board[k][k] == 0) {
                        s->board[i][j] = k + 1;
                        sudoku_solve(s);
                        s->board[i][j] = 0;
                    }
                }
            }
        }
    }

    if (sudoku_is_solved(s)) {
        s->solved = 1;
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

int main() {
    Sudoku *s = sudoku_new(9);
    sudoku_solve(s);

    if (sudoku_is_solved(s)) {
        printf("Sudoku solution:\n");
        for (int i = 0; i < s->size; i++) {
            for (int j = 0; j < s->size; j++) {
                printf("%d ", s->board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }

    return 0;
}