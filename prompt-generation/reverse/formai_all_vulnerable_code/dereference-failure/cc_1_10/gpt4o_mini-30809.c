//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

typedef struct {
    char board[SIZE][SIZE];
} ChessBoard;

void initializeBoard(ChessBoard *chessBoard) {
    const char *initialSetup[SIZE] = {
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
        strcpy(chessBoard->board[i], initialSetup[i]);
    }
}

void printBoard(const ChessBoard *chessBoard) {
    printf("  a b c d e f g h\n");
    printf(" +-----------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d| ", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", chessBoard->board[i][j] == '.' ? ' ' : chessBoard->board[i][j]);
        }
        printf("|\n");
    }
    printf(" +-----------------\n");
}

int isValidMove(const ChessBoard *chessBoard, const char *move) {
    // Check the format of the move
    if (strlen(move) != 5)
        return 0;
    
    int startX = SIZE - (move[1] - '0'); // from rank
    int startY = move[0] - 'a';          // from file
    int endX = SIZE - (move[4] - '0');   // to rank
    int endY = move[3] - 'a';             // to file

    // Check bounds
    if (startX < 0 || startX >= SIZE || startY < 0 || startY >= SIZE ||
        endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE)
        return 0;

    // Can only move own pieces (uppercase for white, lowercase for black)
    char piece = chessBoard->board[startX][startY];
    if (piece == '.' || (piece >= 'a' && piece <= 'z' && (endX < startX)))
        return 0;

    return 1; // Move is valid (simplified check)
}

void makeMove(ChessBoard *chessBoard, const char *move) {
    int startX = SIZE - (move[1] - '0');
    int startY = move[0] - 'a';
    int endX = SIZE - (move[4] - '0');
    int endY = move[3] - 'a';

    chessBoard->board[endX][endY] = chessBoard->board[startX][startY];
    chessBoard->board[startX][startY] = '.';
}

int main() {
    ChessBoard chessBoard;
    initializeBoard(&chessBoard);
    char move[6];

    while (1) {
        printBoard(&chessBoard);
        printf("Enter your move (e.g., e2 e4): ");
        fgets(move, sizeof(move), stdin);
        
        // Convert user input from `e2 e4` to `e2e4` format
        move[4] = move[5] = '\0'; // Null-terminate 
        move[2] = move[3]; // Capture the second part
        move[3] = move[4] = '\0'; // Null-terminate second part 
        
        if (!isValidMove(&chessBoard, move)) {
            printf("Invalid move!\n");
            continue;
        }
        
        makeMove(&chessBoard, move);
    }

    return 0;
}