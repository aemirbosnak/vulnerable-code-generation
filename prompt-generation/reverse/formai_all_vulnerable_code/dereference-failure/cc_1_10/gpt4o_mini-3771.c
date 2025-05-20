//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_SIZE 8
#define WHITE 'W'
#define BLACK 'B'
#define EMPTY '.'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} ChessBoard;

void initializeBoard(ChessBoard *chessBoard) {
    const char *initialSetup[BOARD_SIZE] = {
        "RNBQKBNR",
        "PPPPPPPP",
        "........",
        "........",
        "........",
        "........",
        "pppppppp",
        "rnbqkbnr"
    };

    for (int i = 0; i < BOARD_SIZE; i++) {
        strcpy(chessBoard->board[i], initialSetup[i]);
    }
}

void printBoard(const ChessBoard *chessBoard) {
    printf("  a b c d e f g h\n");
    printf("  -----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", chessBoard->board[i][j]);
        }
        printf("|\n");
    }
    printf("  -----------------\n");
}

bool isValidMove(const ChessBoard *chessBoard, int startX, int startY, int endX, int endY, char player) {
    char piece = chessBoard->board[startX][startY];

    if (piece == EMPTY || (player == WHITE && piece >= 'a') || (player == BLACK && piece <= 'Z')) {
        return false;
    }

    // Add other piece movement validations...
    // For simplicity, let's assume all moves are valid (not including complex rules)

    return true;
}

void movePiece(ChessBoard *chessBoard, int startX, int startY, int endX, int endY) {
    chessBoard->board[endX][endY] = chessBoard->board[startX][startY];
    chessBoard->board[startX][startY] = EMPTY;
}

void playGame() {
    ChessBoard chessBoard;
    initializeBoard(&chessBoard);
    char currentPlayer = WHITE;
    char input[5];
    int startX, startY, endX, endY;

    while (true) {
        printBoard(&chessBoard);
        printf("Player %c's turn. Enter your move (e.g., e2 e4): ", currentPlayer);
        fgets(input, sizeof(input), stdin);

        // Process input
        if (sscanf(input, "%c%d %c%d", (char*)&startY, &startX, (char*)&endY, &endX) != 4) {
            printf("Invalid input format. Please try again.\n");
            continue;
        }

        // Convert input from 'a1' format to array indices
        startX = BOARD_SIZE - startX;
        startY = startY - 'a';
        endX = BOARD_SIZE - endX;
        endY = endY - 'a';

        if (isValidMove(&chessBoard, startX, startY, endX, endY, currentPlayer)) {
            movePiece(&chessBoard, startX, startY, endX, endY);
            currentPlayer = (currentPlayer == WHITE) ? BLACK : WHITE; // Switch player
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Curious Chess Engine!\n");
    playGame();
    return 0;
}