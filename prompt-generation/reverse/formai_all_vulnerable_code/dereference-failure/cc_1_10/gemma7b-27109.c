//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Cell {
    int row;
    int col;
    char state;
} Cell;

void initBoard(Cell **board) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            board[r][c].row = r;
            board[r][c].col = c;
            board[r][c].state = 'N';
        }
    }
}

int checkWin(Cell **board, char player) {
    // Rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (board[r][0].state == player && board[r][1].state == player && board[r][2].state == player) {
            return 1;
        }
    }

    // Columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (board[0][c].state == player && board[1][c].state == player && board[2][c].state == player) {
            return 1;
        }
    }

    // Diagonals
    if (board[0][0].state == player && board[1][1].state == player && board[2][2].state == player) {
        return 1;
    }

    if (board[0][2].state == player && board[1][1].state == player && board[2][0].state == player) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));

    Cell **board = (Cell **)malloc(BOARD_SIZE * sizeof(Cell *));
    initBoard(board);

    char player = 'X';
    int gameWon = 0;

    // Game loop
    while (!gameWon) {
        // Get the move
        int move = rand() % 9;

        // Place the move
        board[move / BOARD_SIZE][move % BOARD_SIZE].state = player;

        // Check if the player won
        gameWon = checkWin(board, player);

        // If the player won, they get a trophy
        if (gameWon) {
            printf("Congratulations! You won!\n");
        }

        // Switch to the next player
        player = (player == 'X') ? 'O' : 'X';
    }

    // Free the memory
    free(board);

    return 0;
}