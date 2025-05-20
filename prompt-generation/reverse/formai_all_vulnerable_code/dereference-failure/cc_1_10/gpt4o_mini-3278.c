//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BOARD_SIZE 8
#define PLAYER_WHITE 1
#define PLAYER_BLACK -1

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    int currentPlayer;
} GameState;

void initializeBoard(GameState *gameState) {
    const char *initialBoard[BOARD_SIZE] = {
        "rnbqkbnr",
        "pppppppp",
        "........",
        "........",
        "........",
        "........",
        "PPPPPPPP",
        "RNBQKBNR"
    };

    for (int i = 0; i < BOARD_SIZE; i++) {
        strcpy(gameState->board[i], initialBoard[i]);
    }
    gameState->currentPlayer = PLAYER_WHITE;
}

void printBoard(const GameState *gameState) {
    printf("  a b c d e f g h\n");
    printf(" +----------------\n");
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", gameState->board[i][j]);
        }
        printf("\n");
    }
    printf(" +----------------\n");
}

bool isMoveValid(GameState *gameState, const char *move) {
    // Basic validation: Ensure the move format is correct
    if (strlen(move) != 4) return false;

    int startX = BOARD_SIZE - (move[1] - '0');
    int startY = move[0] - 'a';
    int endX = BOARD_SIZE - (move[3] - '0');
    int endY = move[2] - 'a';

    // Ensure moves are within bounds
    if (startX < 0 || startX >= BOARD_SIZE || 
        startY < 0 || startY >= BOARD_SIZE || 
        endX < 0 || endX >= BOARD_SIZE || 
        endY < 0 || endY >= BOARD_SIZE) {
        return false;
    }
    
    // More complex validation would occur here in a full implementation.
    return true;
}

void makeMove(GameState *gameState, const char *move) {
    int startX = BOARD_SIZE - (move[1] - '0');
    int startY = move[0] - 'a';
    int endX = BOARD_SIZE - (move[3] - '0');
    int endY = move[2] - 'a';

    // Move the piece
    gameState->board[endX][endY] = gameState->board[startX][startY];
    gameState->board[startX][startY] = '.';

    // Switch players
    gameState->currentPlayer *= -1;
}

void playGame() {
    GameState gameState;
    initializeBoard(&gameState);
    char move[5];

    while (true) {
        printBoard(&gameState);
        printf("Player %s's turn. Enter your move (e.g., e2e4): ", 
               gameState.currentPlayer == PLAYER_WHITE ? "White" : "Black");
        scanf("%4s", move);

        if (strcmp(move, "exit") == 0) {
            printf("Exiting game.\n");
            break;
        }

        if (isMoveValid(&gameState, move)) {
            makeMove(&gameState, move);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

int main() {
    playGame();
    return 0;
}