//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void initBoard(int **board) {
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

void playGame(int **board) {
    int player = 1;
    int move = 0;

    initBoard(board);

    while (!isBoardFull(board) && !checkWin(board, player)) {
        move = rand() % 9;

        if (board[move / BOARD_SIZE][move % BOARD_SIZE] == 0) {
            board[move / BOARD_SIZE][move % BOARD_SIZE] = player;
            player *= -1;
        }
    }

    if (checkWin(board, player) == 1) {
        printf("You win!");
    } else {
        printf("Draw!");
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];

    playGame(board);

    return 0;
}