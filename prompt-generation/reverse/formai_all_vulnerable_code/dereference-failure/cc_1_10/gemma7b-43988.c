//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 9

typedef struct SudokuBoard {
    int **board;
    int size;
} SudokuBoard;

SudokuBoard *createBoard(int size) {
    SudokuBoard *board = malloc(sizeof(SudokuBoard));
    board->board = malloc(size * size * sizeof(int));
    board->size = size;
    return board;
}

void generateSudoku(SudokuBoard *board) {
    srand(time(NULL));
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            board->board[i][j] = rand() % MAX + 1;
        }
    }
}

int isSafe(SudokuBoard *board, int i, int j, int num) {
    for (int r = 0; r < board->size; r++) {
        if (board->board[r][j] == num) return 0;
    }

    for (int c = 0; c < board->size; c++) {
        if (board->board[i][c] == num) return 0;
    }

    int box_i = (i / 3) * 3;
    int box_j = (j / 3) * 3;

    for (int r = box_i; r < box_i + 3; r++) {
        for (int c = box_j; c < box_j + 3; c++) {
            if (board->board[r][c] == num) return 0;
        }
    }

    return 1;
}

void solveSudoku(SudokuBoard *board) {
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            if (board->board[i][j] == 0) {
                for (int num = 1; num <= MAX; num++) {
                    if (isSafe(board, i, j, num)) {
                        board->board[i][j] = num;
                        solveSudoku(board);
                        board->board[i][j] = 0;
                    }
                }
            }
        }
    }
}

int main() {
    SudokuBoard *board = createBoard(9);
    generateSudoku(board);
    solveSudoku(board);

    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            printf("%d ", board->board[i][j]);
        }
        printf("\n");
    }

    return 0;
}