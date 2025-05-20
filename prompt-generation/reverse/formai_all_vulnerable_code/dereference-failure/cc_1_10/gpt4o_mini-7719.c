//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

char board[SIZE][SIZE];

void initializeBoard() {
    const char* pieces = "rnbqkp";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == 0) {
                board[i][j] = pieces[j];
            } else if (i == 1) {
                board[i][j] = 'p';  // pawn
            } else if (i == 6) {
                board[i][j] = 'P';  // Pawn
            } else if (i == 7) {
                board[i][j] = pieces[j] - 32;  // Uppercase for white pieces
            } else {
                board[i][j] = '.';  // Empty square
            }
        }
    }
}

void printBoard() {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int startX, int startY, int endX, int endY) {
    // Basic bounds checking
    if (endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE) return 0;
    // Check if moving to an empty space or capturing opponent's piece
    if (board[endX][endY] == '.' || (board[startX][startY] < 'a' && board[endX][endY] >= 'a')) {
        return 1;
    }
    return 0;
}

void makeMove(int startX, int startY, int endX, int endY) {
    board[endX][endY] = board[startX][startY];
    board[startX][startY] = '.';
}

void parseMove(char *move, int *startX, int *startY, int *endX, int *endY) {
    *startY = move[0] - 'a';
    *startX = 8 - (move[1] - '0');
    *endY = move[2] - 'a';
    *endX = 8 - (move[3] - '0');
}

int main() {
    char move[5];
    int startX, startY, endX, endY;
    initializeBoard();
    
    while (1) {
        printBoard();
        printf("Enter your move (e.g., e2e4): ");
        scanf("%4s", move);
        parseMove(move, &startX, &startY, &endX, &endY);
        
        if (isValidMove(startX, startY, endX, endY)) {
            makeMove(startX, startY, endX, endY);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}