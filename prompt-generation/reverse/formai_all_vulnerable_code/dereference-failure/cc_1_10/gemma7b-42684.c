//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY_SPOT '-'

void initBoard(char **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = malloc(BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_SPOT;
        }
    }
}

int isBoardFull(char **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY_SPOT) {
                return 0;
            }
        }
    }
    return 1;
}

int isPlayerWin(char **board, char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

int main() {
    char **board;
    char player = PLAYER_X;
    int gameWon = 0;

    initBoard(&board);

    while (!gameWon && !isBoardFull(board)) {
        // Get the move
        int move = rand() % 9;

        // Place the move
        board[move / BOARD_SIZE][move % BOARD_SIZE] = player;

        // Check if the player won
        gameWon = isPlayerWin(board, player);

        // If the player won, switch to the other player
        if (gameWon) {
            player = PLAYER_O;
        } else {
            // Otherwise, switch to the next move
            player = PLAYER_X;
        }
    }

    // Print the winner or draw
    if (gameWon) {
        printf("The winner is: %c\n", player);
    } else {
        printf("It's a draw.\n");
    }

    return 0;
}