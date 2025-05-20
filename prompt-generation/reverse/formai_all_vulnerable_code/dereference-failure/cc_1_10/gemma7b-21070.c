//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void initializeBoard(int **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = malloc(BOARD_SIZE * sizeof(int));
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void placeMark(int **board, int row, int col, int player) {
    board[row][col] = player;
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
    int **board = NULL;
    initializeBoard(&board);

    // Game logic
    placeMark(board, 1, 1, 2);
    placeMark(board, 0, 1, 1);
    placeMark(board, 2, 0, 2);
    placeMark(board, 1, 2, 1);
    placeMark(board, 0, 0, 2);

    if (checkWin(board, 1) == 1) {
        printf("Player 1 won!");
    } else if (checkWin(board, 2) == 1) {
        printf("Player 2 won!");
    } else {
        printf("Draw!");
    }

    return 0;
}