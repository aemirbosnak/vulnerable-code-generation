//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: grateful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

int main() {
    // Initialize the game board
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                                {0, 0, 0},
                                {0, 0, 0}};

    // Seed the random number generator
    srand(time(NULL));

    // Determine the player who moves first
    int player = rand() % 2 + 1;

    // Game loop
    while (!boardFull(board) && !gameOver(board, player)) {
        // Get the player's move
        int move = getMove(board, player);

        // Place the player's mark on the board
        board[move / BOARD_SIZE][move % BOARD_SIZE] = player;

        // Switch to the next player
        player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // Check if the game is over
    if (gameOver(board, player)) {
        printf("Player %d won!", player);
    } else {
        printf("It's a draw!");
    }

    return 0;
}

// Check if the game board is full
int boardFull(int **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

// Check if the game is over
int gameOver(int **board, int player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j][0] == player && board[j][1] == player && board[j][2] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    // If all else fails, it's a draw
    return 0;
}

// Get the player's move
int getMove(int **board, int player) {
    // Get a random move
    int move = rand() % (BOARD_SIZE * BOARD_SIZE);

    // If the move is valid, return it
    if (board[move / BOARD_SIZE][move % BOARD_SIZE] == 0) {
        return move;
    } else {
        // Otherwise, try again
        return getMove(board, player);
    }
}