//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define EMPTY ' '
#define PAWN 'P'
#define KNIGHT 'N'
#define BISHOP 'B'
#define ROOK 'R'
#define QUEEN 'Q'
#define KING 'K'

void displayBoard(char board[SIZE][SIZE]) {
    printf("   a b c d e f g h\n");
    printf("  -----------------\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%d| ", SIZE - i);
        for(int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  -----------------\n");
}

void initializeBoard(char board[SIZE][SIZE]) {
    char initialPos[SIZE][SIZE] = {
        {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK},
        {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
        {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK}
    };
    
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            board[i][j] = initialPos[i][j];
        }
    }
}

int isValidMove(char board[SIZE][SIZE], int startX, int startY, int endX, int endY) {
    // Simple rule: Checks for basic bounds, not for specific piece rules.
    if (endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE) {
        return 0; // Out of bounds
    }
    if (board[endX][endY] != EMPTY) {
        return 0; // Target square is not empty
    }
    return 1; // Valid move according to basic rules
}

void movePiece(char board[SIZE][SIZE], int startX, int startY, int endX, int endY) {
    board[endX][endY] = board[startX][startY];
    board[startX][startY] = EMPTY;
}

void knightMoves(char board[SIZE][SIZE], int x, int y) {
    int knightMoves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, 
                              {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
    for (int i = 0; i < 8; i++) {
        int newX = x + knightMoves[i][0];
        int newY = y + knightMoves[i][1];
        if (isValidMove(board, x, y, newX, newY)) {
            printf("Knight can move to: %c%d\n", newY + 'a', SIZE - newX);
        }
    }
}

void kingMoves(char board[SIZE][SIZE], int x, int y) {
    int kingMoves[8][2] = {{-1, -1}, {-1, 0}, {-1, +1}, 
                            {0, -1},           {0, +1}, 
                            {+1, -1}, {+1, 0}, {+1, +1}};
    for (int i = 0; i < 8; i++) {
        int newX = x + kingMoves[i][0];
        int newY = y + kingMoves[i][1];
        if (isValidMove(board, x, y, newX, newY)) {
            printf("King can move to: %c%d\n", newY + 'a', SIZE - newX);
        }
    }
}

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    
    int currentPlayer = 0;
    while (1) {
        displayBoard(board);
        printf("Current Player: %s\n", currentPlayer == 0 ? "White" : "Black");
        printf("Enter your move (e.g., e2 e4): ");
        
        char start[3], end[3];
        scanf("%s %s", start, end);
        
        int startX = SIZE - (start[1] - '0');
        int startY = start[0] - 'a';
        int endX = SIZE - (end[1] - '0');
        int endY = end[0] - 'a';
        
        if(isValidMove(board, startX, startY, endX, endY)) {
            movePiece(board, startX, startY, endX, endY);
            currentPlayer = 1 - currentPlayer; // Switch players
        } else {
            printf("Alas, that is not a valid move!\n");
        }
    }
    return 0;
}