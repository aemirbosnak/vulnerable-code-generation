//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_SLOT -1
#define PLAYER_X 1
#define PLAYER_O 2

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void initializeBoard(int** board) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            board[r][c] = EMPTY_SLOT;
        }
    }
}

int isBoardFull(int** board) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (board[r][c] == EMPTY_SLOT) {
                return 0;
            }
        }
    }
    return 1;
}

int checkWin(int** board, int player) {
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (board[r][0] == player && board[r][1] == player && board[r][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (board[0][c] == player && board[1][c] == player && board[2][c] == player) {
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
    int** board = (int**)malloc(BOARD_SIZE * sizeof(int*));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (int*)malloc(BOARD_SIZE * sizeof(int));
    }

    initializeBoard(board);

    int player = PLAYER_X;
    int gameWon = 0;

    // Game loop
    while (!gameWon && !isBoardFull(board)) {
        int moveX = rand() % BOARD_SIZE;
        int moveY = rand() % BOARD_SIZE;

        if (board[moveX][moveY] == EMPTY_SLOT) {
            board[moveX][moveY] = player;

            if (checkWin(board, player) == 1) {
                gameWon = 1;
            }
        }
    }

    // Game over
    if (gameWon) {
        printf("Player %d won!", player);
    } else {
        printf("It's a draw!");
    }

    return 0;
}