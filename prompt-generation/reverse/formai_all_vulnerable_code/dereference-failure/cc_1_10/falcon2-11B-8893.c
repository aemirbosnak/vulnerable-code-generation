//Falcon2-11B DATASET v1.0 Category: Chess AI ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to make a move
void makeMove(int board[8][8], int row, int col, int player) {
    board[row][col] = player;
    printf("Player %d makes a move at (%d, %d)\n", player, row, col);
}

// Function to print the board
void printBoard(int board[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to play the game
void playGame(int board[8][8], int player) {
    int gameOver = 0;
    while (!gameOver) {
        printBoard(board);
        printf("Player %d's turn\n", player);
        int row, col, move;
        scanf("%d %d %d", &row, &col, &move);
        makeMove(board, row, col, move);
        if (checkIfGameOver(board, player)) {
            gameOver = 1;
        } else {
            player = (player == 1)? 2 : 1;
        }
    }
    printf("Game over\n");
}

// Function to check if game is over
int checkIfGameOver(int board[8][8], int player) {
    int winner = 0;
    for (int i = 0; i < 8; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            winner = 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            winner = 1;
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            winner = 1;
        }
        if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
            winner = 1;
        }
        if (board[0][7] == player && board[1][6] == player && board[2][5] == player) {
            winner = 1;
        }
        if (board[7][0] == player && board[6][1] == player && board[5][2] == player) {
            winner = 1;
        }
        if (board[7][7] == player && board[6][6] == player && board[5][5] == player) {
            winner = 1;
        }
        if (board[7][0] == player && board[6][1] == player && board[5][2] == player) {
            winner = 1;
        }
    }
    return winner;
}

int main() {
    int board[8][8];
    srand(time(0));
    int player = 1;
    playGame(board, player);
    return 0;
}