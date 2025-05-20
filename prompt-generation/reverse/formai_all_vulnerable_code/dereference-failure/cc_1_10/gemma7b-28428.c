//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void initBoard(int** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (int*)malloc(BOARD_SIZE * sizeof(int));
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

int isBoardFull(int** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int checkWin(int** board, int player) {
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
    int** board;
    initBoard(&board);

    // Seed the random number generator
    srand(time(NULL));

    // Player's turn
    int player = 1;

    // Game loop
    while (!isBoardFull(board) && !checkWin(board, player)) {
        // Get the move
        int move = rand() % 9;

        // Place the mark
        board[move / 3][move % 3] = player;

        // Switch player
        player = (player == 1) ? 2 : 1;
    }

    // Game over
    if (checkWin(board, player) == 1) {
        printf("Player %d won!", player);
    } else {
        printf("It's a draw!");
    }

    return 0;
}