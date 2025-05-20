//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void initializeBoard(int **board) {
    board = (int**)malloc(sizeof(int*) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (int*)malloc(sizeof(int) * BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

int checkWin(int **board, int player) {
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
    int **board;
    initializeBoard(&board);

    int player = 1;
    int move = 0;

    // Game loop
    while (!checkWin(board, player) && move < 9) {
        // Get move
        move = getRandomMove(board);

        // Make move
        board[move / BOARD_SIZE][move % BOARD_SIZE] = player;

        // Switch player
        player *= -1;
    }

    // Game over
    if (checkWin(board, player) == 1) {
        printf("Player %d won!", player);
    } else {
        printf("It's a draw!");
    }

    return 0;
}

int getRandomMove(int **board) {
    // Calculate number of available moves
    int moves = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                moves++;
            }
        }
    }

    // Randomly select a move
    srand(time(NULL));
    return rand() % moves;
}