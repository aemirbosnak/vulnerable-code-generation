//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOARD_SIZE 6

typedef struct Board {
    int **board;
    int turn;
    int winner;
} Board;

void initializeBoard(Board *board) {
    board->board = malloc(MAX_BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        board->board[i] = malloc(MAX_BOARD_SIZE * sizeof(int));
    }
    board->turn = 0;
    board->winner = -1;
}

void makeMove(Board *board, int x, int y) {
    if (board->board[x][y] != 0) {
        return;
    }
    board->board[x][y] = board->turn;
    board->turn = (board->turn == 0) ? 1 : 0;
}

int checkWin(Board *board) {
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            if (board->board[i][j] != board->winner) {
                continue;
            }
            if (i == 0) {
                return 1;
            } else if (i == MAX_BOARD_SIZE - 1) {
                return 2;
            } else if (j == 0) {
                return 3;
            } else if (j == MAX_BOARD_SIZE - 1) {
                return 4;
            }
        }
    }
    return -1;
}

int main() {
    Board board;
    initializeBoard(&board);

    makeMove(&board, 0, 0);
    makeMove(&board, 1, 0);
    makeMove(&board, 0, 1);
    makeMove(&board, 1, 1);
    makeMove(&board, 0, 2);
    makeMove(&board, 1, 2);

    if (checkWin(&board) == 0) {
        printf("Player 0 won!");
    } else if (checkWin(&board) == 1) {
        printf("Player 1 won!");
    } else {
        printf("It's a draw!");
    }

    return 0;
}