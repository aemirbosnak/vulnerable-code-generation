//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer;
} ChessGame;

void initializeBoard(ChessGame *game) {
    // Initialize the chessboard with pieces
    const char *initialSetup[BOARD_SIZE] = {
        "rnbqkbnr",  // Black pieces
        "pppppppp",
        "        ",
        "        ",
        "        ",
        "        ",
        "PPPPPPPP",  // White pieces
        "RNBQKBNR"   // White pieces
    };

    for (int i = 0; i < BOARD_SIZE; i++)
        strcpy(game->board[i], initialSetup[i]);

    game->currentPlayer = 'W'; // Start with White
}

void displayBoard(const ChessGame *game) {
    printf("  a b c d e f g h\n");
    printf(" +-----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j] == ' ' ? '.' : game->board[i][j]);
        }
        printf("|\n");
    }
    printf(" +-----------------\n");
}

int isValidMove(int srcRow, int srcCol, int destRow, int destCol, const ChessGame *game) {
    // Simplistic validation: check if within bounds and moving own piece
    char piece = game->board[srcRow][srcCol];
    if (piece == ' ' || (game->currentPlayer == 'W' && piece < 'A') || (game->currentPlayer == 'B' && piece > 'Z')) {
        return 0; // Invalid piece
    }
    // Basic move bounds check
    return (destRow >= 0 && destRow < BOARD_SIZE && destCol >= 0 && destCol < BOARD_SIZE);
}

void makeMove(ChessGame *game, int srcRow, int srcCol, int destRow, int destCol) {
    if (isValidMove(srcRow, srcCol, destRow, destCol, game)) {
        game->board[destRow][destCol] = game->board[srcRow][srcCol];
        game->board[srcRow][srcCol] = ' '; // Empty the source square
        game->currentPlayer = (game->currentPlayer == 'W') ? 'B' : 'W'; // Switch players
    } else {
        printf("Invalid move!\n");
    }
}

void promptMove(ChessGame *game) {
    char move[5];
    printf("Player %c, enter your move (e.g., e2 e4): ", game->currentPlayer);
    fgets(move, sizeof(move), stdin);
    
    int srcRow = 8 - (move[1] - '0');
    int srcCol = move[0] - 'a';
    int destRow = 8 - (move[4] - '0');
    int destCol = move[3] - 'a';

    makeMove(game, srcRow, srcCol, destRow, destCol);
}

int main() {
    ChessGame game;
    initializeBoard(&game);

    while (1) {
        displayBoard(&game);
        promptMove(&game);
    }

    return 0;
}