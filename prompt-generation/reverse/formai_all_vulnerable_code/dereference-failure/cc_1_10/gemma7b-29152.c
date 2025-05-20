//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 9

typedef struct Sudoku {
    int **board;
    int size;
} Sudoku;

Sudoku *sudoku_create(int size) {
    Sudoku *s = malloc(sizeof(Sudoku));
    s->board = malloc(sizeof(int *) * size);
    s->size = size;

    for (int i = 0; i < size; i++) {
        s->board[i] = malloc(sizeof(int) * size);
    }

    return s;
}

void sudoku_solve(Sudoku *s) {
    for (int i = 0; i < s->size; i++) {
        for (int j = 0; j < s->size; j++) {
            if (s->board[i][j] == 0) {
                for (int k = 0; k < s->size; k++) {
                    if (s->board[k][j] != 0 && s->board[i][k] != 0) {
                        if (s->board[k][j] == s->board[i][k]) {
                            s->board[i][j] = s->board[k][j];
                            break;
                        }
                    }
                }

                if (s->board[i][j] == 0) {
                    s->board[i][j] = 1;
                    sudoku_solve(s);
                    s->board[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    Sudoku *s = sudoku_create(MAX_SIZE);

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

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%d ", s->board[i][j]);
        }
        printf("\n");
    }

    return 0;
}