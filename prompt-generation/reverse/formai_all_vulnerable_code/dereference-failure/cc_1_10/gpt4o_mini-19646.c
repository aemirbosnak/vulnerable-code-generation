//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define WHITE 'W'
#define BLACK 'B'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentTurn;
} ChessGame;

void initializeGame(ChessGame *game);
void printBoard(const ChessGame *game);
int makeMove(ChessGame *game, const char *move);
int isMoveValid(const ChessGame *game, const char *move);
void switchTurn(ChessGame *game);
int isWinningMove(const ChessGame *game);

int main() {
    ChessGame game;
    initializeGame(&game);
    char move[5];

    while (1) {
        printBoard(&game);
        printf("Current turn: %c\n", game.currentTurn);
        printf("Enter your move (e.g., e2e4): ");
        scanf("%s", move);

        if (strcmp(move, "quit") == 0) {
            printf("Game ended.\n");
            break;
        }

        if (makeMove(&game, move)) {
            if (isWinningMove(&game)) {
                printf("Player %c wins!\n", game.currentTurn);
                break;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}

void initializeGame(ChessGame *game) {
    memset(game->board, EMPTY, sizeof(game->board));
    game->currentTurn = WHITE;

    // Initialize pawn positions as an example
    for (int i = 0; i < BOARD_SIZE; i++) {
        game->board[1][i] = WHITE; // White pawns
        game->board[6][i] = BLACK; // Black pawns
    }
}

void printBoard(const ChessGame *game) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int makeMove(ChessGame *game, const char *move) {
    if (!isMoveValid(game, move)) {
        return 0;
    }

    int fromRow = 8 - (move[1] - '0');
    int fromCol = move[0] - 'a';
    int toRow = 8 - (move[3] - '0');
    int toCol = move[2] - 'a';

    if (game->board[fromRow][fromCol] != game->currentTurn) {
        return 0; // Not player's turn
    }

    game->board[toRow][toCol] = game->board[fromRow][fromCol];
    game->board[fromRow][fromCol] = EMPTY;

    switchTurn(game);
    return 1;
}

int isMoveValid(const ChessGame *game, const char *move) {
    if (strlen(move) != 4) {
        return 0; // Invalid move length
    }

    int fromRow = 8 - (move[1] - '0');
    int fromCol = move[0] - 'a';
    int toRow = 8 - (move[3] - '0');
    int toCol = move[2] - 'a';

    if (fromRow < 0 || fromRow >= BOARD_SIZE || fromCol < 0 || fromCol >= BOARD_SIZE ||
        toRow < 0 || toRow >= BOARD_SIZE || toCol < 0 || toCol >= BOARD_SIZE) {
        return 0; // Move out of bounds
    }

    // Basic validation: check for a clear path or valid capture
    char fromPiece = game->board[fromRow][fromCol];
    char toPiece = game->board[toRow][toCol];

    if (fromPiece == EMPTY || (toPiece != EMPTY && toPiece == fromPiece)) {
        return 0; // Cannot move to an occupied square by the same color
    }

    return 1; // Basic move validation passed
}

void switchTurn(ChessGame *game) {
    game->currentTurn = (game->currentTurn == WHITE) ? BLACK : WHITE;
}

int isWinningMove(const ChessGame *game) {
    // A placeholder for win condition checks; can be expanded later
    return 0;
}