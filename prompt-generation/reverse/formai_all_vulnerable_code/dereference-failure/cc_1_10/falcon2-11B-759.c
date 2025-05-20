//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int currentPlayer;
    int turn;
} GameBoard;

void printBoard(GameBoard *board) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board->board[i][j]);
        }
        printf("\n");
    }
}

void makeMove(GameBoard *board, int row, int col, char direction) {
    // Check if the move is valid
    if (board->board[row][col]!= '.') {
        return;
    }

    // Make the move
    switch (direction) {
        case 'L':
            board->board[row][col] = 'X';
            break;
        case 'R':
            board->board[row][col] = 'O';
            break;
        default:
            return;
    }

    // Change the player's turn
    board->currentPlayer ^= 1;
    board->turn += 1;
}

int main() {
    GameBoard board;
    int row, col, direction;
    char move;

    while (1) {
        printBoard(&board);
        printf("Player %d's turn.\n", board.currentPlayer);
        printf("Enter row, col, and direction (L or R): ");
        scanf("%d %d %c", &row, &col, &move);
        makeMove(&board, row, col, move);
    }

    return 0;
}