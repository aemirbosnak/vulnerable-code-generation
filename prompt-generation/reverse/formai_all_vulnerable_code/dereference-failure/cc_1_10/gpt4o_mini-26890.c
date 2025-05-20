//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define WHITE 1
#define BLACK 0

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int turn;
} Game;

void initializeBoard(Game *game) {
    const char *initial[] = {
        "rnbqkbnr", // Black pieces
        "pppppppp", // Black pawns
        "........", // Empty
        "........", // Empty
        "........", // Empty
        "........", // Empty
        "PPPPPPPP", // White pawns
        "RNBQKBNR"  // White pieces
    };

    for (int i = 0; i < BOARD_SIZE; i++) {
        strcpy(game->board[i], initial[i]);
    }

    game->turn = WHITE; // White starts first
}

void printBoard(Game *game) {
    printf("  ---------------------------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d | ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j] == '.' ? '.' : game->board[i][j]);
        }
        printf("|\n");
    }
    printf("  ---------------------------------\n");
    printf("    a b c d e f g h\n");
}

int isMoveValid(Game *game, char *move) {
    // This function should validate if the move is legal.
    // For now, let's allow any move for simplicity.
    return 1;
}

void makeMove(Game *game, char *move) {
    // For this simple example, we will just simulate moves without specific logic.
    int fromRow = BOARD_SIZE - (move[1] - '0');
    int fromCol = move[0] - 'a';
    int toRow = BOARD_SIZE - (move[4] - '0');
    int toCol = move[3] - 'a';

    if (isMoveValid(game, move)) {
        // Move the piece
        game->board[toRow][toCol] = game->board[fromRow][fromCol];
        game->board[fromRow][fromCol] = '.';

        // Switch turn
        game->turn = !game->turn;
    } else {
        printf("Invalid move!\n");
    }
}

void playGame(Game *game) {
    char move[6]; // e.g. "e2 e4"
    while (1) {
        printBoard(game);
        printf("Enter your move (e.g., e2 e4): ");
        fgets(move, sizeof(move), stdin);

        // Trim newline character
        move[strcspn(move, "\n")] = 0;

        makeMove(game, move);
    }
}

int main() {
    Game game;
    initializeBoard(&game);
    playGame(&game);
    return 0;
}