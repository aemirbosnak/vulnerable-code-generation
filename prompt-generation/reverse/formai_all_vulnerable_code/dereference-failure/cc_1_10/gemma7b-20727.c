//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

void sudoku_solve(int **board) {
    for (int r = 0; r < MAX; r++) {
        for (int c = 0; c < MAX; c++) {
            if (board[r][c] == 0) {
                for (int i = 0; i < MAX; i++) {
                    if (board[r][i] != 0 && board[i][c] != 0) {
                        if (board[r][i] == board[i][c] && board[r][i] != board[r][c]) {
                            board[r][c] = board[r][i];
                            sudoku_solve(board);
                            board[r][c] = 0;
                        }
                    }
                }
            }
        }
    }
    return;
}

int main() {
    int **board = (int **)malloc(MAX * MAX * sizeof(int));
    for (int i = 0; i < MAX; i++) {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Initialize the Sudoku board
    board[0][0] = 5;
    board[0][1] = 3;
    board[0][2] = 0;
    board[0][3] = 0;
    board[0][4] = 0;
    board[0][5] = 2;
    board[0][6] = 0;
    board[0][7] = 0;
    board[0][8] = 0;

    board[1][0] = 6;
    board[1][1] = 0;
    board[1][2] = 0;
    board[1][3] = 1;
    board[1][4] = 4;
    board[1][5] = 0;
    board[1][6] = 0;
    board[1][7] = 0;
    board[1][8] = 0;

    board[2][0] = 0;
    board[2][1] = 9;
    board[2][2] = 0;
    board[2][3] = 0;
    board[2][4] = 0;
    board[2][5] = 0;
    board[2][6] = 0;
    board[2][7] = 0;
    board[2][8] = 0;

    sudoku_solve(board);

    // Print the solved Sudoku board
    for (int r = 0; r < MAX; r++) {
        for (int c = 0; c < MAX; c++) {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    free(board);
    return 0;
}