//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef struct {
    char board[SIZE][SIZE];
    char currentPlayer;
} Game;

void initializeBoard(Game *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i % 2 != j % 2) { // Checkered pattern
                if (i < 3) {
                    game->board[i][j] = 'B'; // Black pieces
                } else if (i > 4) {
                    game->board[i][j] = 'R'; // Red pieces
                } else {
                    game->board[i][j] = '.'; // Empty
                }
            } else {
                game->board[i][j] = ' '; // Space
            }
        }
    }
    game->currentPlayer = 'R'; // Red starts first
}

void printBoard(Game *game) {
    printf("  A B C D E F G H\n");
    printf(" +----------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d|", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c|", game->board[i][j]);
        }
        printf("\n +----------------\n");
    }
}

int isMoveValid(Game *game, int startX, int startY, int endX, int endY) {
    if (endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE) return 0; // Out of bounds
    if (game->board[endX][endY] != '.') return 0; // Target must be empty
    if (game->board[startX][startY] == ' ') return 0; // There must be a piece to move

    int direction = (game->currentPlayer == 'R') ? 1 : -1;
    if (endX - startX == direction && abs(endY - startY) == 1) return 1; // Regular move
    if (endX - startX == direction * 2 && abs(endY - startY) == 2) {
        int midX = (startX + endX) / 2;
        int midY = (startY + endY) / 2;
        if (game->board[midX][midY] != ' ' && game->board[midX][midY] != game->currentPlayer) return 1; // Jump
    }
    return 0;
}

void makeMove(Game *game, int startX, int startY, int endX, int endY) {
    char temp = game->board[startX][startY];
    game->board[endX][endY] = temp; // Move the piece
    game->board[startX][startY] = '.'; // Empty the old spot

    // If it was a jump, remove the jumped piece
    if (abs(endX - startX) == 2) {
        int midX = (startX + endX) / 2;
        int midY = (startY + endY) / 2;
        game->board[midX][midY] = '.'; // Remove the jumped piece
    }
}

void switchPlayer(Game *game) {
    game->currentPlayer = (game->currentPlayer == 'R') ? 'B' : 'R';
}

int main() {
    Game game;
    initializeBoard(&game);
    int startX, startY, endX, endY;
    char startCol, endCol;

    while (1) {
        printBoard(&game);
        printf("Player %c's turn. Enter move (e.g., A3 B4): ", game.currentPlayer);
        scanf(" %c%d %c%d", &startCol, &startX, &endCol, &endX);
        
        startX -= 1; // Convert to 0-index
        endX -= 1; // Convert to 0-index
        startY = startCol - 'A'; // Convert to 0-index
        endY = endCol - 'A'; // Convert to 0-index

        if (isMoveValid(&game, startX, startY, endX, endY)) {
            makeMove(&game, startX, startY, endX, endY);
            switchPlayer(&game);
        } else {
            printf("Invalid move! Try again.\n");
        }
    }

    return 0;
}