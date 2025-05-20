//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

typedef struct Puzzle {
    int **board;
    int solved;
} Puzzle;

Puzzle *createPuzzle(int size) {
    Puzzle *p = malloc(sizeof(Puzzle));
    p->board = malloc(size * size * sizeof(int));
    p->solved = 0;
    return p;
}

int isSafe(Puzzle *p, int x, int y) {
    int i, j, k;
    for (i = 0; i < MAX; i++) {
        if (p->board[x][i] == p->board[x][y] || p->board[i][y] == p->board[x][y]) {
            return 0;
        }
    }
    return 1;
}

void solvePuzzle(Puzzle *p) {
    int x, y;
    for (x = 0; x < MAX; x++) {
        for (y = 0; y < MAX; y++) {
            if (p->board[x][y] == 0 && isSafe(p, x, y)) {
                p->board[x][y] = 1;
                solvePuzzle(p);
                p->board[x][y] = 0;
            }
        }
    }
    if (p->solved) {
        return;
    }
    p->solved = 1;
    printf("Solved Sudoku:\n");
    for (x = 0; x < MAX; x++) {
        for (y = 0; y < MAX; y++) {
            printf("%d ", p->board[x][y]);
        }
        printf("\n");
    }
}

int main() {
    Puzzle *p = createPuzzle(MAX);
    p->board[0][0] = 5;
    p->board[0][2] = 6;
    p->board[1][0] = 1;
    p->board[2][2] = 8;
    p->board[3][0] = 3;
    p->board[4][1] = 4;
    p->board[5][2] = 9;
    p->board[6][0] = 2;
    p->board[7][1] = 7;
    p->board[8][0] = 4;
    p->board[8][2] = 3;
    solvePuzzle(p);
    return 0;
}