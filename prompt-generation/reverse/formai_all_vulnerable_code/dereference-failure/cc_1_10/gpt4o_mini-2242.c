//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for the game
#define BOARD_SIZE 8
#define WHITE 1
#define BLACK 0

// Structure to represent the chessboard
typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} Chessboard;

// Function prototypes
void initializeBoard(Chessboard *chessboard);
void displayBoard(Chessboard *chessboard);
int isMoveValid(char *move, Chessboard *chessboard, int color);
void makeMove(char *move, Chessboard *chessboard);
int isGameOver(Chessboard *chessboard);

// Main function
int main() {
    Chessboard chessboard;
    char move[6]; // For a move like "e2e4"
    int currentTurn = WHITE;

    initializeBoard(&chessboard);
    
    while (!isGameOver(&chessboard)) {
        displayBoard(&chessboard);
        
        printf("%s's turn. Enter your move: ", currentTurn == WHITE ? "White" : "Black");
        scanf("%s", move);
        
        if (isMoveValid(move, &chessboard, currentTurn)) {
            makeMove(move, &chessboard);
            currentTurn = (currentTurn == WHITE) ? BLACK : WHITE; // Switch turns
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }

    printf("Game over!\n");
    return 0;
}

// Initialize the chessboard with pieces
void initializeBoard(Chessboard *chessboard) {
    const char *init_row[2] = {"rnbqkbnr", "RNBQKBNR"};
    const char *empty_row = "        "; // Empty row
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i == 0) {
            strcpy(chessboard->board[i], init_row[1]); // White pieces
        } else if (i == 1) {
            strcpy(chessboard->board[i], "PPPPPPPP"); // White pawns
        } else if (i == 6) {
            strcpy(chessboard->board[i], "pppppppp"); // Black pawns
        } else if (i == 7) {
            strcpy(chessboard->board[i], init_row[0]); // Black pieces
        } else {
            strcpy(chessboard->board[i], empty_row); // Empty rows
        }
    }
}

// Display the chessboard
void displayBoard(Chessboard *chessboard) {
    printf("\n   a b c d e f g h\n");
    printf("  +----------------+\n");
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", chessboard->board[i][j]);
        }
        printf("|\n");
    }

    printf("  +----------------+\n");
}

// Check if a move is valid (simplified validation)
int isMoveValid(char *move, Chessboard *chessboard, int color) {
    if (strlen(move) != 4) return 0; // Move must be 4 characters

    // Basic validation (detailed rules are omitted for brevity)
    int from_col = move[0] - 'a';
    int from_row = 8 - (move[1] - '0');
    int to_col = move[2] - 'a';
    int to_row = 8 - (move[3] - '0');

    if (from_col < 0 || from_col >= BOARD_SIZE || to_col < 0 || to_col >= BOARD_SIZE ||
        from_row < 0 || from_row >= BOARD_SIZE || to_row < 0 || to_row >= BOARD_SIZE) {
            return 0; // Out of bounds
    }

    // Simplified: just check if the destination is empty or the correct color piece
    char source_piece = chessboard->board[from_row][from_col];
    char target_piece = chessboard->board[to_row][to_col];

    if ((color == WHITE && source_piece >= 'a' && source_piece <= 'z') || 
        (color == BLACK && source_piece >= 'A' && source_piece <= 'Z')) {
            return 0; // Wrong color
    }

    return 1; // We assume the move is valid for now
}

// Move the piece on the chessboard
void makeMove(char *move, Chessboard *chessboard) {
    int from_col = move[0] - 'a';
    int from_row = 8 - (move[1] - '0');
    int to_col = move[2] - 'a';
    int to_row = 8 - (move[3] - '0');

    chessboard->board[to_row][to_col] = chessboard->board[from_row][from_col];
    chessboard->board[from_row][from_col] = ' '; // Empty the original position
}

// Placeholder for game over check (currently always false)
int isGameOver(Chessboard *chessboard) {
    return 0; // Game is never over in this simple implementation
}