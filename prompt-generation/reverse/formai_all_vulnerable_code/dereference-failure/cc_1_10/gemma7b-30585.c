//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define SUDO_SIZE 9

typedef struct Sudoku {
    int **board;
    int **visited;
    int **candidates;
} Sudoku;

Sudoku* sudoku_create(void) {
    Sudoku* s = malloc(sizeof(Sudoku));
    s->board = malloc(sizeof(int*) * SUDO_SIZE);
    for (int i = 0; i < SUDO_SIZE; i++) {
        s->board[i] = malloc(sizeof(int) * SUDO_SIZE);
    }
    s->visited = malloc(sizeof(int*) * SUDO_SIZE);
    for (int i = 0; i < SUDO_SIZE; i++) {
        s->visited[i] = malloc(sizeof(int) * SUDO_SIZE);
    }
    s->candidates = malloc(sizeof(int*) * SUDO_SIZE);
    for (int i = 0; i < SUDO_SIZE; i++) {
        s->candidates[i] = malloc(sizeof(int) * SUDO_SIZE);
    }
    return s;
}

void sudoku_solve(Sudoku* s) {
    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            if (s->board[i][j] == 0 && !s->visited[i][j]) {
                for (int k = 0; k < SUDO_SIZE; k++) {
                    if (s->candidates[i][k] && !s->visited[k][j]) {
                        s->board[i][j] = s->candidates[i][k];
                        s->visited[i][j] = 1;
                        sudoku_solve(s);
                        s->board[i][j] = 0;
                        s->visited[i][j] = 0;
                    }
                }
            }
        }
    }

    if (sudoku_is_valid(s)) {
        printf("Solution:\n");
        for (int i = 0; i < SUDO_SIZE; i++) {
            for (int j = 0; j < SUDO_SIZE; j++) {
                printf("%d ", s->board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }
}

int sudoku_is_valid(Sudoku* s) {
    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            if (s->board[i][j] == 0) {
                return 0;
            }
            int row_sum = 0;
            for (int k = 0; k < SUDO_SIZE; k++) {
                if (s->board[k][j] != 0) {
                    row_sum++;
                }
            }
            if (row_sum != 9) {
                return 0;
            }

            int col_sum = 0;
            for (int l = 0; l < SUDO_SIZE; l++) {
                if (s->board[i][l] != 0) {
                    col_sum++;
                }
            }
            if (col_sum != 9) {
                return 0;
            }

            int box_sum = 0;
            int box_start = (i / 3) * 3;
            int box_end = box_start + 2;
            for (int m = box_start; m < box_end; m++) {
                for (int n = box_start; n < box_end; n++) {
                    if (s->board[m][n] != 0) {
                        box_sum++;
                    }
                }
            }
            if (box_sum != 9) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    Sudoku* s = sudoku_create();
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