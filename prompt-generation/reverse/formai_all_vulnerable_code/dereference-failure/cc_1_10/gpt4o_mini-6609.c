//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char turn;
} ChessGame;

void initializeBoard(ChessGame* game) {
    const char* initialPositions[BOARD_SIZE] = {
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
        strncpy(game->board[i], initialPositions[i], BOARD_SIZE);
    }
    game->turn = 'W'; // White starts
}

void printBoard(ChessGame game) {
    printf("\n  a b c d e f g h\n");
    printf(" +----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game.board[i][j]);
        }
        printf("\n");
    }
    printf(" +----------------\n");
    printf("   Turn: %c\n", game.turn);
}

int isValidMove(char piece, int startX, int startY, int endX, int endY, ChessGame game) {
    // Basic move validation (to be expanded for actual rules)
    if ((piece >= 'a' && piece <= 'z' && game.turn == 'W') || (piece >= 'A' && piece <= 'Z' && game.turn == 'B')) {
        return 0; // Wrong turn
    }
    // Check if the end position is within the bounds
    if (endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) {
        return 0; // Out of bounds
    }
    return 1; // Valid move for simplicity
}

void makeMove(ChessGame* game, int startX, int startY, int endX, int endY) {
    game->board[endX][endY] = game->board[startX][startY];
    game->board[startX][startY] = '.';
    game->turn = (game->turn == 'W') ? 'B' : 'W'; // Change turn
}

void playerMove(ChessGame* game) {
    char input[5];
    printf("Enter your move (e.g., e2 e4): ");
    scanf("%s", input);

    int startX = 8 - (input[1] - '0');
    int startY = input[0] - 'a';
    int endX = 8 - (input[4] - '0');
    int endY = input[3] - 'a';

    char piece = game->board[startX][startY];
    if (isValidMove(piece, startX, startY, endX, endY, *game)) {
        makeMove(game, startX, startY, endX, endY);
    } else {
        printf("Invalid move! Try again.\n");
    }
}

int main() {
    ChessGame game;
    initializeBoard(&game);
    printBoard(game);

    while (1) {
        playerMove(&game);
        printBoard(game);
    }

    return 0;
}