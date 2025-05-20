//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

typedef struct Sudoku {
    int **board;
    int size;
} Sudoku;

Sudoku *sudoku_new(int size) {
    Sudoku *s = malloc(sizeof(Sudoku));
    s->board = malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        s->board[i] = malloc(sizeof(int) * size);
    }
    s->size = size;
    return s;
}

void sudoku_solve(Sudoku *s) {
    for (int i = 0; i < s->size; i++) {
        for (int j = 0; j < s->size; j++) {
            if (s->board[i][j] == 0) {
                for (int k = 0; k < s->size; k++) {
                    if (s->board[k][j] != 0 && k != i) {
                        int num = s->board[k][j];
                        if (s->board[i][num] == 0) {
                            s->board[i][num] = 1;
                            sudoku_solve(s);
                            s->board[i][num] = 0;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    Sudoku *s = sudoku_new(MAX_SIZE);
    s->board[0][0] = 5;
    s->board[2][2] = 6;
    s->board[4][4] = 1;
    s->board[6][6] = 3;
    s->board[8][8] = 4;

    sudoku_solve(s);

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%d ", s->board[i][j]);
        }
        printf("\n");
    }

    return 0;
}