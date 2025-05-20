//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

typedef struct Sudoku {
    int **board;
    int size;
} Sudoku;

Sudoku* sudoku_create(int size) {
    Sudoku* s = malloc(sizeof(Sudoku));
    s->board = malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        s->board[i] = malloc(sizeof(int) * size);
    }
    s->size = size;
    return s;
}

void sudoku_solve(Sudoku* s) {
    for (int r = 0; r < s->size; r++) {
        for (int c = 0; c < s->size; c++) {
            if (s->board[r][c] == 0) {
                for (int i = 0; i < s->size; i++) {
                    for (int j = 0; j < s->size; j++) {
                        if (s->board[i][j] != 0 && i != r && j != c) {
                            int box_i = (r / 3) * 3 + (i / 3);
                            int box_j = (c / 3) * 3 + (j / 3);
                            if (s->board[i][j] == s->board[r][c] && box_i == box_j) {
                                s->board[r][c] = s->board[i][j];
                                sudoku_solve(s);
                                s->board[r][c] = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return;
}

int main() {
    Sudoku* s = sudoku_create(MAX_SIZE);
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

    for (int r = 0; r < MAX_SIZE; r++) {
        for (int c = 0; c < MAX_SIZE; c++) {
            printf("%d ", s->board[r][c]);
        }
        printf("\n");
    }

    return 0;
}