//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define SUDO_SIZE 9

typedef struct Sudoku {
    int **board;
    int solved;
} Sudoku;

Sudoku *sudoku_create(void) {
    Sudoku *s = malloc(sizeof(Sudoku));
    s->board = malloc(sizeof(int *) * SUDO_SIZE);
    for (int i = 0; i < SUDO_SIZE; i++) {
        s->board[i] = malloc(sizeof(int) * SUDO_SIZE);
    }
    s->solved = 0;
    return s;
}

void sudoku_solve(Sudoku *s) {
    if (s->solved) {
        return;
    }
    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            if (s->board[i][j] == 0) {
                for (int k = 0; k < SUDO_SIZE; k++) {
                    if (s->board[i][k] == s->board[k][j] && s->board[i][k] != 0) {
                        s->board[i][j] = s->board[k][j];
                        sudoku_solve(s);
                        s->board[i][j] = 0;
                    }
                }
            }
        }
    }
    s->solved = 1;
}

int main() {
    Sudoku *s = sudoku_create();
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

    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            printf("%d ", s->board[i][j]);
        }
        printf("\n");
    }

    return 0;
}