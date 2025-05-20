//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

// Define the board structure
typedef struct Board {
    int **board;
    int turn;
    int winner;
} Board;

// Function to initialize the board
void initBoard(Board *board) {
    board->board = (int **)malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[i] = (int *)malloc(BOARD_SIZE * sizeof(int));
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }
    board->turn = 0;
    board->winner = 0;
}

// Function to place a mark on the board
void placeMark(Board *board, int row, int col, int player) {
    board->board[row][col] = player;
    board->turn++;
}

// Function to check if the player has won
int checkWin(Board *board, int player) {
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

    if (board->turn == BOARD_SIZE * BOARD_SIZE) {
        return 2;
    }

    return 0;
}

int main() {
    Board board;
    initBoard(&board);

    // Play the game
    while (!checkWin(&board, 2)) {
        // Get the player's move
        int row, col;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &col);

        // Place the mark
        placeMark(&board, row, col, 1);

        // Check if the player has won
        if (checkWin(&board, 1) == 1) {
            printf("You won!");
        }
    }

    // Game over
    printf("Game over!");

    return 0;
}