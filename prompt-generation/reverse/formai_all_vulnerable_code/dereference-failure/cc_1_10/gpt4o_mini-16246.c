//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 8

typedef struct {
    char board[SIZE][SIZE];
} ChessBoard;

void initializeBoard(ChessBoard *chessBoard) {
    const char *initialSetup[SIZE] = {
        "rnbqkbnr",
        "pppppppp",
        "        ",
        "        ",
        "        ",
        "        ",
        "PPPPPPPP",
        "RNBQKBNR"
    };
    
    for (int i = 0; i < SIZE; i++) {
        strcpy(chessBoard->board[i], initialSetup[i]);
    }
}

void printBoard(const ChessBoard *chessBoard) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            if (chessBoard->board[i][j] == ' ') {
                printf(". ");
            } else {
                printf("%c ", chessBoard->board[i][j]);
            }
        }
        printf("%d\n", SIZE - i);
    }
    printf("  a b c d e f g h\n");
}

bool isValidMove(const ChessBoard *chessBoard, const char *move) {
    // This function checks if the move is valid according to basic chess rules
    // For simplicity, we'll just check if the move is in the correct format.

    if (strlen(move) != 5) return false; // e.g., e2 to e4 is "e2 e4"
    
    char sourceFile = move[0];
    char sourceRank = move[1];
    char destFile = move[3];
    char destRank = move[4];

    return (sourceFile >= 'a' && sourceFile <= 'h' && 
            sourceRank >= '1' && sourceRank <= '8' &&
            destFile >= 'a' && destFile <= 'h' && 
            destRank >= '1' && destRank <= '8');
}

void makeMove(ChessBoard *chessBoard, const char *move) {
    char sourceFile = move[0];
    char sourceRank = move[1];
    char destFile = move[3];
    char destRank = move[4];

    int srcRow = SIZE - (sourceRank - '0');
    int srcCol = sourceFile - 'a';
    int destRow = SIZE - (destRank - '0');
    int destCol = destFile - 'a';

    chessBoard->board[destRow][destCol] = chessBoard->board[srcRow][srcCol];
    chessBoard->board[srcRow][srcCol] = ' ';
}

void playGame() {
    ChessBoard chessBoard;
    initializeBoard(&chessBoard);
    char move[6];

    while (true) {
        printf("\nCurrent Board:\n");
        printBoard(&chessBoard);
        printf("Enter your move (e.g. e2 e4), or 'exit' to quit: ");
        
        fgets(move, sizeof(move), stdin);
        move[strcspn(move, "\n")] = '\0'; // Remove newline

        if (strcmp(move, "exit") == 0) {
            break;
        }

        if (isValidMove(&chessBoard, move)) {
            makeMove(&chessBoard, move);
        } else {
            printf("Invalid move! Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Imaginative Chess Engine!\n");
    playGame();
    printf("Thank you for playing!\n");
    return 0;
}