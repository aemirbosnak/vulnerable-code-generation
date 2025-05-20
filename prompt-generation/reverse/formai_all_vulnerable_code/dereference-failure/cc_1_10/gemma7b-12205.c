//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define SUDO_SIZE 9

typedef struct Sudoku {
    int **data;
    int **visited;
    int **candidates;
} Sudoku;

Sudoku *sudoku_new() {
    Sudoku *s = malloc(sizeof(Sudoku));
    s->data = malloc(sizeof(int *) * SUDO_SIZE);
    s->visited = malloc(sizeof(int *) * SUDO_SIZE);
    s->candidates = malloc(sizeof(int *) * SUDO_SIZE);
    for (int i = 0; i < SUDO_SIZE; i++) {
        s->data[i] = malloc(sizeof(int) * SUDO_SIZE);
        s->visited[i] = malloc(sizeof(int) * SUDO_SIZE);
        s->candidates[i] = malloc(sizeof(int) * SUDO_SIZE);
    }
    return s;
}

void sudoku_free(Sudoku *s) {
    for (int i = 0; i < SUDO_SIZE; i++) {
        free(s->data[i]);
        free(s->visited[i]);
        free(s->candidates[i]);
    }
    free(s->data);
    free(s->visited);
    free(s->candidates);
    free(s);
}

int sudoku_solve(Sudoku *s) {
    if (sudoku_is_solved(s)) {
        return 1;
    }
    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            if (s->visited[i][j] || s->data[i][j] != 0) {
                continue;
            }
            for (int k = 1; k <= SUDO_SIZE; k++) {
                if (sudoku_is_valid(s, i, j, k)) {
                    s->data[i][j] = k;
                    s->visited[i][j] = 1;
                    if (sudoku_solve(s) == 1) {
                        return 1;
                    }
                    s->data[i][j] = 0;
                    s->visited[i][j] = 0;
                }
            }
        }
    }
    return 0;
}

int sudoku_is_solved(Sudoku *s) {
    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            if (s->data[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int sudoku_is_valid(Sudoku *s, int i, int j, int k) {
    // Row validation
    for (int l = 0; l < SUDO_SIZE; l++) {
        if (s->data[i][l] == k) {
            return 0;
        }
    }

    // Column validation
    for (int m = 0; m < SUDO_SIZE; m++) {
        if (s->data[m][j] == k) {
            return 0;
        }
    }

    // Block validation
    int block_i = (i / 3) * 3;
    int block_j = (j / 3) * 3;
    for (int n = block_i; n < block_i + 3; n++) {
        for (int o = block_j; o < block_j + 3; o++) {
            if (s->data[n][o] == k) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    Sudoku *s = sudoku_new();
    s->data[0][0] = 5;
    s->data[0][1] = 3;
    s->data[0][2] = 0;
    s->data[1][0] = 6;
    s->data[1][1] = 0;
    s->data[1][2] = 0;
    s->data[2][0] = 0;
    s->data[2][1] = 0;
    s->data[2][2] = 0;

    sudoku_solve(s);

    for (int i = 0; i < SUDO_SIZE; i++) {
        for (int j = 0; j < SUDO_SIZE; j++) {
            printf("%d ", s->data[i][j]);
        }
        printf("\n");
    }

    sudoku_free(s);

    return 0;
}