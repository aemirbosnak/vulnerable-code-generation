//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY_SPOT '-'

// Define the board structure
typedef struct Board {
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer;
    int gameStatus;
} Board;

// Function to initialize the board
void initializeBoard(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = EMPTY_SPOT;
        }
    }

    board->currentPlayer = PLAYER_X;
    board->gameStatus = 0;
}

// Function to place a piece on the board
void placePiece(Board *board, int row, int col) {
    if (board->board[row][col] != EMPTY_SPOT) {
        return;
    }

    board->board[row][col] = board->currentPlayer;
}

// Function to check if the player has won
int checkWin(Board *board, char player) {
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
int isBoardFull(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == EMPTY_SPOT) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to play the game
void playGame(Board *board) {
    int moveMade = 0;

    // Loop until someone wins or the board is full
    while (!checkWin(board, board->currentPlayer) && !isBoardFull(board)) {
        // Get the player's move
        int row, col;
        printf("Enter row (1-3): ");
        scanf("%d", &row);

        printf("Enter column (1-3): ");
        scanf("%d", &col);

        // Place the piece on the board
        placePiece(board, row, col);

        // Alternate the current player
        board->currentPlayer = (board->currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;

        moveMade++;
    }

    // Check if the game has ended
    if (checkWin(board, board->currentPlayer) || isBoardFull(board)) {
        printf("Game Over!\n");

        // Print the board
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("%c ", board->board[i][j]);
            }

            printf("\n");
        }

        // Print the number of moves made
        printf("Number of moves made: %d\n", moveMade);
    }
}

int main() {
    Board board;
    initializeBoard(&board);
    playGame(&board);

    return 0;
}