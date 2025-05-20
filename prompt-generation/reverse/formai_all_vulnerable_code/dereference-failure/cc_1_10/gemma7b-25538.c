//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

void solveSudoku(int **board) {
    for (int r = 0; r < MAX; r++) {
        for (int c = 0; c < MAX; c++) {
            if (board[r][c] == 0) {
                for (int n = 1; n <= MAX; n++) {
                    if (isSafe(board, r, c, n)) {
                        board[r][c] = n;
                        solveSudoku(board);
                        board[r][c] = 0;
                    }
                }
            }
        }
    }
}

int isSafe(int **board, int r, int c, int n) {
    for (int i = 0; i < MAX; i++) {
        if (board[r][i] == n) return 0;
        if (board[i][c] == n) return 0;
    }
    return 1;
}

int main() {
    int **board = (int **)malloc(MAX * MAX * sizeof(int));
    for (int i = 0; i < MAX; i++) {
        board[i] = (int *)malloc(MAX * sizeof(int));
        for (int j = 0; j < MAX; j++) {
            board[i][j] = 0;
        }
    }

    board[0][0] = 5;
    board[0][1] = 3;
    board[0][2] = 4;
    board[1][0] = 6;
    board[1][1] = 8;
    board[1][2] = 2;
    board[2][0] = 1;
    board[2][1] = 9;
    board[2][2] = 7;

    solveSudoku(board);

    for (int r = 0; r < MAX; r++) {
        for (int c = 0; c < MAX; c++) {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    free(board);

    return 0;
}