//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOARD_SIZE 10

typedef struct Cell {
    int x;
    int y;
    char state;
} Cell;

Cell **board;

void initializeBoard() {
    board = malloc(MAX_BOARD_SIZE * MAX_BOARD_SIZE * sizeof(Cell));
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            board[i][j].x = i;
            board[i][j].y = j;
            board[i][j].state = 'O';
        }
    }
}

void displayBoard() {
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            printf("%c ", board[i][j].state);
        }
        printf("\n");
    }
}

void placePiece(char piece, int x, int y) {
    if (board[x][y].state == 'O') {
        return;
    }
    board[x][y].state = piece;
}

int checkWin(char piece) {
    // Check rows
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            if (board[i][j].state == piece && board[i][j].x == board[i][0].x) {
                return 1;
            }
        }
    }

    // Check columns
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            if (board[i][j].state == piece && board[i][j].y == board[0][j].y) {
                return 1;
            }
        }
    }

    // Check diagonals
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            if (board[i][j].state == piece && board[i][j].x == board[0][0].x && board[i][j].y == board[0][0].y) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    initializeBoard();
    displayBoard();

    char currentPiece = 'X';
    int gameWon = 0;

    // Game loop
    while (!gameWon) {
        int x, y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);

        placePiece(currentPiece, x, y);

        displayBoard();

        gameWon = checkWin(currentPiece);

        if (gameWon) {
            printf("You won!");
        } else {
            currentPiece = 'O';
        }
    }

    return 0;
}