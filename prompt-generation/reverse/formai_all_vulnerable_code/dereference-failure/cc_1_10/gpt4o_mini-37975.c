//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef struct {
    char board[SIZE][SIZE];
} Checkers;

void initializeBoard(Checkers *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i < 3 && (i + j) % 2 == 1)
                game->board[i][j] = 'B'; // Black pieces
            else if (i > 4 && (i + j) % 2 == 1)
                game->board[i][j] = 'R'; // Red pieces
            else
                game->board[i][j] = '.'; // Empty
        }
    }
}

void printBoard(Checkers game) {
    printf("\n  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", game.board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isValidMove(Checkers game, int srcRow, int srcCol, int destRow, int destCol, char player) {
    // Check that the destination is within bounds and empty
    if (destRow < 0 || destRow >= SIZE || destCol < 0 || destCol >= SIZE || game.board[destRow][destCol] != '.') {
        return 0;
    }

    // Check that the move is diagonal
    if (abs(destRow - srcRow) != abs(destCol - srcCol) || abs(destRow - srcRow) > 2) {
        return 0;
    }

    // Capturing logic
    if (abs(destRow - srcRow) == 2) {
        int middleRow = (srcRow + destRow) / 2;
        int middleCol = (srcCol + destCol) / 2;
        
        if (game.board[middleRow][middleCol] == (player == 'R' ? 'B' : 'R')) {
            return 1; // Valid capture
        }
        return 0;
    }

    // Regular move
    return abs(destRow - srcRow) == 1;
}

void makeMove(Checkers *game, int srcRow, int srcCol, int destRow, int destCol) {
    char player = game->board[srcRow][srcCol];
    game->board[destRow][destCol] = player; // Move the piece
    game->board[srcRow][srcCol] = '.'; // Empty the source

    // Check for capturing
    if (abs(destRow - srcRow) == 2) {
        int middleRow = (srcRow + destRow) / 2;
        int middleCol = (srcCol + destCol) / 2;
        game->board[middleRow][middleCol] = '.'; // Remove captured piece
    }
}

int main() {
    Checkers game;
    initializeBoard(&game);
    printBoard(game);

    int currentPlayer = 0; // 0 for player 'R', 1 for player 'B'
    char players[2] = {'R', 'B'};
    while (1) {
        int srcRow, srcCol, destRow, destCol;
        char srcColChar, destColChar;

        printf("Player %c's turn: ", players[currentPlayer]);
        printf("Enter move (e.g. A3 B4): ");
        scanf(" %c%d %c%d", &srcColChar, &srcRow, &destColChar, &destRow);

        srcCol = srcColChar - 'A';
        destCol = destColChar - 'A';
        srcRow -= 1;
        destRow -= 1;

        // Validate move
        if (isValidMove(game, srcRow, srcCol, destRow, destCol, players[currentPlayer])) {
            makeMove(&game, srcRow, srcCol, destRow, destCol);
            printBoard(game);
        } else {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Switch players
        currentPlayer = (currentPlayer + 1) % 2;
    }

    return 0;
}