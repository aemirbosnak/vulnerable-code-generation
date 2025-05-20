//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Cell {
    int row;
    int col;
    char value;
} Cell;

void initializeBoard(Cell **board) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j].row = i;
            board[i][j].col = j;
            board[i][j].value = ' ';
        }
    }
}

void printBoard(Cell **board) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j].value);
        }
        printf("\n");
    }
}

char checkWin(Cell **board, char player) {
    int i, j;
    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0].value == player && board[i][1].value == player && board[i][2].value == player) {
            return player;
        }
    }

    // Check columns
    for (j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j].value == player && board[1][j].value == player && board[2][j].value == player) {
            return player;
        }
    }

    // Check diagonals
    if (board[0][0].value == player && board[1][1].value == player && board[2][2].value == player) {
        return player;
    }

    if (board[0][2].value == player && board[1][1].value == player && board[2][0].value == player) {
        return player;
    }

    return 'N';
}

int main() {
    Cell **board = (Cell **)malloc(BOARD_SIZE * sizeof(Cell *));
    initializeBoard(board);

    printBoard(board);

    char winner = checkWin(board, 'X');

    if (winner == 'X') {
        printf("X won!");
    } else if (winner == 'O') {
        printf("O won!");
    } else {
        printf("It's a draw!");
    }

    return 0;
}