//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define WHITE 'W'
#define BLACK 'B'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer;
} ChessGame;

void initializeBoard(ChessGame *game) {
    memset(game->board, EMPTY, sizeof(game->board));
    
    // Place pieces
    for (int i = 0; i < BOARD_SIZE; i++) {
        game->board[1][i] = WHITE; // White pawns
        game->board[6][i] = BLACK; // Black pawns
    }

    game->board[0][0] = game->board[0][7] = 'R'; // Rooks
    game->board[0][1] = game->board[0][6] = 'N'; // Knights
    game->board[0][2] = game->board[0][5] = 'B'; // Bishops
    game->board[0][3] = 'Q'; // Queen
    game->board[0][4] = 'K'; // King
    
    game->board[7][0] = game->board[7][7] = 'r'; // Rooks
    game->board[7][1] = game->board[7][6] = 'n'; // Knights
    game->board[7][2] = game->board[7][5] = 'b'; // Bishops
    game->board[7][3] = 'q'; // Queen
    game->board[7][4] = 'k'; // King
    
    game->currentPlayer = WHITE;
}

void printBoard(ChessGame *game) {
    printf("   A B C D E F G H\n");
    printf("  +----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", 8-i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
    printf("  +----------------\n");
}

int isMoveValid(ChessGame *game, int startRow, int startCol, int endRow, int endCol) {
    // Simplified validation: Only checks for empty spaces and same color
    char piece = game->board[startRow][startCol];
    if (piece == EMPTY) return 0;
    if ((game->currentPlayer == WHITE && piece != WHITE) || (game->currentPlayer == BLACK && piece != BLACK))
        return 0; 
    
    if (game->board[endRow][endCol] == EMPTY || 
        (game->currentPlayer == WHITE && game->board[endRow][endCol] == BLACK) || 
        (game->currentPlayer == BLACK && game->board[endRow][endCol] == WHITE)) {
        return 1; // Valid move
    }
    
    return 0; // Invalid move
}

void makeMove(ChessGame *game, int startRow, int startCol, int endRow, int endCol) {
    game->board[endRow][endCol] = game->board[startRow][startCol];
    game->board[startRow][startCol] = EMPTY;
}

void switchPlayer(ChessGame *game) {
    game->currentPlayer = (game->currentPlayer == WHITE) ? BLACK : WHITE;
}

int main() {
    ChessGame game;
    initializeBoard(&game);
  
    while (1) {
        printBoard(&game);
        printf("Current Player: %c\n", game.currentPlayer);
        
        char input[5];
        printf("Enter your move (e.g., e2 e4): ");
        fgets(input, sizeof(input), stdin);

        // Parse input
        int startRow = 8 - (input[1] - '0');
        int startCol = input[0] - 'A';
        int endRow = 8 - (input[4] - '0');
        int endCol = input[3] - 'A';

        if (isMoveValid(&game, startRow, startCol, endRow, endCol)) {
            makeMove(&game, startRow, startCol, endRow, endCol);
            switchPlayer(&game);
        } else {
            printf("Invalid move, try again.\n");
        }
    }

    return 0;
}