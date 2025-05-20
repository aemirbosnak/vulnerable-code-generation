//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: happy
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 8

char board[SIZE][SIZE];

// Initialize the chess board with pieces in their initial positions
void initialize_board() {
    const char* initial_rows[SIZE] = {
        "rnbqkbnr", // Black pieces
        "pppppppp", // Black pawns 
        "........", // Empty row
        "........", // Empty row
        "........", // Empty row
        "........", // Empty row
        "PPPPPPPP", // White pawns
        "RNBQKBNR"  // White pieces
    };
    
    for (int i = 0; i < SIZE; i++) {
        strcpy(board[i], initial_rows[i]);
    }
}

// Print the chess board to the terminal
void print_board() {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", SIZE - i);
    }
    printf("  a b c d e f g h\n\n");
}

// Convert the algebraic notation to array indices
bool move_to_indices(char *move, int *start_row, int *start_col, int *end_row, int *end_col) {
    if (strlen(move) != 4) return false;

    *start_col = move[0] - 'a';
    *start_row = SIZE - (move[1] - '0') - 1; // convert to array index
    *end_col = move[2] - 'a';
    *end_row = SIZE - (move[3] - '0') - 1; // convert to array index

    return (*start_col >= 0 && *start_col < SIZE && 
            *end_col >= 0 && *end_col < SIZE &&
            *start_row >= 0 && *start_row < SIZE &&
            *end_row >= 0 && *end_row < SIZE);
}

// Make a move on the board (naive implementation without rules)
bool make_move(char *move) {
    int start_row, start_col, end_row, end_col;
    if (move_to_indices(move, &start_row, &start_col, &end_row, &end_col)) {
        // Allow the move if the starting position has a piece
        if (board[start_row][start_col] != '.') {
            board[end_row][end_col] = board[start_row][start_col];
            board[start_row][start_col] = '.';
            return true;
        }
    }
    return false;
}

// Main game loop
void play_game() {
    char move[5]; // a2a3
    bool isWhiteTurn = true;

    while (1) {
        print_board();
        printf("%s's turn. Enter your move (e.g., a2a3): ", isWhiteTurn ? "White" : "Black");
        fgets(move, sizeof(move), stdin);
        move[strcspn(move, "\n")] = 0; // Remove newline character

        if (make_move(move)) {
            isWhiteTurn = !isWhiteTurn; // Switch turns
        } else {
            printf("Invalid move. Please try again!\n\n");
        }
    }
}

int main() {
    printf("Welcome to the Happy Chess Game!\n");
    initialize_board();
    play_game();
    return 0;
}