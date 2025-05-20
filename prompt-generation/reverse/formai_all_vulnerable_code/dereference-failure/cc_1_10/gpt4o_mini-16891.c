//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

char board[SIZE][SIZE];

// Initialize the board
void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = ' ';
            } else {
                if (i < 3) {
                    board[i][j] = 'B'; // Black pieces
                } else if (i > 4) {
                    board[i][j] = 'R'; // Red pieces
                } else {
                    board[i][j] = ' ';
                }
            }
        }
    }
}

// Print the board
void printBoard() {
    printf("  A B C D E F G H\n");
    printf(" +----------------+\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d| ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf(" +----------------+\n");
}

// Convert user input to board coordinates
void parseInput(char input[3], int *row, int *col) {
    *col = input[0] - 'A'; // Convert column
    *row = input[1] - '1'; // Convert row
}

// Check valid movement of the piece
int isValidMove(int fromRow, int fromCol, int toRow, int toCol) {
    // Basic check for game moves
    if (toRow < 0 || toRow >= SIZE || toCol < 0 || toCol >= SIZE ||
        board[toRow][toCol] != ' ') {
        return 0;
    }

    // Check if the move is diagonal
    if (abs(fromRow - toRow) == 1 && abs(fromCol - toCol) == 1) {
        return 1;
    }
    return 0;
}

// Move the piece
void movePiece(int fromRow, int fromCol, int toRow, int toCol) {
    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = ' ';
}

// Main game loop
void playGame() {
    char input[3];
    int fromRow, fromCol, toRow, toCol;
    char turn = 'R';

    while (1) {
        printBoard();
        printf("Player %c's turn. Enter your move (e.g., B3 B4): ", turn);
        fgets(input, sizeof(input), stdin);
        
        // Parse input
        parseInput(&input[0], &fromRow, &fromCol);
        parseInput(&input[3], &toRow, &toCol);
        
        // Validate move
        if (isValidMove(fromRow, fromCol, toRow, toCol)) {
            movePiece(fromRow, fromCol, toRow, toCol);
            turn = (turn == 'R') ? 'B' : 'R'; // Switch turn
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

int main() {
    initializeBoard();
    playGame();
    return 0;
}