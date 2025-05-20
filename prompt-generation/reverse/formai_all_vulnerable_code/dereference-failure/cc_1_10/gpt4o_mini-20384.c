//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 8

typedef struct {
    char board[SIZE][SIZE];
    bool whiteTurn;
} ChessGame;

void initializeBoard(ChessGame *game) {
    memset(game->board, 0, sizeof(game->board));
    char initialSetup[SIZE][SIZE] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            game->board[i][j] = initialSetup[i][j];
        }
    }
    game->whiteTurn = true;
}

void printBoard(ChessGame *game) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", game->board[i][j] == 0 ? '.' : game->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isValidMove(ChessGame *game, int fromRow, int fromCol, int toRow, int toCol) {
    char piece = game->board[fromRow][fromCol];
    if (piece == 0) return false;

    if ((game->whiteTurn && piece < 'a') || (!game->whiteTurn && piece > 'Z')) {
        return false; // Not the right player's turn
    }

    // Add basic rules to validate moves for different pieces
    // For simplicity, only allowing pawn moves for this example
    if (piece == 'P' && toRow == fromRow - 1 && toCol == fromCol && game->board[toRow][toCol] == 0) {
        return true; // valid forward move for Pawn
    }
    if (piece == 'p' && toRow == fromRow + 1 && toCol == fromCol && game->board[toRow][toCol] == 0) {
        return true; // valid forward move for Pawn
    }

    return false; // Invalid move
}

void makeMove(ChessGame *game, int fromRow, int fromCol, int toRow, int toCol) {
    game->board[toRow][toCol] = game->board[fromRow][fromCol];
    game->board[fromRow][fromCol] = 0;
    game->whiteTurn = !game->whiteTurn;
}

void undoMove(ChessGame *game, int fromRow, int fromCol, int toRow, int toCol, char capturedPiece) {
    game->board[fromRow][fromCol] = game->board[toRow][toCol];
    game->board[toRow][toCol] = capturedPiece;
    game->whiteTurn = !game->whiteTurn;
}

char getInput() {
    char move[5];
    printf("Enter move (e.g., e2 e4): ");
    fgets(move, sizeof(move), stdin);
    return move;
}

void parseMove(char* move, int *fromRow, int *fromCol, int *toRow, int *toCol) {
    *fromCol = move[0] - 'a';
    *fromRow = 8 - (move[1] - '0');
    *toCol = move[3] - 'a';
    *toRow = 8 - (move[4] - '0');
}

bool playGame(ChessGame *game) {
    printBoard(game);
    char move[5];
    while (true) {
        int fromRow, fromCol, toRow, toCol;
        getInput(move);
        parseMove(move, &fromRow, &fromCol, &toRow, &toCol);

        if (isValidMove(game, fromRow, fromCol, toRow, toCol)) {
            char capturedPiece = game->board[toRow][toCol];
            makeMove(game, fromRow, fromCol, toRow, toCol);
            printf("Move made!\n");
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
    return true;
}

int main() {
    ChessGame game;
    initializeBoard(&game);
    playGame(&game);
    return 0;
}