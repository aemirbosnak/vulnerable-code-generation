//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void initializeBoard(int **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

int isBoardFull(int **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int checkWin(int **board, int player) {
    // Horizontal win
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // Vertical win
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j][0] == player && board[j][1] == player && board[j][2] == player) {
            return 1;
        }
    }

    // Diagonal win
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    // Draw
    if (isBoardFull(board)) {
        return 2;
    }

    return 0;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);

    int player = 1;
    int gameWon = 0;

    // Simulate the game
    while (!gameWon) {
        // Get the player's move
        int moveX = rand() % BOARD_SIZE;
        int moveY = rand() % BOARD_SIZE;

        // Check if the move is valid
        if (board[moveX][moveY] != 0) {
            continue;
        }

        // Make the move
        board[moveX][moveY] = player;

        // Check if the player has won
        gameWon = checkWin(board, player);

        // Switch to the next player
        player = (player == 1) ? 2 : 1;
    }

    // Print the winner or draw
    if (gameWon) {
        printf("Player %d won!\n", player);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}