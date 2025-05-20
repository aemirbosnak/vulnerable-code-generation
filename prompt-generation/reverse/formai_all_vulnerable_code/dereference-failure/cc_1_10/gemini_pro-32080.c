//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Card states
#define UNKNOWN -1
#define MATCH 0
#define MISMATCH 1

// Player types
#define HUMAN 0
#define COMPUTER 1

// Board dimensions
#define NUM_ROWS 4
#define NUM_COLS 4

// Function prototypes
void print_board(int board[NUM_ROWS][NUM_COLS]);
bool is_match(int card1, int card2);
bool has_won(int board[NUM_ROWS][NUM_COLS]);
void make_move(int board[NUM_ROWS][NUM_COLS], int player, int row, int col);

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the game board
    int board[NUM_ROWS][NUM_COLS];
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            board[i][j] = UNKNOWN;
        }
    }

    // Place the cards on the board
    int cards[NUM_ROWS * NUM_COLS / 2];
    for (int i = 0; i < NUM_ROWS * NUM_COLS / 2; i++) {
        cards[i] = i;
    }

    for (int i = 0; i < NUM_ROWS * NUM_COLS / 2; i++) {
        int j = rand() % (NUM_ROWS * NUM_COLS / 2);
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }

    int k = 0;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            board[i][j] = cards[k++];
        }
    }

    // Print the board
    print_board(board);

    // Get the first player's move
    printf("Player 1, enter your move (row, col): ");
    int row1, col1;
    scanf("%d %d", &row1, &col1);

    // Make the move
    make_move(board, HUMAN, row1, col1);

    // Print the board
    print_board(board);

    // Get the second player's move
    printf("Player 2, enter your move (row, col): ");
    int row2, col2;
    scanf("%d %d", &row2, &col2);

    // Make the move
    make_move(board, HUMAN, row2, col2);

    // Print the board
    print_board(board);

    // Check for a winner
    if (has_won(board)) {
        printf("Player 2 wins!\n");
    } else {
        printf("No winner yet.\n");
    }

    return 0;
}

// Function to print the board
void print_board(int board[NUM_ROWS][NUM_COLS]) {
    printf("    ");
    for (int i = 0; i < NUM_COLS; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    for (int i = 0; i < NUM_ROWS; i++) {
        printf("%2d ", i);
        for (int j = 0; j < NUM_COLS; j++) {
            switch (board[i][j]) {
                case UNKNOWN:
                    printf("?? ");
                    break;
                case MATCH:
                    printf("__ ");
                    break;
                case MISMATCH:
                    printf("XX ");
                    break;
                default:
                    printf("%2d ", board[i][j]);
                    break;
            }
        }
        printf("\n");
    }
}

// Function to check if two cards match
bool is_match(int card1, int card2) {
    return card1 == card2;
}

// Function to check if the board has been won
bool has_won(int board[NUM_ROWS][NUM_COLS]) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (board[i][j] == UNKNOWN) {
                return false;
            }
        }
    }
    return true;
}

// Function to make a move
void make_move(int board[NUM_ROWS][NUM_COLS], int player, int row, int col) {
    if (board[row][col] == UNKNOWN) {
        board[row][col] = player;
    } else if (board[row][col] == player) {
        board[row][col] = MATCH;
    } else {
        board[row][col] = MISMATCH;
    }
}