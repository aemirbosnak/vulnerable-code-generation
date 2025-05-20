//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 8

typedef enum { EMPTY, WHITE, BLACK } PieceType;

typedef struct {
    PieceType board[SIZE][SIZE];
} ChessBoard;

void initializeBoard(ChessBoard *cb) {
    // Initialize empty board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cb->board[i][j] = EMPTY;
        }
    }

    // Set up pieces (we'll have pawns and kings for simplicity)
    for (int j = 0; j < SIZE; j++) {
        cb->board[1][j] = WHITE;  // White pawns
        cb->board[6][j] = BLACK;  // Black pawns
    }
}

void printBoard(const ChessBoard *cb) {
    for (int i = SIZE - 1; i >= 0; i--) {
        for (int j = 0; j < SIZE; j++) {
            switch (cb->board[i][j]) {
                case EMPTY: printf(". "); break;
                case WHITE: printf("P "); break;
                case BLACK: printf("p "); break;
            }
        }
        printf("\n");
    }
}

bool isMoveLegal(ChessBoard *cb, int startX, int startY, int endX, int endY, PieceType player) {
    // Simple legal move check: not moving onto your own piece
    if (cb->board[endX][endY] == player) {
        return false;
    }
    
    // Forward movement for pawns
    if (player == WHITE) {
        if (startX == 1 && endX == 3 && startY == endY && cb->board[2][startY] == EMPTY && cb->board[endX][endY] == EMPTY) {
            return true; // double step
        } else if (endX - startX == 1 && startY == endY && cb->board[endX][endY] == EMPTY) {
            return true; // single step
        } else if (endX - startX == 1 && abs(startY - endY) == 1 && cb->board[endX][endY] == BLACK) {
            return true; // capture
        }
    } else if (player == BLACK) {
        if (startX == 6 && endX == 4 && startY == endY && cb->board[5][startY] == EMPTY && cb->board[endX][endY] == EMPTY) {
            return true; // double step
        } else if (startX - endX == 1 && startY == endY && cb->board[endX][endY] == EMPTY) {
            return true; // single step
        } else if (startX - endX == 1 && abs(startY - endY) == 1 && cb->board[endX][endY] == WHITE) {
            return true; // capture
        }
    }

    return false; // If no valid moves, it's illegal
}

void movePiece(ChessBoard *cb, int startX, int startY, int endX, int endY) {
    cb->board[endX][endY] = cb->board[startX][startY];
    cb->board[startX][startY] = EMPTY;
}

void playGame(ChessBoard *cb) {
    int startX, startY, endX, endY;
    PieceType player = WHITE;

    while (true) {
        printBoard(cb);
        printf("Player %s's turn. Enter move (startX startY endX endY): ", (player == WHITE ? "WHITE" : "BLACK"));
        scanf("%d %d %d %d", &startX, &startY, &endX, &endY);

        if (isMoveLegal(cb, startX, startY, endX, endY, player)) {
            movePiece(cb, startX, startY, endX, endY);
            player = (player == WHITE ? BLACK : WHITE); // Switch player
        } else {
            printf("Illegal move. Try again.\n");
        }
    }
}

int main() {
    ChessBoard cb;
    initializeBoard(&cb);
    playGame(&cb);
    return 0;
}