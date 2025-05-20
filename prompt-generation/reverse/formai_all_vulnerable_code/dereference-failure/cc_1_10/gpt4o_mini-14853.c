//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define EMPTY ' '
#define WHITE 'W'
#define BLACK 'B'

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 != 0) {
                if (i < 3) {
                    board[i][j] = BLACK;
                } else if (i > 4) {
                    board[i][j] = WHITE;
                } else {
                    board[i][j] = EMPTY;
                }
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int startRow, int startCol, int endRow, int endCol, char board[SIZE][SIZE], char player) {
    if (endRow < 0 || endRow >= SIZE || endCol < 0 || endCol >= SIZE || board[endRow][endCol] != EMPTY) {
        return 0; // Out of bounds or not empty
    }
    if (player == WHITE && startRow < endRow) {
        return 0; // White can only move down
    }
    if (player == BLACK && startRow > endRow) {
        return 0; // Black can only move up
    }
    if (abs(startRow - endRow) == 1 && abs(startCol - endCol) == 1) {
        return 1; // Simple move
    }
    if (abs(startRow - endRow) == 2 && abs(startCol - endCol) == 2) {
        int middleRow = (startRow + endRow) / 2;
        int middleCol = (startCol + endCol) / 2;
        if (board[middleRow][middleCol] != EMPTY && board[middleRow][middleCol] != player) {
            return 1; // Jump move
        }
    }
    return 0; // Invalid move
}

void makeMove(int startRow, int startCol, int endRow, int endCol, char board[SIZE][SIZE]) {
    board[endRow][endCol] = board[startRow][startCol];
    board[startRow][startCol] = EMPTY;
    if (abs(startRow - endRow) == 2) { // Jump
        int middleRow = (startRow + endRow) / 2;
        int middleCol = (startCol + endCol) / 2;
        board[middleRow][middleCol] = EMPTY; // Remove the jumped piece
    }
}

int main() {
    char board[SIZE][SIZE];
    char currentPlayer = WHITE;
    char input[5];
    int startRow, startCol, endRow, endCol;

    initializeBoard(board);

    while (1) {
        printBoard(board);
        printf("%s's turn (Enter move in format 'A1 B2'): ", (currentPlayer == WHITE) ? "White" : "Black");
        fgets(input, sizeof(input), stdin);

        startCol = input[0] - 'A';
        startRow = input[1] - '1';
        endCol = input[3] - 'A';
        endRow = input[4] - '1';

        if (!isValidMove(startRow, startCol, endRow, endCol, board, currentPlayer)) {
            printf("Invalid move! Please try again.\n");
            continue;
        }

        makeMove(startRow, startCol, endRow, endCol, board);

        currentPlayer = (currentPlayer == WHITE) ? BLACK : WHITE; // Switch players
    }

    return 0;
}