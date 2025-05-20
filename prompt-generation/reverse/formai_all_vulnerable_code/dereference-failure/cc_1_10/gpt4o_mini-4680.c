//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define EMPTY '.'
#define WHITE 'W'
#define BLACK 'B'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentTurn;
} GameState;

void initializeBoard(GameState *game) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            game->board[i][j] = EMPTY;
        }
    }
    game->board[0][0] = game->board[0][7] = WHITE; // Rooks
    game->board[0][1] = game->board[0][6] = WHITE; // Knights
    game->board[0][2] = game->board[0][5] = WHITE; // Bishops
    game->board[0][3] = WHITE; // Queen
    game->board[0][4] = WHITE; // King
    for (int j = 0; j < BOARD_SIZE; ++j) {
        game->board[1][j] = WHITE; // Pawns
    }
    game->board[7][0] = game->board[7][7] = BLACK; // Rooks
    game->board[7][1] = game->board[7][6] = BLACK; // Knights
    game->board[7][2] = game->board[7][5] = BLACK; // Bishops
    game->board[7][3] = BLACK; // Queen
    game->board[7][4] = BLACK; // King
    for (int j = 0; j < BOARD_SIZE; ++j) {
        game->board[6][j] = BLACK; // Pawns
    }
    game->currentTurn = WHITE;
}

void printBoard(GameState *game) {
    for (int i = BOARD_SIZE - 1; i >= 0; --i) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

int isMoveValid(GameState *game, int startX, int startY, int endX, int endY) {
    // Example rule: check for simple horizontal or vertical moves for rooks (not complete)
    char piece = game->board[startX][startY];
    if ((piece == WHITE || piece == BLACK) && (piece == game->currentTurn)) {
        if (startX == endX || startY == endY) {
            return 1; // Valid move for rook
        }
    }
    return 0; // Invalid move
}

void makeMove(GameState *game, int startX, int startY, int endX, int endY) {
    char piece = game->board[startX][startY];
    game->board[endX][endY] = piece; // Move the piece
    game->board[startX][startY] = EMPTY; // Empty the original spot
}

void switchTurn(GameState *game) {
    game->currentTurn = (game->currentTurn == WHITE) ? BLACK : WHITE;
}

void playGame() {
    GameState game;
    initializeBoard(&game);
    printBoard(&game);
    
    while (1) {
        printf("Current turn: %c\n", game.currentTurn);
        char startCol, endCol;
        int startRow, endRow;
        printf("Enter your move (e.g., e2 e4): ");
        scanf(" %c%d %c%d", &startCol, &startRow, &endCol, &endRow);

        int startX = startRow - 1; // Convert to 0-indexed
        int startY = startCol - 'a'; // Convert char to index
        int endX = endRow - 1; // Convert to 0-indexed
        int endY = endCol - 'a'; // Convert char to index

        if (isMoveValid(&game, startX, startY, endX, endY)) {
            makeMove(&game, startX, startY, endX, endY);
            switchTurn(&game);
            printBoard(&game);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

int main() {
    playGame();
    return 0;
}