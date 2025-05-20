//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure to represent a checkers board
struct CheckersBoard {
    int size;
    int** board;
};

// Initialize a new checkers board of size n
struct CheckersBoard* newCheckersBoard(int n) {
    struct CheckersBoard* board = (struct CheckersBoard*) malloc(sizeof(struct CheckersBoard));
    board->size = n;
    board->board = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        board->board[i] = (int*) malloc(n * sizeof(int));
    }
    return board;
}

// Free the memory used by a checkers board
void freeCheckersBoard(struct CheckersBoard* board) {
    free(board->board);
    free(board);
}

// Move a piece from one square to another on the board
void movePiece(struct CheckersBoard* board, int from, int to) {
    board->board[to][board->size - 1 - from] = -1;
    board->board[from][board->size - 1 - to] = board->size - 1;
}

// Check if a move is valid on the board
bool isValidMove(struct CheckersBoard* board, int from, int to) {
    int n = board->size;
    int* row = board->board[from];
    int* nextRow = board->board[to];
    for (int i = 0; i < n; i++) {
        if (row[i]!= -1 && nextRow[i]!= -1 && row[i] == nextRow[i]) {
            return false;
        }
    }
    return true;
}

// Play a game of checkers
int main() {
    int n = 8; // Size of the board
    struct CheckersBoard* board = newCheckersBoard(n);

    // Initialize the board
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                board->board[i][j] = -1;
            } else {
                board->board[i][j] = i + j;
            }
        }
    }

    // Print the board
    printf("Checkers Board:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Play the game
    int currentPlayer = 1;
    while (true) {
        int from, to;
        printf("Player %d, enter coordinates of piece to move (e.g. 1,2): ", currentPlayer % 2 == 0? "Black" : "Red");
        scanf("%d %d", &from, &to);
        if (!isValidMove(board, from, to)) {
            printf("Invalid move. Try again.\n");
        } else {
            movePiece(board, from, to);
            printf("Player %d moved piece from (%d,%d) to (%d,%d)\n", currentPlayer, from, board->size - 1 - from, to, board->size - 1 - to);
            currentPlayer =!currentPlayer % 2;
        }
    }

    // Free the memory used by the board
    freeCheckersBoard(board);

    return 0;
}