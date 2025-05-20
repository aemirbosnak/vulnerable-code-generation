//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: realistic
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
    const char *initial[] = {
        "rnbqkbnr",
        "pppppppp",
        "        ",
        "        ",
        "        ",
        "        ",
        "PPPPPPPP",
        "RNBQKBNR"
    };
    
    for (int i = 0; i < SIZE; i++) {
        strcpy(game->board[i], initial[i]);
    }
    game->whiteTurn = true;
}

void printBoard(const ChessGame *game) {
    printf("  a b c d e f g h\n");
    printf(" +-----------------\n");
    
    for (int i = 0; i < SIZE; i++) {
        printf("%d|", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", game->board[i][j] == ' ' ? '.' : game->board[i][j]);
        }
        printf("|\n");
    }
    printf(" +-----------------\n");
}

bool isValidMove(char piece, int startRow, int startCol, int endRow, int endCol) {
    // Simplified movement rules, only checking basic moves for pawns and rooks
    if (piece == 'P') { // white pawn
        if (startCol == endCol) {
            if (endRow == startRow + 1 && endRow < SIZE) return true; // move forward
        }
    } else if (piece == 'p') { // black pawn
        if (startCol == endCol) {
            if (endRow == startRow - 1 && endRow >= 0) return true; // move forward
        }
    } else if (piece == 'R' || piece == 'r') { // rook
        if (startRow == endRow || startCol == endCol) return true; // vertical or horizontal move
    }
    return false;
}

void makeMove(ChessGame *game, int startRow, int startCol, int endRow, int endCol) {
    char piece = game->board[startRow][startCol];
    if (isValidMove(piece, startRow, startCol, endRow, endCol)) {
        game->board[endRow][endCol] = piece;
        game->board[startRow][startCol] = ' ';
        game->whiteTurn = !game->whiteTurn;
    }
}

void getInput(const ChessGame *game) {
    char move[5];
    printf("%s's turn. Enter your move (e.g., e2 e4): ", game->whiteTurn ? "White" : "Black");
    fgets(move, sizeof(move), stdin);
    
    int startRow = SIZE - (move[1] - '0');
    int startCol = move[0] - 'a';
    int endRow = SIZE - (move[4] - '0');
    int endCol = move[3] - 'a';

    makeMove(game, startRow, startCol, endRow, endCol);
}

int main() {
    ChessGame game;
    initializeBoard(&game);
    
    while (true) {
        printBoard(&game);
        getInput(&game);
    }
    return 0;
}