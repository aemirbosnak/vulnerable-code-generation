//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define PLAYER1 'X'
#define PLAYER2 'O'

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 != 0) {
                if (i < 3) {
                    board[i][j] = PLAYER1;  // Player 1 pieces
                } else if (i > 4) {
                    board[i][j] = PLAYER2;  // Player 2 pieces
                } else {
                    board[i][j] = EMPTY; // Empty squares
                }
            } else {
                board[i][j] = EMPTY; // No pieces on these squares
            }
        }
    }
}

void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\nCheckers Board:\n");
    printf("  A B C D E F G H\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isValidMove(char board[BOARD_SIZE][BOARD_SIZE], int startX, int startY, int endX, int endY, char player) {
    int dir = (player == PLAYER1) ? 1 : -1;
    if (endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE || board[endX][endY] != EMPTY) {
        return 0; // Invalid move out of bounds or not empty
    }
    if ((endX - startX == dir) && (abs(endY - startY) == 1)) {
        return 1; // Simple move
    }
    if ((endX - startX == 2 * dir) && (abs(endY - startY) == 2)) {
        // Check if jumping over opponent
        int midX = (startX + endX) / 2;
        int midY = (startY + endY) / 2;
        if (board[midX][midY] != EMPTY && board[midX][midY] != player) {
            return 1; // Jump move
        }
    }
    return 0; // Invalid move
}

void makeMove(char board[BOARD_SIZE][BOARD_SIZE], int startX, int startY, int endX, int endY) {
    board[endX][endY] = board[startX][startY]; // Move the piece
    board[startX][startY] = EMPTY; // Empty the old space

    // Check if jump move, if so, remove the jumped piece
    if (abs(endX - startX) == 2) {
        int midX = (startX + endX) / 2;
        int midY = (startY + endY) / 2;
        board[midX][midY] = EMPTY; // Remove jumped piece
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);

    char currentPlayer = PLAYER1;
    int startX, startY, endX, endY;
    char columnStart, columnEnd;
;
    while (1) {
        displayBoard(board);
        printf("Player %c's turn! (Enter your move like A1 A2): ", currentPlayer);
        scanf(" %c%d %c%d", &columnStart, &startX, &columnEnd, &endX);

        startY = columnStart - 'A'; // Convert 'A'..'H' to 0..7
        endY = columnEnd - 'A'; // Convert 'A'..'H' to 0..7

        if (startX < 1 || startX > 8 || endX < 1 || endX > 8 || 
            !isValidMove(board, startX - 1, startY, endX - 1, endY, currentPlayer)) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        makeMove(board, startX - 1, startY, endX - 1, endY);
        
        // Switch players
        currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
    }

    return 0;
}