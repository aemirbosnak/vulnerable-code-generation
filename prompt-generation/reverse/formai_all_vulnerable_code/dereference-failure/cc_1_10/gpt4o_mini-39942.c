//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} CheckersGame;

void initializeBoard(CheckersGame *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 != 0) {
                if (i < 3) {
                    game->board[i][j] = 'b';  // Black pieces
                } else if (i > 4) {
                    game->board[i][j] = 'r';  // Red pieces
                } else {
                    game->board[i][j] = ' ';
                }
            } else {
                game->board[i][j] = ' ';
            }
        }
    }
}

void printBoard(CheckersGame *game) {
    printf("  a b c d e f g h\n");
    printf(" +----------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", game->board[i][j]);
        }
        printf("\n +----------------+\n");
    }
}

int isValidMove(CheckersGame *game, int startRow, int startCol, int endRow, int endCol, char player) {
    int direction = (player == 'r') ? -1 : 1; // Red moves up, Black moves down
    if (endRow < 0 || endRow >= BOARD_SIZE || endCol < 0 || endCol >= BOARD_SIZE) {
        return 0; // Move off board
    }
    if (game->board[endRow][endCol] != ' ') {
        return 0; // Target square is occupied
    }
    if ((endRow - startRow == direction) && (abs(endCol - startCol) == 1)) {
        return 1; // Simple move
    }
    if ((endRow - startRow == 2 * direction) && (abs(endCol - startCol) == 2)) {
        int middleRow = (startRow + endRow) / 2;
        int middleCol = (startCol + endCol) / 2;
        if (game->board[middleRow][middleCol] != ' ' && game->board[middleRow][middleCol] != player) {
            return 1; // Jump move
        }
    }
    return 0; // Invalid move
}

void makeMove(CheckersGame *game, int startRow, int startCol, int endRow, int endCol) {
    char player = game->board[startRow][startCol];
    game->board[endRow][endCol] = player;
    game->board[startRow][startCol] = ' ';
    if (abs(endRow - startRow) == 2) { // Jump move
        int middleRow = (startRow + endRow) / 2;
        int middleCol = (startCol + endCol) / 2;
        game->board[middleRow][middleCol] = ' '; // Remove jumped piece
    }
}

int main() {
    CheckersGame game;
    initializeBoard(&game);
    char player = 'r';
    int startRow, startCol, endRow, endCol;
    char startColChar, endColChar;

    while (1) {
        printBoard(&game);
        printf("Player %c's turn. Enter move (e.g. a3 b4): ", player);
        scanf(" %c%d %c%d", &startColChar, &startRow, &endColChar, &endRow);

        startCol = startColChar - 'a';
        startRow -= 1; // Convert to 0-index
        endCol = endColChar - 'a';
        endRow -= 1; // Convert to 0-index

        if (isValidMove(&game, startRow, startCol, endRow, endCol, player)) {
            makeMove(&game, startRow, startCol, endRow, endCol);
            player = (player == 'r') ? 'b' : 'r'; // Switch player
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}