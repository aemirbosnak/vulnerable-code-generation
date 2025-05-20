//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 8

typedef enum { EMPTY, PLAYER1, PLAYER2 } Cell;

typedef struct {
    Cell board[SIZE][SIZE];
    int player1Score;
    int player2Score;
} GameState;

// Function to initialize the game state
void initGame(GameState *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            game->board[i][j] = EMPTY;
        }
    }
    // Setup Player 1
    for (int i = 0; i < 3; i++) {
        for (int j = (i % 2); j < SIZE; j += 2) {
            game->board[i][j] = PLAYER1;
        }
    }
    // Setup Player 2
    for (int i = 5; i < SIZE; i++) {
        for (int j = (i % 2); j < SIZE; j += 2) {
            game->board[i][j] = PLAYER2;
        }
    }
    game->player1Score = 0;
    game->player2Score = 0;
}

// Function to print the board
void printBoard(const GameState *game) {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            switch (game->board[i][j]) {
                case EMPTY: printf(". "); break;
                case PLAYER1: printf("X "); break;
                case PLAYER2: printf("O "); break;
            }
        }
        printf("\n");
    }
    printf("Player 1 Score: %d\n", game->player1Score);
    printf("Player 2 Score: %d\n", game->player2Score);
}

// Function to check if a move is valid
bool isValidMove(const GameState *game, int startX, int startY, int endX, int endY, bool isPlayer1) {
    Cell player = isPlayer1 ? PLAYER1 : PLAYER2;
    Cell opponent = isPlayer1 ? PLAYER2 : PLAYER1;

    if (endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE)
        return false;

    if (game->board[endX][endY] != EMPTY)
        return false;

    if (abs(endX - startX) == 1 && abs(endY - startY) == 1) {
        // Simple move
        return (game->board[startX][startY] == player);
    } else if (abs(endX - startX) == 2 && abs(endY - startY) == 2) {
        // Jump move
        int middleX = (startX + endX) / 2;
        int middleY = (startY + endY) / 2;
        return (game->board[startX][startY] == player && game->board[middleX][middleY] == opponent);
    }

    return false;
}

// Function to make a move
void makeMove(GameState *game, int startX, int startY, int endX, int endY) {
    // Update board
    Cell player = game->board[startX][startY];
    game->board[endX][endY] = player;
    game->board[startX][startY] = EMPTY;

    // Check for captures
    if (abs(endX - startX) == 2) {
        int middleX = (startX + endX) / 2;
        int middleY = (startY + endY) / 2;
        // Remove the opponent's piece
        game->board[middleX][middleY] = EMPTY;
        if (player == PLAYER1) {
            game->player1Score++;
        } else {
            game->player2Score++;
        }
    }
}

// Function to play the game
void playGame() {
    GameState game;
    initGame(&game);

    bool isPlayer1Turn = true;
    while (true) {
        printBoard(&game);
        int startX, startY, endX, endY;
        char startCol, endCol;

        if (isPlayer1Turn) {
            printf("Player 1's turn (X). Move from (e.g., 'E2') to (e.g., 'D3'): ");
        } else {
            printf("Player 2's turn (O). Move from (e.g., 'D7') to (e.g., 'C6'): ");
        }

        scanf(" %c%d %c%d", &startCol, &startX, &endCol, &endX);

        startY = startCol - 'A';
        endY = endCol - 'A';
        startX = SIZE - startX;   // Convert to array index
        endX = SIZE - endX;       // Convert to array index
        
        if (isValidMove(&game, startX, startY, endX, endY, isPlayer1Turn)) {
            makeMove(&game, startX, startY, endX, endY);
            isPlayer1Turn = !isPlayer1Turn;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

int main() {
    playGame();
    return 0;
}