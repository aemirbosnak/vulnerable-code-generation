//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define N 9

typedef struct Sudoku {
    int **board;
    int **visited;
    int **candidates;
} Sudoku;

Sudoku* sudoku_new() {
    Sudoku* s = malloc(sizeof(Sudoku));
    s->board = malloc(N * N * sizeof(int));
    s->visited = malloc(N * N * sizeof(int));
    s->candidates = malloc(N * N * sizeof(int));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            s->board[i][j] = 0;
            s->visited[i][j] = 0;
            s->candidates[i][j] = 9;
        }
    }

    return s;
}

void sudoku_solve(Sudoku* s) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (s->board[i][j] == 0 && s->visited[i][j] == 0) {
                for (int k = 1; k <= 9; k++) {
                    if (sudoku_valid(s, i, j, k) && s->candidates[i][j] >= k) {
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

    if (sudoku_complete(s)) {
        printf("Solution:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", s->board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }
}

int sudoku_valid(Sudoku* s, int i, int j, int k) {
    // Valid row
    for (int l = 0; l < N; l++) {
        if (s->board[i][l] == k) {
            return 0;
        }
    }

    // Valid column
    for (int m = 0; m < N; m++) {
        if (s->board[m][j] == k) {
            return 0;
        }
    }

    // Valid 3x3 box
    int x = i / 3;
    int y = j / 3;
    for (int n = 0; n < 3; n++) {
        for (int m = 0; m < 3; m++) {
            if (s->board[x + n][y + m] == k) {
                return 0;
            }
        }
    }

    return 1;
}

int sudoku_complete(Sudoku* s) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (s->board[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    Sudoku* s = sudoku_new();
    sudoku_solve(s);

    return 0;
}