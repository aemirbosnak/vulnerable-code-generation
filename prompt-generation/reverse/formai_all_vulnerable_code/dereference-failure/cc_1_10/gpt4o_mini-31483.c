//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

char board[SIZE][SIZE];

void initializeBoard() {
    const char* initialSetup[SIZE] = {
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
        strcpy(board[i], initialSetup[i]);
    }
}

void printBoard() {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j] == ' ' ? '.' : board[i][j]);
        }
        printf("%d\n", 8 - i);
    }
    printf("  a b c d e f g h\n");
}

int isValidMove(const char *move) {
    // Basic validation of moves (e.g., ensuring 4 characters)
    if (strlen(move) != 4) return 0;

    // Check if move is within the bounds
    int startX = 8 - (move[1] - '0');
    int startY = move[0] - 'a';
    int endX = 8 - (move[3] - '0');
    int endY = move[2] - 'a';

    if (startX < 0 || startX >= SIZE || startY < 0 || startY >= SIZE ||
        endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE) {
        return 0;
    }
    return 1;
}

void movePiece(const char *move) {
    int startX = 8 - (move[1] - '0');
    int startY = move[0] - 'a';
    int endX = 8 - (move[3] - '0');
    int endY = move[2] - 'a';

    board[endX][endY] = board[startX][startY];
    board[startX][startY] = ' ';
}

int main() {
    char move[5];
    int turn = 0; // 0 for white, 1 for black

    initializeBoard();
    
    while (1) {
        printBoard();
        printf("Player %s's Turn. Enter your move (e.g., e2e4): ", turn == 0 ? "White" : "Black");
        
        scanf("%s", move);
        
        if (isValidMove(move)) {
            movePiece(move);
            turn = 1 - turn; // Switch turns
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    
    return 0;
}