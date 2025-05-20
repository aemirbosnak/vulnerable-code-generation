//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

typedef enum { EMPTY, WHITE, BLACK } Piece;

typedef struct {
    Piece board[SIZE][SIZE];
} Game;

void initializeGame(Game *game) {
    memset(game->board, EMPTY, sizeof(game->board));
    for (int i = 0; i < 3; i++)
        for (int j = (i % 2); j < SIZE; j += 2)
            game->board[i][j] = WHITE;
    for (int i = 5; i < 8; i++)
        for (int j = (i % 2); j < SIZE; j += 2)
            game->board[i][j] = BLACK;
}

void printBoard(const Game *game) {
    printf("   a b c d e f g h\n");
    printf("  +----------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d| ", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            switch (game->board[i][j]) {
                case WHITE: printf("W "); break;
                case BLACK: printf("B "); break;
                case EMPTY: printf(". "); break;
            }
        }
        printf("\n");
    }
    printf("  +----------------\n");
}

int isMoveValid(Game *game, int srcX, int srcY, int destX, int destY, Piece player) {
    if (destX < 0 || destX >= SIZE || destY < 0 || destY >= SIZE || 
        game->board[destX][destY] != EMPTY || 
        (abs(srcX - destX) != 1 && abs(srcX - destX) != 2) || 
        (abs(srcY - destY) != 1 && abs(srcY - destY) != 2)) 
        return 0;

    int midX = (srcX + destX) / 2;
    int midY = (srcY + destY) / 2;

    if (abs(srcX - destX) == 2 && game->board[midX][midY] == (player == WHITE ? BLACK : WHITE))
        return 1;

    return (abs(srcX - destX) == 1);
}

void makeMove(Game *game, int srcX, int srcY, int destX, int destY) {
    Piece player = game->board[srcX][srcY];
    game->board[destX][destY] = player;
    game->board[srcX][srcY] = EMPTY;

    // Handle capture
    if (abs(srcX - destX) == 2) {
        int midX = (srcX + destX) / 2;
        int midY = (srcY + destY) / 2;
        game->board[midX][midY] = EMPTY;
    }
}

Piece getCurrentPlayer(int turn) {
    return (turn % 2 == 0) ? WHITE : BLACK;
}

void surrealistMessage(Piece player) {
    if (player == WHITE) {
        printf("A twist of fate as a dance of shadows awaits!\n");
    } else {
        printf("The spark of chaos ignites the surreal canvas!\n");
    }
}

int main() {
    Game game;
    initializeGame(&game);
    int turn = 0;
    char src[3], dest[3];

    while (1) {
        printBoard(&game);
        Piece currentPlayer = getCurrentPlayer(turn);
        surrealistMessage(currentPlayer);
        
        printf("Player %s, enter your move (e.g., e3 e4): ", (currentPlayer == WHITE) ? "White" : "Black");
        scanf("%s %s", src, dest);

        int srcX = SIZE - (src[1] - '0');
        int srcY = src[0] - 'a';
        int destX = SIZE - (dest[1] - '0');
        int destY = dest[0] - 'a';

        if (isMoveValid(&game, srcX, srcY, destX, destY, currentPlayer)) {
            makeMove(&game, srcX, srcY, destX, destY);
            turn++;
        } else {
            printf("Invalid move, like the fleeting whispers of a dream.\n");
        }
    }

    return 0;
}