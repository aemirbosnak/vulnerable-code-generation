//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

typedef struct {
    char board[SIZE][SIZE];
} ChessBoard;

void initializeBoard(ChessBoard* cb) {
    const char* initial[] = {
        "rnbqkbnr",
        "pppppppp",
        "........",
        "........",
        "........",
        "........",
        "PPPPPPPP",
        "RNBQKBNR"
    };
    
    for (int i = 0; i < SIZE; ++i) {
        strcpy(cb->board[i], initial[i]);
    }
}

void printBoard(const ChessBoard* cb) {
    printf("  a b c d e f g h\n");
    printf(" +-----------------\n");
    for (int i = SIZE-1; i >= 0; --i) {
        printf("%d| ", i + 1);
        for (int j = 0; j < SIZE; ++j) {
            printf("%c ", cb->board[i][j]);
        }
        printf("|\n");
    }
    printf(" +-----------------\n");
}

int isValidMove(const char* move) {
    if (strlen(move) < 4) return 0;
    return (move[0] >= 'a' && move[0] <= 'h' && move[1] >= '1' && move[1] <= '8' &&
            move[2] >= 'a' && move[2] <= 'h' && move[3] >= '1' && move[3] <= '8');
}

void makeMove(ChessBoard* cb, const char* move) {
    int startFile = move[0] - 'a';
    int startRank = move[1] - '1';
    int endFile = move[2] - 'a';
    int endRank = move[3] - '1';

    // Capture logic and basic move
    if (cb->board[startRank][startFile] != '.') {
        cb->board[endRank][endFile] = cb->board[startRank][startFile];
        cb->board[startRank][startFile] = '.';
    } else {
        printf("Invalid Move\n");
    }
}

void playGame() {
    ChessBoard cb;
    initializeBoard(&cb);
    
    char move[5];
    while (1) {
        printBoard(&cb);
        printf("Enter your move (or 'exit' to quit): ");
        fgets(move, sizeof(move), stdin);
        
        if (strncmp(move, "exit", 4) == 0) {
            break;
        }

        move[strcspn(move, "\n")] = 0; // Remove newline
        if (isValidMove(move)) {
            makeMove(&cb, move);
        } else {
            printf("Invalid move format. Use 'e2e4' format.\n");
        }
    }
}

int main() {
    printf("Welcome to the Simple Chess Engine!\n");
    playGame();
    return 0;
}