//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 8

void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
bool isValidMove(char board[SIZE][SIZE], int srcX, int srcY, int destX, int destY, char player);
bool movePiece(char board[SIZE][SIZE], int srcX, int srcY, int destX, int destY);
bool isKing(int x, char player);
void transformToKing(int x, int y, char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    printBoard(board);

    char currentPlayer = 'X'; // Player X starts first.
    int srcX, srcY, destX, destY;
    bool validMove;

    while (true) {
        printf("Player %c's turn. Enter source (x y) and destination (x y): ", currentPlayer);
        scanf("%d %d %d %d", &srcX, &srcY, &destX, &destY);

        validMove = movePiece(board, srcX, srcY, destX, destY);
        if (validMove) {
            printBoard(board);
            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }

    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    // Clear the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Place the initial pieces for player X and O
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i < 3 && (i + j) % 2 != 0) {
                board[i][j] = 'X';
            } else if (i > 4 && (i + j) % 2 != 0) {
                board[i][j] = 'O';
            }
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isValidMove(char board[SIZE][SIZE], int srcX, int srcY, int destX, int destY, char player) {
    // Check bounds
    if (srcX < 0 || srcX >= SIZE || srcY < 0 || srcY >= SIZE ||
        destX < 0 || destX >= SIZE || destY < 0 || destY >= SIZE) {
        return false;
    }

    // Check if source and destination are valid
    if (board[srcX][srcY] != player || board[destX][destY] != ' ') {
        return false;
    }

    // Calculate valid move distances
    int dx = destX - srcX;
    int dy = destY - srcY;

    // Check for normal piece movement
    if (abs(dx) == 1 && abs(dy) == 1) {
        return true; // Normal move of one step
    }
    // Check for capturing
    if (abs(dx) == 2 && abs(dy) == 2) {
        int midX = (srcX + destX) / 2;
        int midY = (srcY + destY) / 2;
        char opponentPiece = (player == 'X') ? 'O' : 'X';
        if (board[midX][midY] == opponentPiece) {
            return true; // Capture move
        }
    }
    return false; // Invalid move
}

bool movePiece(char board[SIZE][SIZE], int srcX, int srcY, int destX, int destY) {
    char player = board[srcX][srcY];

    if (isValidMove(board, srcX, srcY, destX, destY, player)) {
        // Perform the move
        board[destX][destY] = player;
        board[srcX][srcY] = ' ';

        // Check if it was a capture
        if (abs(destX - srcX) == 2) {
            int midX = (srcX + destX) / 2;
            int midY = (srcY + destY) / 2;
            board[midX][midY] = ' '; // Remove captured piece
        }

        // Transform to a king if it reaches the opposite side
        transformToKing(destX, destY, board);
        return true;
    }
    return false;
}

void transformToKing(int x, int y, char board[SIZE][SIZE]) {
    if (x == 0 && board[x][y] == 'X') {
        board[x][y] = 'K'; // X becomes a King
    }
    if (x == 7 && board[x][y] == 'O') {
        board[x][y] = 'k'; // O becomes a King
    }
}