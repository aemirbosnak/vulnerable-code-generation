//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef enum { EMPTY, RED, BLACK } Piece;
typedef struct {
    Piece board[SIZE][SIZE];
    int turn; // 0 for RED, 1 for BLACK
} GameState;

void initializeBoard(GameState *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 != 0) {
                if (i < 3) {
                    game->board[i][j] = BLACK;
                } else if (i > 4) {
                    game->board[i][j] = RED;
                } else {
                    game->board[i][j] = EMPTY;
                }
            } else {
                game->board[i][j] = EMPTY;
            }
        }
    }
    game->turn = 0; // RED starts first
}

void displayBoard(GameState *game) {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            if (game->board[i][j] == RED) {
                printf("R ");
            } else if (game->board[i][j] == BLACK) {
                printf("B ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int isValidMove(GameState *game, int fromRow, int fromCol, int toRow, int toCol) {
    Piece player = game->turn == 0 ? RED : BLACK;
    if (game->board[fromRow][fromCol] != player) return 0;
    if (game->board[toRow][toCol] != EMPTY) return 0;
    if (abs(fromRow - toRow) != 1 || abs(fromCol - toCol) != 1) return 0;

    return 1;
}

void makeMove(GameState *game, int fromRow, int fromCol, int toRow, int toCol) {
    game->board[toRow][toCol] = game->board[fromRow][fromCol];
    game->board[fromRow][fromCol] = EMPTY;
    game->turn = 1 - game->turn; // Switch turns
}

void getPlayerInput(GameState *game, int *fromRow, int *fromCol, int *toRow, int *toCol) {
    char fromColChar, toColChar;
    printf("Player %s, enter your move (e.g. 'A1 B2'): ", game->turn == 0 ? "RED" : "BLACK");
    scanf(" %c%d %c%d", &fromColChar, fromRow, &toColChar, toRow);
    *fromCol = fromColChar - 'A';
    *toCol = toColChar - 'A';
    (*fromRow)--; // Adjust for zero-based indexing
    (*toRow)--;
}

int main() {
    GameState game;
    initializeBoard(&game);
    
    while (1) {
        displayBoard(&game);
        int fromRow, fromCol, toRow, toCol;
        
        getPlayerInput(&game, &fromRow, &fromCol, &toRow, &toCol);
        
        if (isValidMove(&game, fromRow, fromCol, toRow, toCol)) {
            makeMove(&game, fromRow, fromCol, toRow, toCol);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}