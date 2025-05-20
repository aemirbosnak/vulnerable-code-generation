//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOARD_SIZE 3

typedef struct GameBoard {
    int **board;
    int currentPlayer;
    int winner;
} GameBoard;

GameBoard* initializeGameBoard() {
    GameBoard* gameBoard = malloc(sizeof(GameBoard));
    gameBoard->board = malloc(MAX_BOARD_SIZE * MAX_BOARD_SIZE * sizeof(int));
    gameBoard->currentPlayer = 1;
    gameBoard->winner = 0;

    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            gameBoard->board[i][j] = 0;
        }
    }

    return gameBoard;
}

void makeMove(GameBoard* gameBoard, int x, int y) {
    if (gameBoard->board[x][y] != 0) {
        return;
    }

    gameBoard->board[x][y] = gameBoard->currentPlayer;

    if (checkWin(gameBoard, gameBoard->currentPlayer) == 1) {
        gameBoard->winner = gameBoard->currentPlayer;
    } else if (checkDraw(gameBoard) == 1) {
        gameBoard->winner = 2;
    } else {
        gameBoard->currentPlayer = (gameBoard->currentPlayer == 1) ? 2 : 1;
    }
}

int checkWin(GameBoard* gameBoard, int player) {
    // Check rows
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        if (gameBoard->board[0][i] == player && gameBoard->board[1][i] == player && gameBoard->board[2][i] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < MAX_BOARD_SIZE; j++) {
        if (gameBoard->board[j][0] == player && gameBoard->board[j][1] == player && gameBoard->board[j][2] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (gameBoard->board[0][0] == player && gameBoard->board[1][1] == player && gameBoard->board[2][2] == player) {
        return 1;
    } else if (gameBoard->board[0][2] == player && gameBoard->board[1][1] == player && gameBoard->board[2][0] == player) {
        return 1;
    }

    return 0;
}

int checkDraw(GameBoard* gameBoard) {
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            if (gameBoard->board[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    GameBoard* gameBoard = initializeGameBoard();

    makeMove(gameBoard, 1, 1);
    makeMove(gameBoard, 2, 0);
    makeMove(gameBoard, 1, 0);
    makeMove(gameBoard, 2, 2);
    makeMove(gameBoard, 1, 2);

    if (gameBoard->winner != 0) {
        printf("Winner: Player %d\n", gameBoard->winner);
    } else if (gameBoard->winner == 2) {
        printf("Draw\n");
    }

    return 0;
}