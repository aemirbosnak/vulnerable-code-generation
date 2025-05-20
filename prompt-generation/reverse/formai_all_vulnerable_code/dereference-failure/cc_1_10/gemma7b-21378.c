//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 9

typedef struct sudoku_board {
    int board[MAX][MAX];
    int solve_status;
} sudoku_board;

sudoku_board* sudoku_board_init() {
    sudoku_board* board = (sudoku_board*)malloc(sizeof(sudoku_board));
    board->solve_status = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            board->board[i][j] = 0;
        }
    }
    return board;
}

int sudoku_board_solve(sudoku_board* board) {
    if (board->solve_status) {
        return 1;
    }
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (board->board[i][j] == 0) {
                for (int n = 1; n <= MAX; n++) {
                    if (sudoku_board_valid(board, i, j, n)) {
                        board->board[i][j] = n;
                        if (sudoku_board_solve(board) == 1) {
                            return 1;
                        } else {
                            board->board[i][j] = 0;
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}

int sudoku_board_valid(sudoku_board* board, int i, int j, int n) {
    // Row validation
    for (int r = 0; r < MAX; r++) {
        if (board->board[r][j] == n) {
            return 0;
        }
    }

    // Column validation
    for (int c = 0; c < MAX; c++) {
        if (board->board[i][c] == n) {
            return 0;
        }
    }

    // 3x3 box validation
    int box_i = i / 3;
    int box_j = j / 3;
    for (int r = box_i * 3; r < box_i * 3 + 3; r++) {
        for (int c = box_j * 3; c < box_j * 3 + 3; c++) {
            if (board->board[r][c] == n) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    sudoku_board* board = sudoku_board_init();
    sudoku_board_solve(board);

    // Print the solution
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", board->board[i][j]);
        }
        printf("\n");
    }

    return 0;
}