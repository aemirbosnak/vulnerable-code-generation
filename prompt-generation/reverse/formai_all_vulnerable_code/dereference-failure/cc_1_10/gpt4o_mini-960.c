//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the chess board
void initialize_board() {
    const char *initial_setup[BOARD_SIZE] = {
        "rnbqkbnr",
        "pppppppp",
        "        ",
        "        ",
        "        ",
        "        ",
        "PPPPPPPP",
        "RNBQKBNR"
    };
    for (int i = 0; i < BOARD_SIZE; i++) {
        strcpy(board[i], initial_setup[i]);
    }
}

// Function to print the chess board
void print_board() {
    printf("  a b c d e f g h\n");
    printf(" +-----------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j] == ' ' ? '.' : board[i][j]);
        }
        printf("|\n");
    }
    printf(" +-----------------+\n");
}

// Function to move a piece on the board
int move_piece(const char *move) {
    if (strlen(move) != 5) {
        printf("Invalid move format!\n");
        return 0;
    }
    int from_col = move[0] - 'a';
    int from_row = 8 - (move[1] - '0');
    int to_col = move[3] - 'a';
    int to_row = 8 - (move[4] - '0');

    if (from_col < 0 || from_col >= BOARD_SIZE || from_row < 0 || from_row >= BOARD_SIZE ||
        to_col < 0 || to_col >= BOARD_SIZE || to_row < 0 || to_row >= BOARD_SIZE) {
        printf("Move out of bounds!\n");
        return 0;
    }

    if (board[from_row][from_col] == ' ') {
        printf("No piece at source!\n");
        return 0;
    }

    // Move the piece
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = ' ';
    return 1;
}

int main() {
    char move[6];
    int turn = 0; // 0 for white, 1 for black

    printf("Welcome to the energetic C Chess Engine!\n");
    initialize_board();

    while (1) {
        print_board();
        printf("Player %s, enter your move (e.g., e2 e4): ", (turn == 0) ? "White" : "Black");
        fgets(move, sizeof(move), stdin);
        move[strcspn(move, "\n")] = 0; // Remove newline for input

        if (strcmp(move, "exit") == 0) {
            printf("Thanks for playing!\n");
            break;
        }

        if (!move_piece(move)) {
            continue; // If move fails, prompt again without changing turn
        }
        
        turn = !turn; // Switch turn
    }

    return 0;
}