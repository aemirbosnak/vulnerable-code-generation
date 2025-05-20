//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: shocked
#include <stdlib.h>
#include <stdio.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **board;
    int turn;
} Board;

void initBoard(Board *board) {
    board->board = malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[i] = malloc(BOARD_SIZE * sizeof(int));
    }
    board->turn = 0;
}

int isBoardFull(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int checkWin(Board *board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
            return 1;
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return 1;
    }

    // If all else fails, it's a draw
    return 2;
}

int main() {
    Board board;
    initBoard(&board);

    // Game loop
    while (!isBoardFull(&board) && checkWin(&board) == 0) {
        // Get the player's move
        int moveX, moveY;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &moveX, &moveY);

        // Place the mark
        board.board[moveX][moveY] = board.turn;

        // Increment the turn
        board.turn++;
    }

    // Game over
    if (checkWin(&board) == 1) {
        printf("You win!");
    } else if (checkWin(&board) == 2) {
        printf("It's a draw!");
    } else {
        printf("Error!");
    }

    return 0;
}