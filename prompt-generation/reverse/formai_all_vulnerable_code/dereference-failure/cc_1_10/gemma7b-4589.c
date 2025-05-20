//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: enthusiastic
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct GameBoard {
    int **board;
    int currentPlayer;
    int winner;
} GameBoard;

GameBoard *initializeGameBoard() {
    GameBoard *board = malloc(sizeof(GameBoard));
    board->board = malloc(sizeof(int *) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[i] = malloc(sizeof(int) * BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }
    board->currentPlayer = 1;
    board->winner = 0;
    return board;
}

void makeMove(GameBoard *board, int row, int col) {
    if (board->board[row][col] != 0) {
        return;
    }
    board->board[row][col] = board->currentPlayer;
    board->currentPlayer = (board->currentPlayer == 1) ? 2 : 1;
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

    // If all cells are occupied and there is no winner, it's a draw
    return 0;
}

int main() {
    GameBoard *board = initializeGameBoard();

    // Play the game
    makeMove(board, 0, 0);
    makeMove(board, 1, 1);
    makeMove(board, 2, 2);
    makeMove(board, 0, 1);
    makeMove(board, 1, 0);

    // Check if there is a winner or draw
    int winner = checkWin(board);

    // Print the winner or draw
    if (winner) {
        printf("Winner: Player %d\n", winner);
    } else {
        printf("Draw!\n");
    }

    return 0;
}