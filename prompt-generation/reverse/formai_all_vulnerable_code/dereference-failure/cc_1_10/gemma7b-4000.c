//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

typedef struct Sudoku {
    int **board;
    int **mask;
    int **visited;
} Sudoku;

Sudoku *sudoku_init(int size) {
    Sudoku *s = (Sudoku *)malloc(sizeof(Sudoku));
    s->board = (int **)malloc(size * sizeof(int *));
    s->mask = (int **)malloc(size * sizeof(int *));
    s->visited = (int **)malloc(size * sizeof(int *));
    s->board[0] = (int *)malloc(size * size * sizeof(int));
    s->mask[0] = (int *)malloc(size * size * sizeof(int));
    s->visited[0] = (int *)malloc(size * size * sizeof(int));
    return s;
}

void sudoku_solve(Sudoku *s) {
    for (int r = 0; r < MAX; r++) {
        for (int c = 0; c < MAX; c++) {
            if (s->board[r][c] == 0 && s->mask[r][c] == 0 && s->visited[r][c] == 0) {
                for (int n = 0; n < MAX; n++) {
                    if (s->board[r][n] == s->board[n][c] && s->mask[r][n] == 0 && s->visited[r][n] == 0) {
                        s->visited[r][n] = 1;
                        s->board[r][c] = n + 1;
                        sudoku_solve(s);
                        s->board[r][c] = 0;
                        s->visited[r][n] = 0;
                    }
                }
            }
        }
    }
    return;
}

int main() {
    Sudoku *s = sudoku_init(MAX);
    s->board[0][0] = 5;
    s->board[0][1] = 3;
    s->board[0][2] = 0;
    s->board[1][0] = 6;
    s->board[1][1] = 0;
    s->board[1][2] = 0;
    s->board[2][0] = 0;
    s->board[2][1] = 9;
    s->board[2][2] = 1;
    sudoku_solve(s);
    printf("%d %d %d\n", s->board[0][2], s->board[1][1], s->board[2][0]);
    return 0;
}