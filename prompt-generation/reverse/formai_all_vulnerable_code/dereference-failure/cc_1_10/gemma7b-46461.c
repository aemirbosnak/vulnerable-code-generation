//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUDO_SIZE 9

typedef struct Sudoku_board {
    int **board;
    int size;
    int solved;
} Sudoku_board;

Sudoku_board *sudoku_board_init(int size) {
    Sudoku_board *board = malloc(sizeof(Sudoku_board));
    board->board = malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        board->board[i] = malloc(sizeof(int) * size);
    }
    board->size = size;
    board->solved = 0;
    return board;
}

void sudoku_board_solve(Sudoku_board *board) {
    if (board->solved) {
        return;
    }

    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            if (board->board[i][j] == 0) {
                for (int k = 0; k < board->size; k++) {
                    if (board->board[i][k] != 0 && board->board[k][j] != 0) {
                        if (board->board[i][j] == 0) {
                            board->board[i][j] = board->board[k][j] + 1;
                            sudoku_board_solve(board);
                            board->board[i][j] = 0;
                        }
                    }
                }
            }
        }
    }

    board->solved = 1;
}

int main() {
    Sudoku_board *board = sudoku_board_init(SUDO_SIZE);
    sudoku_board_solve(board);

    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            printf("%d ", board->board[i][j]);
        }
        printf("\n");
    }

    return 0;
}