//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

typedef struct sudoku_board {
    int **board;
    int size;
} sudoku_board;

sudoku_board *sudoku_init(int size) {
    sudoku_board *board = malloc(sizeof(sudoku_board));
    board->size = size;
    board->board = malloc(size * size * sizeof(int));
    for (int i = 0; i < size * size; i++) {
        board->board[i] = 0;
    }
    return board;
}

void sudoku_solve(sudoku_board *board) {
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            if (board->board[i][j] == 0) {
                for (int k = 0; k < board->size; k++) {
                    if (board->board[k][j] != 0 && board->board[i][k] != 0) {
                        if (board->board[k][j] == board->board[i][k]) {
                            board->board[i][j] = board->board[k][j];
                            sudoku_solve(board);
                            board->board[i][j] = 0;
                        }
                    }
                }
            }
        }
    }
    if (sudoku_check(board)) {
        printf("Solution:\n");
        for (int i = 0; i < board->size; i++) {
            for (int j = 0; j < board->size; j++) {
                printf("%d ", board->board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }
}

int sudoku_check(sudoku_board *board) {
    for (int i = 0; i < board->size; i++) {
        // Check rows
        for (int j = 0; j < board->size; j++) {
            int row_sum = 0;
            for (int k = 0; k < board->size; k++) {
                if (board->board[i][k] != 0) {
                    row_sum += board->board[i][k];
                }
            }
            if (row_sum != MAX) {
                return 0;
            }
        }

        // Check columns
        for (int j = 0; j < board->size; j++) {
            int column_sum = 0;
            for (int k = 0; k < board->size; k++) {
                if (board->board[k][j] != 0) {
                    column_sum += board->board[k][j];
                }
            }
            if (column_sum != MAX) {
                return 0;
            }
        }

        // Check 3x3 blocks
        for (int l = 0; l < board->size; l++) {
            int block_sum = 0;
            for (int m = 0; m < board->size; m++) {
                for (int n = 0; n < board->size; n++) {
                    if (board->board[l][m] != 0 && board->board[l][n] != 0) {
                        block_sum += board->board[l][n];
                    }
                }
            }
            if (block_sum != MAX) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    sudoku_board *board = sudoku_init(9);
    board->board[0][0] = 5;
    board->board[0][1] = 3;
    board->board[0][2] = 4;
    board->board[1][0] = 6;
    board->board[1][2] = 2;
    board->board[2][0] = 1;
    board->board[2][1] = 9;
    board->board[3][0] = 8;
    board->board[3][2] = 7;
    board->board[4][0] = 4;
    board->board[4][1] = 2;
    board->board[4][2] = 3;
    board->board[5][0] = 9;
    board->board[5][1] = 5;
    board->board[5][2] = 1;
    board->board[6][0] = 2;
    board->board[6][1] = 3;
    board->board[6][2] = 4;
    board->board[7][0] = 1;
    board->board[7][1] = 9;
    board->board[7][2] = 5;
    board->board[8][0] = 3;
    board->board[8][1] = 4;
    board->board[8][2] = 2;
    board->board[9][0] = 6;
    board->board[9][1] = 1;
    board->board[9][2] = 5;

    sudoku_solve(board);

    return 0;
}