//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x;
    int y;
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

int isPlayerWon(int **board, int player) {
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
    int **board = (int**)malloc(BOARD_SIZE * sizeof(int*));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (int*)malloc(BOARD_SIZE * sizeof(int));
    }

    initializeBoard(board);

    int player = 1;
    int gameWon = 0;

    // Game loop
    while (!gameWon && !isBoardFull(board)) {
        // Get the move
        int moveX = rand() % BOARD_SIZE;
        int moveY = rand() % BOARD_SIZE;

        // If the move is valid, make it
        if (board[moveX][moveY] == 0) {
            board[moveX][moveY] = player;

            // Check if the player has won
            gameWon = isPlayerWon(board, player);
        }
    }

    // Game over
    if (gameWon) {
        printf("Player %d won!", player);
    } else {
        printf("It's a draw!");
    }

    // Free the memory
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}