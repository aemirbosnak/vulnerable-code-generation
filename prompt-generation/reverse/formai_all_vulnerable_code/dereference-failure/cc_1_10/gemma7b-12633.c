//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY_SPACE '_'

typedef struct GameBoard {
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer;
    int gameWon;
} GameBoard;

void initializeGameBoard(GameBoard *board) {
    board->currentPlayer = PLAYER_X;
    board->gameWon = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = EMPTY_SPACE;
        }
    }
}

int isBoardFull(GameBoard *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == EMPTY_SPACE) {
                return 0;
            }
        }
    }
    return 1;
}

int hasPlayerWon(GameBoard *board, char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == player && board->board[1][i] == player && board->board[2][i] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == player && board->board[j][1] == player && board->board[j][2] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board->board[0][0] == player && board->board[1][1] == player && board->board[2][2] == player) {
        return 1;
    }

    if (board->board[0][2] == player && board->board[1][1] == player && board->board[2][0] == player) {
        return 1;
    }

    return 0;
}

void makeMove(GameBoard *board, int x, int y) {
    if (board->board[x][y] != EMPTY_SPACE) {
        return;
    }

    board->board[x][y] = board->currentPlayer;

    if (hasPlayerWon(board, board->currentPlayer) || isBoardFull(board)) {
        board->gameWon = 1;
    } else {
        board->currentPlayer = (board->currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }
}

int main() {
    GameBoard board;
    initializeGameBoard(&board);

    // Game loop
    while (!board.gameWon) {
        // Get player's move
        int x, y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);

        // Make move
        makeMove(&board, x, y);
    }

    // Game over
    if (board.gameWon) {
        printf("Congratulations! You won!");
    } else {
        printf("It's a draw!");
    }

    return 0;
}