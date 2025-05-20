//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Function to initialize the game board
void initializeBoard(char **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to place a piece on the game board
void placePiece(char **board, int row, int col, char player) {
    board[row][col] = player;
}

// Function to check if the player has won
int hasWon(char **board, char player) {
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

    // If all else fails, the player has not won
    return 0;
}

// Function to generate a random move
int generateMove(char **board) {
    int row = rand() % BOARD_SIZE;
    int col = rand() % BOARD_SIZE;

    // If the move is valid, return the move
    if (board[row][col] == ' ') {
        return row * BOARD_SIZE + col;
    } else {
        // Otherwise, generate a new move
        return generateMove(board);
    }
}

int main() {
    char **board = (char**)malloc(BOARD_SIZE * sizeof(char *));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (char *)malloc(BOARD_SIZE * sizeof(char));
    }

    initializeBoard(board);

    // Game loop
    char player = PLAYER_X;
    while (!hasWon(board, player) && board[0][0] != ' ') {
        int move = generateMove(board);
        placePiece(board, move / BOARD_SIZE, move % BOARD_SIZE, player);

        player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // Check if the player has won or it's a draw
    if (hasWon(board, player)) {
        printf("Congratulations, %c, you won!", player);
    } else {
        printf("It's a draw!");
    }

    // Free the memory allocated for the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}