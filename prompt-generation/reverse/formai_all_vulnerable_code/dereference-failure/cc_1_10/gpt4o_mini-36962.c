//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

// Define pieces
#define EMPTY ' '
#define PAWN 'P'
#define ROOK 'R'
#define KNIGHT 'N'
#define BISHOP 'B'
#define QUEEN 'Q'
#define KING 'K'

// Structure of a Chessboard
typedef struct {
    char board[SIZE][SIZE];
} Chessboard;

// Function to initialize the chessboard with pieces
void initialize_board(Chessboard *chessboard) {
    const char *initial_setup[SIZE] = {
        "R N B Q K B N R",
        "P P P P P P P P",
        "                ",
        "                ",
        "                ",
        "                ",
        "p p p p p p p p",
        "r n b q k b n r"
    };

    for (int i = 0; i < SIZE; ++i) {
        char *token = strtok(initial_setup[i], " ");
        for (int j = 0; j < SIZE; ++j) {
            chessboard->board[i][j] = token ? token[0] : EMPTY;
            token = strtok(NULL, " ");
        }
    }
}

// Function to print the chessboard
void print_board(const Chessboard *chessboard) {
    printf("\n");
    for (int i = SIZE - 1; i >= 0; --i) {
        printf("%d  ", i + 1);
        for (int j = 0; j < SIZE; ++j) {
            printf("%c ", chessboard->board[i][j]);
        }
        printf("\n");
    }
    printf("\n   a b c d e f g h\n");
}

// Function to move a piece
int move_piece(Chessboard *chessboard, int start_row, int start_col, int end_row, int end_col) {
    if (chessboard->board[start_row][start_col] == EMPTY) {
        return 0; // No piece to move
    }
    // Check if move is within bounds
    if (end_row < 0 || end_row >= SIZE || end_col < 0 || end_col >= SIZE) {
        return 0; // Move out of bounds
    }
    // Simple rule: can't move to the same spot or capture own piece
    if (start_row == end_row && start_col == end_col) {
        return 0; 
    }
    if ((chessboard->board[end_row][end_col] != EMPTY) && 
        ((chessboard->board[start_row][start_col] >= 'A' && chessboard->board[end_row][end_col] >= 'A') || 
         (chessboard->board[start_row][start_col] <= 'z' && chessboard->board[end_row][end_col] <= 'z'))) {
        return 0; // Can't capture own piece
    }
    
    // Perform the move
    chessboard->board[end_row][end_col] = chessboard->board[start_row][start_col];
    chessboard->board[start_row][start_col] = EMPTY;
    return 1; // Move successful
}

// Function to read a move from user input
void read_move(char *move) {
    printf("Enter your move (e.g., e2 e4): ");
    fgets(move, 10, stdin);
}

// Function to convert algebraic notation to board indices
void convert_move(const char *move, int *start_row, int *start_col, int *end_row, int *end_col) {
    char start_col_char = move[0];
    char start_row_char = move[1];
    char end_col_char = move[3];
    char end_row_char = move[4];

    *start_col = start_col_char - 'a';
    *start_row = start_row_char - '1';
    *end_col = end_col_char - 'a';
    *end_row = end_row_char - '1';
}

// Main function to orchestrate the chess game
int main() {
    Chessboard chessboard;
    initialize_board(&chessboard);
    print_board(&chessboard);
    
    char move[10];
    int start_row, start_col, end_row, end_col;

    while (1) {
        read_move(move);
        convert_move(move, &start_row, &start_col, &end_row, &end_col);
        if (move_piece(&chessboard, start_row, start_col, end_row, end_col)) {
            printf("Move successful!\n");
        } else {
            printf("Invalid Move, try again.\n");
        }
        print_board(&chessboard);
    }

    return 0;
}