//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} ChessBoard;

void initializeBoard(ChessBoard *chessBoard) {
    const char *pieces = "rnbqkbnrpppppppp                                PPPPPPPPRNBQKBNR";
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            chessBoard->board[i][j] = pieces[i * BOARD_SIZE + j];
        }
    }
}

void printBoard(const ChessBoard *chessBoard) {
    for (int i = BOARD_SIZE - 1; i >= 0; i--) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", chessBoard->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isValidMove(const ChessBoard *chessBoard, const char *move, char player) {
    // Very basic validation. Just checks if the move is within bounds.
    int fromX = move[0] - 'a';
    int fromY = move[1] - '1';
    int toX = move[2] - 'a';
    int toY = move[3] - '1';

    // Ensure move is within bounds and destination square is valid
    if (fromX < 0 || fromX >= BOARD_SIZE || fromY < 0 || fromY >= BOARD_SIZE ||
        toX < 0 || toX >= BOARD_SIZE || toY < 0 || toY >= BOARD_SIZE) {
        return 0; // Invalid move
    }
    if (chessBoard->board[fromY][fromX] == ' ') {
        return 0; // No piece to move
    }
    // Add more checks for specific piece movement rules if necessary
    return 1; // Valid move
}

void makeMove(ChessBoard *chessBoard, const char *move) {
    int fromX = move[0] - 'a';
    int fromY = move[1] - '1';
    int toX = move[2] - 'a';
    int toY = move[3] - '1';

    chessBoard->board[toY][toX] = chessBoard->board[fromY][fromX];
    chessBoard->board[fromY][fromX] = ' ';
}

int main() {
    ChessBoard chessBoard;
    initializeBoard(&chessBoard);
    
    char move[5];
    char player = 'w'; // white goes first

    while (1) {
        printBoard(&chessBoard);
        printf("Player %c, enter your move (e.g., e2e4) or 'quit' to exit: ", player);
        scanf("%s", move);

        if (strcmp(move, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        if (strlen(move) != 4 || !isValidMove(&chessBoard, move, player)) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        makeMove(&chessBoard, move);
        player = (player == 'w') ? 'b' : 'w'; // Swap players
    }

    return 0;
}