//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8
#define WHITE 1
#define BLACK -1
#define EMPTY 0

typedef struct {
    int board[SIZE][SIZE];
    int turn;
} ChessGame;

void initializeBoard(ChessGame *game) {
    memset(game->board, EMPTY, sizeof(game->board));
    
    // Place pawns
    for (int i = 0; i < SIZE; i++) {
        game->board[1][i] = WHITE;
        game->board[6][i] = BLACK;
    }
    
    // Place other pieces
    game->board[0][0] = game->board[0][7] = WHITE; // Rooks
    game->board[0][1] = game->board[0][6] = 0;   // Knights
    game->board[0][2] = game->board[0][5] = 0;   // Bishops
    game->board[0][3] = 0;                         // Queen
    game->board[0][4] = 0;                         // King

    game->board[7][0] = game->board[7][7] = BLACK; // Rooks
    game->board[7][1] = game->board[7][6] = 0;   // Knights
    game->board[7][2] = game->board[7][5] = 0;   // Bishops
    game->board[7][3] = 0;                         // Queen
    game->board[7][4] = 0;                         // King

    game->turn = WHITE;
}

void printBoard(const ChessGame *game) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            if (game->board[i][j] == WHITE)
                printf("W ");
            else if (game->board[i][j] == BLACK)
                printf("B ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int isMoveValid(const ChessGame *game, int startRow, int startCol, int endRow, int endCol) {
    // Basic rule: can't move into your own piece
    if (game->board[endRow][endCol] == game->turn) {
        return 0;
    }
    // Other move validation logic can go here
    return 1;
}

void makeMove(ChessGame *game, int startRow, int startCol, int endRow, int endCol) {
    if (isMoveValid(game, startRow, startCol, endRow, endCol)) {
        game->board[endRow][endCol] = game->board[startRow][startCol];
        game->board[startRow][startCol] = EMPTY;
        game->turn = -game->turn; // Switch turns
    }
}

void playGame() {
    ChessGame game;
    initializeBoard(&game);
    int startRow, startCol, endRow, endCol;

    while (1) {
        printBoard(&game);
        printf("Enter your move (e.g., 'e2 e4'): ");
        char move[10];
        fgets(move, sizeof(move), stdin);

        startCol = move[0] - 'a';
        startRow = SIZE - (move[1] - '0') - 1;
        endCol = move[3] - 'a';
        endRow = SIZE - (move[4] - '0') - 1;

        makeMove(&game, startRow, startCol, endRow, endCol);
    }
}

int main() {
    playGame();
    return 0;
}