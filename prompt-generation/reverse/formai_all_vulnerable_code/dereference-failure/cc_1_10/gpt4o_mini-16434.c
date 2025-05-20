//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define WHITE 0
#define BLACK 1
#define EMPTY -1

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int turn;
} GameState;

void initializeBoard(GameState *game) {
    const char *initialPosition = 
        " r n b q k b n r\n"
        " p p p p p p p p\n"
        " . . . . . . . .\n"
        " . . . . . . . .\n"
        " . . . . . . . .\n"
        " . . . . . . . .\n"
        " P P P P P P P P\n"
        " R N B Q K B N R\n";

    int i = 0;
    while (initialPosition[i]) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (initialPosition[i] == '\n') break;
            game->board[7 - (i / 10)][j] = initialPosition[i];
            i++;
        }
        i++;
    }
    game->turn = WHITE;
}

void printBoard(const GameState *game) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(char piece, int srcRow, int srcCol, int destRow, int destCol) {
    // Simplified movement validation
    if (piece == 'P') return destRow == srcRow - 1 && destCol == srcCol; // Pawn example
    if (piece == 'p') return destRow == srcRow + 1 && destCol == srcCol; // Pawn example
    if (piece == 'R' || piece == 'r') return srcRow == destRow || srcCol == destCol; // Rook example
    // Add other pieces' movement checks here...

    return 0; // Invalid move
}

void movePiece(GameState *game, int srcRow, int srcCol, int destRow, int destCol) {
    char piece = game->board[srcRow][srcCol];
    if (isValidMove(piece, srcRow, srcCol, destRow, destCol)) {
        game->board[destRow][destCol] = piece;
        game->board[srcRow][srcCol] = '.';
        game->turn = (game->turn == WHITE) ? BLACK : WHITE;
    } else {
        printf("Invalid Move!\n");
    }
}

void userInput(GameState *game) {
    char input[6]; // e.g., "e2 e4"
    printf("Enter your move (e.g., e2 e4): ");
    fgets(input, sizeof(input), stdin);

    char src[3] = { input[0], input[1], '\0' };
    char dest[3] = { input[3], input[4], '\0' };

    int srcRow = 8 - (src[1] - '0');
    int srcCol = src[0] - 'a';
    int destRow = 8 - (dest[1] - '0');
    int destCol = dest[0] - 'a';

    movePiece(game, srcRow, srcCol, destRow, destCol);
}

int main() {
    GameState game;
    initializeBoard(&game);

    while (1) {
        printBoard(&game);
        userInput(&game);
    }

    return 0;
}