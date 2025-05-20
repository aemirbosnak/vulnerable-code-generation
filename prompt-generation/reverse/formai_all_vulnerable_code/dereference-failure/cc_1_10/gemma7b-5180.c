//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUDO_SIZE 9

typedef struct Sudoku {
    int **board;
    int **visited;
    int **candidates;
} Sudoku;

Sudoku *sudoku_new() {
    Sudoku *s = malloc(sizeof(Sudoku));
    s->board = malloc(sizeof(int *) * SUDO_SIZE);
    s->visited = malloc(sizeof(int *) * SUDO_SIZE);
    s->candidates = malloc(sizeof(int *) * SUDO_SIZE);

    for (int i = 0; i < SUDO_SIZE; i++) {
        s->board[i] = malloc(sizeof(int) * SUDO_SIZE);
        s->visited[i] = malloc(sizeof(int) * SUDO_SIZE);
        s->candidates[i] = malloc(sizeof(int) * SUDO_SIZE);
    }

    return s;
}

void sudoku_free(Sudoku *s) {
    for (int i = 0; i < SUDO_SIZE; i++) {
        free(s->board[i]);
        free(s->visited[i]);
        free(s->candidates[i]);
    }

    free(s->board);
    free(s->visited);
    free(s->candidates);
    free(s);
}

void sudoku_solve(Sudoku *s) {
    if (sudoku_is_solved(s)) {
        return;
    }

    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            if (s->visited[i][j] || s->board[i][j] != 0) {
                continue;
            }

            for (int k = 1; k <= SUDO_SIZE; k++) {
                if (sudoku_is_valid(s, i, j, k)) {
                    s->board[i][j] = k;
                    s->visited[i][j] = 1;
                    sudoku_solve(s);
                    s->board[i][j] = 0;
                    s->visited[i][j] = 0;
                }
            }
        }
    }

    return;
}

int sudoku_is_solved(Sudoku *s) {
    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            if (s->board[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int sudoku_is_valid(Sudoku *s, int i, int j, int k) {
    // Row validation
    for (int l = 0; l < SUDO_SIZE; l++) {
        if (s->board[i][l] == k) {
            return 0;
        }
    }

    // Column validation
    for (int m = 0; m < SUDO_SIZE; m++) {
        if (s->board[m][j] == k) {
            return 0;
        }
    }

    // 3x3 box validation
    int box_i = i / 3;
    int box_j = j / 3;
    for (int n = box_i * 3; n < box_i * 3 + 3; n++) {
        for (int o = box_j * 3; o < box_j * 3 + 3; o++) {
            if (s->board[n][o] == k) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    Sudoku *s = sudoku_new();

    // Generate a Sudoku puzzle
    s->board[0][0] = 5;
    s->board[0][1] = 3;
    s->board[0][2] = 0;
    s->board[1][0] = 6;
    s->board[1][1] = 0;
    s->board[1][2] = 0;
    s->board[2][0] = 0;
    s->board[2][1] = 0;
    s->board[2][2] = 0;

    // Solve the Sudoku puzzle
    sudoku_solve(s);

    // Print the solution
    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            printf("%d ", s->board[i][j]);
        }
        printf("\n");
    }

    sudoku_free(s);

    return 0;
}