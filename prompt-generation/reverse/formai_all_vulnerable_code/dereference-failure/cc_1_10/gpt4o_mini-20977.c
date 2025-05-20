//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 8

typedef struct {
    char board[SIZE][SIZE];
} ChessGame;

void initializeBoard(ChessGame *game) {
    const char *initial[] = {
        "rnbqkbnr",
        "pppppppp",
        "........",
        "........",
        "........",
        "........",
        "PPPPPPPP",
        "RNBQKBNR"
    };
    
    for (int i = 0; i < SIZE; i++) {
        strcpy(game->board[i], initial[i]);
    }
}

void printBoard(const ChessGame *game) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(char piece, int startX, int startY, int endX, int endY) {
    // Simplified movement validation, no checks for check, or complex pieces
    int dx = endX - startX;
    int dy = endY - startY;

    switch (piece) {
        case 'P':
            return dx == -1 && dy == 0; // Pawn move example
        case 'R':
            return (dx == 0 || dy == 0); // Rook move example
        case 'N':
            return (abs(dx) == 2 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 2); // Knight move
        case 'B':
            return abs(dx) == abs(dy); // Bishop move
        case 'Q':
            return (dx == 0 || dy == 0 || abs(dx) == abs(dy)); // Queen move
        case 'K':
            return abs(dx) <= 1 && abs(dy) <= 1; // King move
        default:
            return 0; // Invalid piece
    }
}

void makeMove(ChessGame *game, int startX, int startY, int endX, int endY) {
    char piece = game->board[startX][startY];
    game->board[endX][endY] = piece;
    game->board[startX][startY] = '.';
}

int getUserMove(int *fromX, int *fromY, int *toX, int *toY) {
    char move[5];
    printf("Enter your move (e.g., e2 e4): ");
    if (fgets(move, sizeof(move), stdin)) {
        // Convert user input to board indexes
        *fromX = SIZE - (move[1] - '0'); // Move from rank (1-8)
        *fromY = move[0] - 'a';          // Move from file (a-h)
        *toX = SIZE - (move[4] - '0');   // Move to rank (1-8)
        *toY = move[3] - 'a';            // Move to file (a-h)
        return 1;
    }
    return 0;
}

void playGame() {
    ChessGame game;
    initializeBoard(&game);

    int fromX, fromY, toX, toY;
    while (1) {
        printBoard(&game);
        if (!getUserMove(&fromX, &fromY, &toX, &toY)) {
            printf("Invalid move input, try again.\n");
            continue;
        }

        char movingPiece = game.board[fromX][fromY];
        if (movingPiece == '.') {
            printf("No piece to move there!\n");
            continue;
        }
        
        if (isValidMove(movingPiece, fromX, fromY, toX, toY)) {
            makeMove(&game, fromX, fromY, toX, toY);
        } else {
            printf("Invalid move for piece %c\n", movingPiece);
        }
    }
}

int main() {
    printf("Welcome to Chess AI!\n");
    playGame();
    return 0;
}