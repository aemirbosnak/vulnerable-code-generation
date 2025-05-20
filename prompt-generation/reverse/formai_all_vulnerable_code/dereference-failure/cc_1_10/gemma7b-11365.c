//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 9

typedef struct Sudoku_board {
    int **data;
    int size;
} Sudoku_board;

Sudoku_board *sudoku_board_create(int size) {
    Sudoku_board *board = malloc(sizeof(Sudoku_board));
    board->size = size;
    board->data = malloc(size * size * sizeof(int));
    return board;
}

void sudoku_board_init(Sudoku_board *board) {
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            board->data[i][j] = 0;
        }
    }
}

int sudoku_board_is_valid(Sudoku_board *board) {
    for (int i = 0; i < board->size; i++) {
        int row_sum = 0;
        for (int j = 0; j < board->size; j++) {
            if (board->data[i][j] != 0) {
                row_sum++;
            }
        }
        if (row_sum != 9) {
            return 0;
        }
    }

    for (int j = 0; j < board->size; j++) {
        int column_sum = 0;
        for (int i = 0; i < board->size; i++) {
            if (board->data[i][j] != 0) {
                column_sum++;
            }
        }
        if (column_sum != 9) {
            return 0;
        }
    }

    for (int k = 0; k < 3; k++) {
        int box_sum = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board->data[i][j] != 0) {
                    box_sum++;
                }
            }
        }
        if (box_sum != 9) {
            return 0;
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
            if (board->data[i][j] == 0) {
                for (int n = 1; n <= board->size; n++) {
                    if (sudoku_board_is_valid(board) && board->data[i][j] != n) {
                        board->data[i][j] = n;
                        sudoku_board_solve(board);
                        board->data[i][j] = 0;
                    }
                }
            }
        }
    }
}

int main() {
    Sudoku_board *board = sudoku_board_create(BOARD_SIZE);
    sudoku_board_init(board);

    board->data[0][0] = 5;
    board->data[0][2] = 3;
    board->data[1][0] = 6;
    board->data[1][2] = 2;
    board->data[2][0] = 1;
    board->data[2][1] = 4;

    sudoku_board_solve(board);

    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            printf("%d ", board->data[i][j]);
        }
        printf("\n");
    }

    return 0;
}