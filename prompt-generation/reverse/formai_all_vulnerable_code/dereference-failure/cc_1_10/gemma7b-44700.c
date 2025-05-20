//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3
#define MOVE_SIZE 2

typedef struct Board {
    int **board;
    int nextMove;
} Board;

Board *initializeBoard() {
    Board *board = malloc(sizeof(Board));
    board->board = malloc(sizeof(int *) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[i] = malloc(sizeof(int) * BOARD_SIZE);
    }
    board->nextMove = 1;
    return board;
}

void makeMove(Board *board, int row, int col) {
    if (board->board[row][col] != 0) {
        return;
    }
    board->board[row][col] = board->nextMove;
    board->nextMove++;
}

int checkWin(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
            return 1;
        }
    }

    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
            return 1;
        }
    }

    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return 1;
    }

    return 0;
}

int main() {
    Board *board = initializeBoard();
    makeMove(board, 1, 1);
    makeMove(board, 2, 2);
    makeMove(board, 0, 0);
    makeMove(board, 1, 0);
    makeMove(board, 2, 0);

    if (checkWin(board) == 1) {
        printf("Player won!");
    } else {
        printf("Draw!");
    }

    return 0;
}