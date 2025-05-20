//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 9

typedef struct SudokuBoard {
    int **board;
    int **visited;
    int **candidates;
} SudokuBoard;

SudokuBoard *SudokuBoard_new() {
    SudokuBoard *board = malloc(sizeof(SudokuBoard));
    board->board = malloc(sizeof(int *) * BOARD_SIZE);
    board->visited = malloc(sizeof(int *) * BOARD_SIZE);
    board->candidates = malloc(sizeof(int *) * BOARD_SIZE);

    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[i] = malloc(sizeof(int) * BOARD_SIZE);
        board->visited[i] = malloc(sizeof(int) * BOARD_SIZE);
        board->candidates[i] = malloc(sizeof(int) * BOARD_SIZE);
    }

    return board;
}

void SudokuBoard_free(SudokuBoard *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board->board[i]);
        free(board->visited[i]);
        free(board->candidates[i]);
    }

    free(board->board);
    free(board->visited);
    free(board->candidates);
    free(board);
}

void SudokuBoard_set(SudokuBoard *board, int x, int y, int value) {
    board->board[x][y] = value;
    board->visited[x][y] = 1;
    board->candidates[x][y] = 0;
}

int SudokuBoard_get(SudokuBoard *board, int x, int y) {
    return board->board[x][y];
}

int SudokuBoard_available(SudokuBoard *board, int x, int y) {
    return board->candidates[x][y] != 0;
}

int SudokuBoard_solve(SudokuBoard *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (SudokuBoard_available(board, i, j)) {
                SudokuBoard_set(board, i, j, 1);
                if (SudokuBoard_solve(board) == 1) {
                    return 1;
                }
                SudokuBoard_set(board, i, j, 0);
            }
        }
    }

    return 0;
}

int main() {
    SudokuBoard *board = SudokuBoard_new();

    SudokuBoard_set(board, 0, 0, 5);
    SudokuBoard_set(board, 0, 1, 3);
    SudokuBoard_set(board, 0, 2, 0);
    SudokuBoard_set(board, 1, 0, 6);
    SudokuBoard_set(board, 1, 1, 0);
    SudokuBoard_set(board, 1, 2, 0);
    SudokuBoard_set(board, 2, 0, 0);
    SudokuBoard_set(board, 2, 1, 0);
    SudokuBoard_set(board, 2, 2, 4);

    SudokuBoard_solve(board);

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", SudokuBoard_get(board, i, j));
        }
        printf("\n");
    }

    SudokuBoard_free(board);

    return 0;
}