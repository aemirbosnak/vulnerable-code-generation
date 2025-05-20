//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **board;
    int currentPlayer;
    int winner;
} Board;

void initializeBoard(Board *board) {
    board->board = (int **)malloc(sizeof(int *) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[i] = (int *)malloc(sizeof(int) * BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }
    board->currentPlayer = 1;
    board->winner = 0;
}

void placeMove(Board *board, int row, int col) {
    if (board->board[row][col] != 0) {
        return;
    }
    board->board[row][col] = board->currentPlayer;
    board->currentPlayer *= -1;
}

int checkWin(Board *board) {
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

    // If all cells are filled and there is no winner, it's a draw
    return 0;
}

int main() {
    Board board;
    initializeBoard(&board);

    // Play until there is a winner or a draw
    while (!checkWin(&board)) {
        // Get the player's move
        int row, col;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &col);

        // Place the move
        placeMove(&board, row, col);
    }

    // Check if there was a winner or a draw
    if (checkWin(&board) != 0) {
        printf("Winner: Player %d\n", checkWin(&board));
    } else {
        printf("It's a draw\n");
    }

    return 0;
}