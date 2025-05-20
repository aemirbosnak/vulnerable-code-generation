//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef enum { EMPTY, BLACK, WHITE } Piece;
typedef struct {
    Piece board[SIZE][SIZE];
} CheckersGame;

void initializeGame(CheckersGame *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i < 3 && (i + j) % 2 == 1) {
                game->board[i][j] = BLACK;
            } else if (i > 4 && (i + j) % 2 == 1) {
                game->board[i][j] = WHITE;
            } else {
                game->board[i][j] = EMPTY;
            }
        }
    }
}

void printBoard(CheckersGame *game) {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            char c;
            switch (game->board[i][j]) {
                case BLACK: c = 'B'; break;
                case WHITE: c = 'W'; break;
                case EMPTY: c = '.'; break;
            }
            printf("%c ", c);
        }
        printf("\n");
    }
}

int isValidMove(CheckersGame *game, int fromRow, int fromCol, int toRow, int toCol, Piece player) {
    if (toRow < 0 || toRow >= SIZE || toCol < 0 || toCol >= SIZE) return 0;
    if (game->board[toRow][toCol] != EMPTY) return 0;

    int rowDifference = toRow - fromRow;
    int colDifference = toCol - fromCol;

    if (player == WHITE && rowDifference == -1 && abs(colDifference) == 1) return 1; // normal move
    if (player == BLACK && rowDifference == 1 && abs(colDifference) == 1) return 1; // normal move
    return 0; // invalid move
}

void movePiece(CheckersGame *game, int fromRow, int fromCol, int toRow, int toCol) {
    game->board[toRow][toCol] = game->board[fromRow][fromCol];
    game->board[fromRow][fromCol] = EMPTY;
}

int main() {
    CheckersGame game;
    initializeGame(&game);
    int fromRow, fromCol, toRow, toCol;
    char fromColChar, toColChar;
    Piece currentPlayer = BLACK;

    while (1) {
        printBoard(&game);
        printf("Player %s's turn (Input: FromRow FromCol ToRow ToCol): ", currentPlayer == BLACK ? "BLACK" : "WHITE");
        scanf(" %c%d %c%d", &fromColChar, &fromRow, &toColChar, &toRow);

        fromCol = fromColChar - 'A';
        fromRow = SIZE - fromRow; // Adjust for 0-based index
        toCol = toColChar - 'A';
        toRow = SIZE - toRow; // Adjust for 0-based index

        if (isValidMove(&game, fromRow, fromCol, toRow, toCol, currentPlayer)) {
            movePiece(&game, fromRow, fromCol, toRow, toCol);
            currentPlayer = (currentPlayer == BLACK) ? WHITE : BLACK; // Switch player
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }

    return 0;
}