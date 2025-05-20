//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUDO_SIZE 9

typedef struct Sudoku {
    int **board;
    int **visited;
    int **candidates;
} Sudoku;

Sudoku* sudoku_new() {
    Sudoku* s = malloc(sizeof(Sudoku));
    s->board = malloc(SUDO_SIZE * sizeof(int*));
    s->visited = malloc(SUDO_SIZE * sizeof(int*));
    s->candidates = malloc(SUDO_SIZE * sizeof(int*));

    for (int i = 0; i < SUDO_SIZE; i++) {
        s->board[i] = malloc(SUDO_SIZE * sizeof(int));
        s->visited[i] = malloc(SUDO_SIZE * sizeof(int));
        s->candidates[i] = malloc(SUDO_SIZE * sizeof(int));
    }

    return s;
}

void sudoku_free(Sudoku* s) {
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

int sudoku_solve(Sudoku* s) {
    if (sudoku_is_solved(s)) {
        return 1;
    }

    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            if (s->visited[i][j] == 0 && s->candidates[i][j] != 0) {
                s->board[i][j] = s->candidates[i][j];
                s->visited[i][j] = 1;

                if (sudoku_solve(s) == 1) {
                    return 1;
                }

                s->board[i][j] = 0;
                s->visited[i][j] = 0;
            }
        }
    }

    return 0;
}

int sudoku_is_solved(Sudoku* s) {
    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            if (s->board[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    Sudoku* s = sudoku_new();

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