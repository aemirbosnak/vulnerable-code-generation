//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 9

typedef struct Sudoku_board {
    int **board;
    int size;
    int **solution;
} Sudoku_board;

Sudoku_board *sudoku_board_init(int size) {
    Sudoku_board *board = malloc(sizeof(Sudoku_board));
    board->size = size;
    board->board = malloc(size * size * sizeof(int));
    board->solution = malloc(size * size * sizeof(int));
    return board;
}

void sudoku_board_fill(Sudoku_board *board) {
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            board->board[i][j] = 0;
        }
    }
}

int sudoku_board_is_valid(Sudoku_board *board) {
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            if (board->board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void sudoku_board_solve(Sudoku_board *board) {
    if (sudoku_board_is_valid(board)) {
        return;
    }
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            if (board->board[i][j] == 0) {
                for (int k = 1; k <= board->size; k++) {
                    if (sudoku_board_is_valid(board) && board->board[i][j] != k) {
                        board->board[i][j] = k;
                        sudoku_board_solve(board);
                        board->board[i][j] = 0;
                    }
                }
            }
        }
    }
}

int main() {
    Sudoku_board *board = sudoku_board_init(9);
    sudoku_board_fill(board);
    sudoku_board_solve(board);

    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            printf("%d ", board->solution[i][j]);
        }
        printf("\n");
    }

    free(board->board);
    free(board->solution);
    free(board);

    return 0;
}