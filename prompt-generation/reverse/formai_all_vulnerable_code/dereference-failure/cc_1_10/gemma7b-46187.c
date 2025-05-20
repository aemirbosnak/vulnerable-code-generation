//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

typedef struct Sudoku {
    int **board;
    int **visited;
    int **candidates;
} Sudoku;

Sudoku *sudoku_create() {
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
            s->candidates[i][j] = 9;
        }
    }
}

void sudoku_solve(Sudoku *s) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (s->board[i][j] == 0 && s->visited[i][j] == 0) {
                for (int k = 0; k < MAX; k++) {
                    if (s->candidates[i][j] & (1 << k)) {
                        s->board[i][j] = k + 1;
                        s->visited[i][j] = 1;
                        sudoku_solve(s);
                        s->board[i][j] = 0;
                        s->visited[i][j] = 0;
                    }
                }
            }
        }
    }
    if (s->board[0][0] != 0) {
        printf("Solution:\n");
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                printf("%d ", s->board[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    Sudoku *s = sudoku_create();
    sudoku_init(s);
    sudoku_solve(s);
    return 0;
}