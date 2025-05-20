//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

typedef struct Sudoku {
    int **board;
    int **visited;
    int **candidates;
} Sudoku;

Sudoku *sudoku_create(int size) {
    Sudoku *s = malloc(sizeof(Sudoku));
    s->board = malloc(size * size * sizeof(int));
    s->visited = malloc(size * size * sizeof(int));
    s->candidates = malloc(size * size * sizeof(int));

    return s;
}

void sudoku_init(Sudoku *s) {
    int i, j;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            s->board[i][j] = 0;
            s->visited[i][j] = 0;
            s->candidates[i][j] = 0;
        }
    }
}

void sudoku_solve(Sudoku *s) {
    int i, j, k;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            if (s->board[i][j] == 0 && s->visited[i][j] == 0) {
                for (k = 1; k <= MAX; k++) {
                    if (sudoku_valid(s, i, j, k) && s->candidates[i][j] & k) {
                        s->board[i][j] = k;
                        s->visited[i][j] = 1;
                        sudoku_solve(s);
                        s->board[i][j] = 0;
                        s->visited[i][j] = 0;
                    }
                }
            }
        }
    }
}

int sudoku_valid(Sudoku *s, int i, int j, int k) {
    int r, c, b;

    // Row validation
    for (r = 0; r < MAX; r++) {
        if (s->board[r][j] == k) {
            return 0;
        }
    }

    // Column validation
    for (c = 0; c < MAX; c++) {
        if (s->board[i][c] == k) {
            return 0;
        }
    }

    // Box validation
    for (b = 0; b < MAX; b++) {
        if (s->board[b][b] == k) {
            return 0;
        }
    }

    return 1;
}

int main() {
    Sudoku *s = sudoku_create(9);
    sudoku_init(s);

    // Solve the Sudoku
    sudoku_solve(s);

    // Print the solution
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", s->board[i][j]);
        }
        printf("\n");
    }

    return 0;
}