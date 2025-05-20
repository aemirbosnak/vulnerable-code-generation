//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a Tic Tac Toe board
typedef struct Board {
    int **board;
    int size;
    int turn;
} Board;

// Function to initialize a Tic Tac Toe board
Board *initBoard(int size) {
    Board *board = malloc(sizeof(Board));
    board->board = malloc(size * size * sizeof(int));
    board->size = size;
    board->turn = 0;

    for (int i = 0; i < size * size; i++) {
        board->board[i] = 0;
    }

    return board;
}

// Function to make a move on the Tic Tac Toe board
void makeMove(Board *board, int row, int col, int player) {
    if (board->board[row * board->size + col] == 0) {
        board->board[row * board->size + col] = player;
        board->turn++;
    }
}

// Function to check if the player has won
int hasWon(Board *board, int player) {
    // Check rows
    for (int i = 0; i < board->size; i++) {
        if (board->board[i * board->size] == player &&
            board->board[i * board->size + 1] == player &&
            board->board[i * board->size + 2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < board->size; j++) {
        if (board->board[j] == player &&
            board->board[j + board->size] == player &&
            board->board[j + 2 * board->size] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board->board[0] == player && board->board[board->size + 1] == player && board->board[board->size * 2 + 2] == player) {
        return 1;
    }

    if (board->board[board->size - 1] == player && board->board[board->size - 2] == player && board->board[board->size - 3] == player) {
        return 1;
    }

    // If all moves have been made and there is no winner, it is a draw
    return 2;
}

// Function to play the Tic Tac Toe game
int main() {
    // Initialize the board
    Board *board = initBoard(3);

    // Play the game
    int gameWon = 0;
    while (!gameWon) {
        // Get the player's move
        int row, col;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &col);

        // Make the move
        makeMove(board, row, col, 1);

        // Check if the player has won
        gameWon = hasWon(board, 1);

        // If the player has won, print the winner
        if (gameWon == 1) {
            printf("Winner: Player 1\n");
        }

        // If there is no winner, print the next turn
        else {
            printf("Next turn: Player 2\n");
        }
    }

    // Free the board
    free(board->board);
    free(board);

    return 0;
}