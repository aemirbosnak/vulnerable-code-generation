//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 9

typedef struct SudokuBoard {
    int **board;
    int size;
} SudokuBoard;

SudokuBoard *sudoku_board_init(int size) {
    SudokuBoard *board = malloc(sizeof(SudokuBoard));
    board->size = size;
    board->board = malloc(size * size * sizeof(int));
    return board;
}

void sudoku_board_set(SudokuBoard *board, int row, int col, int value) {
    board->board[row][col] = value;
}

int sudoku_board_get(SudokuBoard *board, int row, int col) {
    return board->board[row][col];
}

int sudoku_board_solve(SudokuBoard *board) {
    for (int row = 0; row < board->size; row++) {
        for (int col = 0; col < board->size; col++) {
            if (sudoku_board_get(board, row, col) == 0) {
                for (int num = 1; num <= board->size; num++) {
                    if (sudoku_board_valid(board, row, col, num)) {
                        sudoku_board_set(board, row, col, num);
                        if (sudoku_board_solve(board) == 1) {
                            return 1;
                        } else {
                            sudoku_board_set(board, row, col, 0);
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int sudoku_board_valid(SudokuBoard *board, int row, int col, int num) {
    // Check row validity
    for (int r = 0; r < board->size; r++) {
        if (sudoku_board_get(board, r, col) == num) {
            return 0;
        }
    }

    // Check column validity
    for (int c = 0; c < board->size; c++) {
        if (sudoku_board_get(board, row, c) == num) {
            return 0;
        }
    }

    // Check subgrid validity
    int subgrid_row = row / 3;
    int subgrid_col = col / 3;
    for (int r = subgrid_row * 3; r < subgrid_row * 3 + 3; r++) {
        for (int c = subgrid_col * 3; c < subgrid_col * 3 + 3; c++) {
            if (sudoku_board_get(board, r, c) == num) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    SudokuBoard *board = sudoku_board_init(BOARD_SIZE);
    sudoku_board_set(board, 0, 0, 5);
    sudoku_board_set(board, 0, 1, 3);
    sudoku_board_set(board, 0, 2, 0);
    sudoku_board_set(board, 1, 0, 6);
    sudoku_board_set(board, 1, 1, 0);
    sudoku_board_set(board, 1, 2, 0);
    sudoku_board_set(board, 2, 0, 0);
    sudoku_board_set(board, 2, 1, 0);
    sudoku_board_set(board, 2, 2, 0);

    sudoku_board_solve(board);

    for (int row = 0; row < board->size; row++) {
        for (int col = 0; col < board->size; col++) {
            printf("%d ", sudoku_board_get(board, row, col));
        }
        printf("\n");
    }

    return 0;
}