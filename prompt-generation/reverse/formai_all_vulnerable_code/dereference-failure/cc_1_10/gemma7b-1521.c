//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

typedef struct Sudoku {
    int **board;
    int **visited;
    int **candidates;
} Sudoku;

Sudoku *sudoku_new() {
    Sudoku *s = malloc(sizeof(Sudoku));
    s->board = malloc(MAX * MAX * sizeof(int));
    s->visited = malloc(MAX * MAX * sizeof(int));
    s->candidates = malloc(MAX * MAX * sizeof(int));
    return s;
}

void sudoku_init(Sudoku *s) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            s->board[i][j] = 0;
            s->visited[i][j] = 0;
            s->candidates[i][j] = 0;
        }
    }
}

void sudoku_solve(Sudoku *s) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (s->board[i][j] == 0 && s->visited[i][j] == 0) {
                for (int k = 1; k <= MAX; k++) {
                    if (sudoku_valid(s, i, j, k) && s->candidates[i][j] == k) {
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
    // Row validation
    for (int r = 0; r < MAX; r++) {
        if (s->board[r][j] == k) {
            return 0;
        }
    }

    // Column validation
    for (int c = 0; c < MAX; c++) {
        if (s->board[i][c] == k) {
            return 0;
        }
    }

    // Subgrid validation
    int x = i / 3;
    int y = j / 3;
    for (int r = x * 3; r < x * 3 + 3; r++) {
        for (int c = y * 3; c < y * 3 + 3; c++) {
            if (s->board[r][c] == k) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    Sudoku *s = sudoku_new();
    sudoku_init(s);

    // Fill the Sudoku board with initial values
    s->board[0][0] = 5;
    s->board[0][1] = 3;
    s->board[0][2] = 0;
    s->board[1][0] = 6;
    s->board[1][1] = 0;
    s->board[1][2] = 0;
    s->board[2][0] = 9;
    s->board[2][1] = 0;
    s->board[2][2] = 0;

    sudoku_solve(s);

    // Print the Sudoku solution
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", s->board[i][j]);
        }
        printf("\n");
    }

    return 0;
}