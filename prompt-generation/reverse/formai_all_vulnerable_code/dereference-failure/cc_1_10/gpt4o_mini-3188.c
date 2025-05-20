//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum { EMPTY, WHITE, BLACK } Piece;
typedef struct {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    int currentPlayer;
} Game;

void initializeBoard(Game* game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i % 2 != j % 2) {
                if (i < 3) {
                    game->board[i][j] = BLACK;
                } else if (i > 4) {
                    game->board[i][j] = WHITE;
                } else {
                    game->board[i][j] = EMPTY;
                }
            } else {
                game->board[i][j] = EMPTY;
            }
        }
    }
    game->currentPlayer = WHITE;
}

void printBoard(Game* game) {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            char pieceChar = '.';
            if (game->board[i][j] == BLACK) {
                pieceChar = 'B';
            } else if (game->board[i][j] == WHITE) {
                pieceChar = 'W';
            }
            printf("%c ", pieceChar);
        }
        printf("\n");
    }
}

int isMoveValid(Game* game, int startRow, int startCol, int endRow, int endCol) {
    if (endRow < 0 || endRow >= BOARD_SIZE || endCol < 0 || endCol >= BOARD_SIZE) {
        return 0;
    }
    if (game->board[endRow][endCol] != EMPTY) {
        return 0;
    }
    int rowDiff = endRow - startRow;
    int colDiff = endCol - startCol;
    if (game->currentPlayer == WHITE && rowDiff == -1 && (colDiff == -1 || colDiff == 1)) {
        return 1;
    }
    if (game->currentPlayer == BLACK && rowDiff == 1 && (colDiff == -1 || colDiff == 1)) {
        return 1;
    }
    return 0;
}

void movePiece(Game* game, int startRow, int startCol, int endRow, int endCol) {
    game->board[endRow][endCol] = game->board[startRow][startCol];
    game->board[startRow][startCol] = EMPTY;
}

void changePlayer(Game* game) {
    game->currentPlayer = (game->currentPlayer == WHITE) ? BLACK : WHITE;
}

void playGame() {
    Game game;
    initializeBoard(&game);
    int startRow, startCol, endRow, endCol;

    while (1) {
        printBoard(&game);
        printf("Player %s's turn. Enter move (e.g., A3 B4): ", game.currentPlayer == WHITE ? "WHITE" : "BLACK");
        char start, end;
        scanf(" %c%d %c%d", &start, &startRow, &end, &endRow);
        startRow -= 1; // Convert to 0-indexed
        endRow -= 1;   // Convert to 0-indexed
        startCol = start - 'A';
        endCol = end - 'A';

        if (isMoveValid(&game, startRow, startCol, endRow, endCol)) {
            movePiece(&game, startRow, startCol, endRow, endCol);
            changePlayer(&game);
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
}

int main() {
    playGame();
    return 0;
}