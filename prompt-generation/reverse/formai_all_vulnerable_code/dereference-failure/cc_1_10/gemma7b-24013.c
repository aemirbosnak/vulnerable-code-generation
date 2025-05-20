//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct GameBoard {
    int board[BOARD_SIZE][BOARD_SIZE];
    int currentPlayer;
    int isGameOver;
} GameBoard;

void initializeGameBoard(GameBoard *board) {
    board->currentPlayer = 1;
    board->isGameOver = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }
}

int checkWin(GameBoard *board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
            return board->board[0][i];
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
            return board->board[j][0];
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return board->board[0][0];
    }

    // If all cells are filled and no winner, it's a draw
    return 0;
}

void playTurn(GameBoard *board, int player) {
    int row, col;

    // Get the player's move
    printf("Enter row and column (1-3): ");
    scanf("%d %d", &row, &col);

    // Check if the move is valid
    if (board->board[row][col] != 0) {
        printf("Invalid move. Please try again.\n");
        return;
    }

    // Make the move
    board->board[row][col] = player;

    // Check if the player has won or if the game is over
    if (checkWin(board) == player) {
        printf("Congratulations! You have won!\n");
    } else if (checkWin(board) == 0) {
        printf("It's a draw.\n");
    } else {
        board->currentPlayer = (board->currentPlayer == 1) ? 2 : 1;
        printf("Next turn.\n");
    }
}

int main() {
    GameBoard board;
    initializeGameBoard(&board);

    // Play the game until someone wins or it's a draw
    while (!board.isGameOver) {
        playTurn(&board, board.currentPlayer);
    }

    return 0;
}