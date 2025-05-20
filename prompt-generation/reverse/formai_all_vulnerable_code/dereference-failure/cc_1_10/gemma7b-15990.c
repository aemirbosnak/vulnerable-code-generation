//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

typedef struct Sudoku_board {
    int **board;
    int size;
} Sudoku_board;

Sudoku_board *sudoku_board_init(int size) {
    Sudoku_board *board = malloc(sizeof(Sudoku_board));
    board->size = size;
    board->board = malloc(size * size * sizeof(int));
    for (int i = 0; i < size * size; i++) {
        board->board[i] = 0;
    }
    return board;
}

void sudoku_board_solve(Sudoku_board *board) {
    int size = board->size;
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (board->board[r * size + c] == 0) {
                for (int i = 0; i < size; i++) {
                    if (board->board[r * size + i] != 0 && board->board[i * size + c] != 0) {
                        if (board->board[r * size + i] == board->board[i * size + c]) {
                            board->board[r * size + c] = board->board[r * size + i];
                            sudoku_board_solve(board);
                            board->board[r * size + c] = 0;
                        }
                    }
                }
            }
        }
    }
    if (sudoku_board_is_solved(board)) {
        printf("Solved Sudoku!\n");
    } else {
        printf("No solution found.\n");
    }
}

int sudoku_board_is_solved(Sudoku_board *board) {
    int size = board->size;
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (board->board[r * size + c] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    Sudoku_board *board = sudoku_board_init(MAX_SIZE);
    board->board[0] = 5;
    board->board[3] = 3;
    board->board[6] = 4;
    board->board[8] = 2;
    board->board[1] = 9;
    board->board[5] = 7;
    board->board[8] = 6;
    sudoku_board_solve(board);
    return 0;
}