//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: careful
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
    for (int i = 0; i < s->size; i++) {
        for (int j = 0; j < s->size; j++) {
            s->board[i][j] = 0;
        }
    }
}

void sudoku_solve(Sudoku *s) {
    for (int i = 0; i < s->size; i++) {
        for (int j = 0; j < s->size; j++) {
            if (s->board[i][j] == 0) {
                for (int k = 0; k < s->size; k++) {
                    if (s->board[i][k] != 0 && s->board[k][j] != 0) {
                        if (s->board[i][k] == s->board[k][j]) {
                            s->board[i][j] = s->board[i][k];
                            sudoku_solve(s);
                            s->board[i][j] = 0;
                        }
                    }
                }
            }
        }
    }
    if (sudoku_valid(s)) {
        printf("Solution:\n");
        for (int i = 0; i < s->size; i++) {
            for (int j = 0; j < s->size; j++) {
                printf("%d ", s->board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }
}

int sudoku_valid(Sudoku *s) {
    for (int i = 0; i < s->size; i++) {
        int sum = 0;
        for (int j = 0; j < s->size; j++) {
            sum += s->board[i][j];
        }
        if (sum != MAX) {
            return 0;
        }
    }

    for (int j = 0; j < s->size; j++) {
        int sum = 0;
        for (int i = 0; i < s->size; i++) {
            sum += s->board[i][j];
        }
        if (sum != MAX) {
            return 0;
        }
    }

    for (int k = 0; k < s->size; k++) {
        int sum = 0;
        for (int i = 0; i < s->size; i++) {
            for (int j = 0; j < s->size; j++) {
                sum += s->board[i][j];
            }
        }
        if (sum != MAX) {
            return 0;
        }
    }

    return 1;
}

int main() {
    Sudoku *s = sudoku_new(9);
    sudoku_init(s);

    s->board[0][0] = 5;
    s->board[0][1] = 3;
    s->board[0][2] = 0;
    s->board[1][0] = 6;
    s->board[1][1] = 0;
    s->board[1][2] = 0;
    s->board[2][0] = 0;
    s->board[2][1] = 0;
    s->board[2][2] = 0;

    sudoku_solve(s);

    return 0;
}