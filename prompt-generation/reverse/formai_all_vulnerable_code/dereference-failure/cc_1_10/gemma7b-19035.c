//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

// Game board structure
typedef struct GameBoard {
    int board[BOARD_SIZE][BOARD_SIZE];
    int currentPlayer;
    int winner;
} GameBoard;

// Function to initialize the game board
void initializeGameBoard(GameBoard *board) {
    board->currentPlayer = PLAYER_X;
    board->winner = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }
}

// Function to place a piece on the board
void placePiece(GameBoard *board, int x, int y) {
    if (board->board[x][y] != 0) {
        return;
    }
    board->board[x][y] = board->currentPlayer;
}

// Function to check if the player has won
int hasPlayerWon(GameBoard *board, int player) {
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

// Function to check if the board is full
int isBoardFull(GameBoard *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

// Main game loop
int main() {
    GameBoard board;
    initializeGameBoard(&board);

    // Play until someone wins or the board is full
    while (!hasPlayerWon(&board, board.currentPlayer) && !isBoardFull(&board)) {
        // Get the player's move
        int x, y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);

        // Place the piece on the board
        placePiece(&board, x, y);

        // Switch to the next player
        board.currentPlayer = (board.currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // Check if the player has won or the board is full
    if (hasPlayerWon(&board, board.currentPlayer)) {
        printf("Congratulations! You have won!");
    } else if (isBoardFull(&board)) {
        printf("It's a draw!");
    } else {
        printf("An error has occurred!");
    }

    return 0;
}