//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

// Function prototypes
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]);
int movePiece(char board[BOARD_SIZE][BOARD_SIZE], char *move);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    char move[6];
    int turn = 0; // 0 for white's turn, 1 for black's turn

    initializeBoard(board);
    
    while (1) {
        printBoard(board);
        
        printf("\n%s's turn. Enter your move (e.g., e2 e4): ", turn == 0 ? "White" : "Black");
        fgets(move, sizeof(move), stdin);
        move[strcspn(move, "\n")] = 0;  // Remove newline character
        
        if (strcmp(move, "exit") == 0) break;

        if (movePiece(board, move)) {
            turn = !turn; // Switch turns
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }

    return 0;
}

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    const char *initial[] = {
        "rnbqkbnr", // Black pieces
        "pppppppp", // Black pawns
        "        ", // Empty
        "        ", // Empty
        "        ", // Empty
        "        ", // Empty
        "PPPPPPPP", // White pawns
        "RNBQKBNR"  // White pieces
    };

    for (int i = 0; i < BOARD_SIZE; ++i) {
        strcpy(board[i], initial[i]);
    }
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n  a b c d e f g h\n");
    printf(" +----------------+\n");
    for (int i = 0; i < BOARD_SIZE; ++i) {
        printf("%d|", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf(" +----------------+\n");
}

int movePiece(char board[BOARD_SIZE][BOARD_SIZE], char *move) {
    char src[3], dest[3];
    int srcRow, srcCol, destRow, destCol;

    // Parse the move input into source and destination
    if (sscanf(move, "%2s %2s", src, dest) != 2) {
        return 0; // Invalid input
    }

    // Convert user-friendly coordinates to array indices
    srcCol = src[0] - 'a';
    srcRow = BOARD_SIZE - (src[1] - '0');
    destCol = dest[0] - 'a';
    destRow = BOARD_SIZE - (dest[1] - '0');

    // Validate move
    if (srcRow < 0 || srcRow >= BOARD_SIZE || 
        srcCol < 0 || srcCol >= BOARD_SIZE ||
        destRow < 0 || destRow >= BOARD_SIZE || 
        destCol < 0 || destCol >= BOARD_SIZE) {
        return 0; // Out of bounds
    }
    
    // Validate if there's a piece at the source
    if (board[srcRow][srcCol] == ' ') {
        return 0; // No piece to move
    }
    
    // Move the piece (Overwrite destination)
    board[destRow][destCol] = board[srcRow][srcCol];
    board[srcRow][srcCol] = ' '; // Clear the source square
    
    return 1; // Successful move
}