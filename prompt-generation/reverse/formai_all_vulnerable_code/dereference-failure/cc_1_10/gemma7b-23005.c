//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

typedef struct Sudoku {
    int **board;
    int size;
} Sudoku;

Sudoku* sudoku_init(int size) {
    Sudoku* s = malloc(sizeof(Sudoku));
    s->board = malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        s->board[i] = malloc(sizeof(int) * size);
    }
    s->size = size;
    return s;
}

void sudoku_solve(Sudoku* s) {
    for (int i = 0; i < s->size; i++) {
        for (int j = 0; j < s->size; j++) {
            if (s->board[i][j] == 0) {
                for (int k = 0; k < s->size; k++) {
                    if (s->board[k][j] != 0 && s->board[i][k] != 0) {
                        if (s->board[k][j] == s->board[i][k]) {
                            s->board[i][j] = s->board[k][j];
                            sudoku_solve(s);
                            s->board[i][j] = 0;
                        }
                    }
                }
            }
        }
    }
    if (sudoku_is_solved(s)) {
        printf("Solved Sudoku!\n");
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

int sudoku_is_solved(Sudoku* s) {
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
    Sudoku* s = sudoku_init(9);
    s->board[0][0] = 5;
    s->board[0][1] = 3;
    s->board[0][2] = 0;
    s->board[0][3] = 0;
    s->board[0][4] = 0;
    s->board[0][5] = 0;
    s->board[0][6] = 0;
    s->board[0][7] = 0;
    s->board[0][8] = 0;
    sudoku_solve(s);
    return 0;
}