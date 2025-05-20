//FormAI DATASET v1.0 Category: Memory Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 4
#define NUM_COLS 4

// Initialize the game board with random numbers
void init_board(int board[NUM_ROWS][NUM_COLS]) {
    // Use current time as seed for random generator
    srand(time(NULL));

    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            board[i][j] = rand() % 10;
        }
    }
}

// Print the game board
void print_board(int board[NUM_ROWS][NUM_COLS]) {
    printf("Memory Game:\n\n");

    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Check if two cards match
int match_cards(int board[NUM_ROWS][NUM_COLS], int row1, int col1, int row2, int col2) {
    if (board[row1][col1] == board[row2][col2]) {
        return 1;
    } else {
        return 0;
    }
}

// Flip a card
void flip_card(int board[NUM_ROWS][NUM_COLS], int row, int col) {
    board[row][col] = -1;
}

// Determine if the game is over
int game_over(int board[NUM_ROWS][NUM_COLS]) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (board[i][j] != -1) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int board[NUM_ROWS][NUM_COLS];
    int row1, col1, row2, col2;
    int num_flips = 0;
    int num_matches = 0;

    init_board(board);

    while (!game_over(board)) {
        print_board(board);

        // Get first card
        printf("Enter the row and column of the first card: ");
        scanf("%d %d", &row1, &col1);
        flip_card(board, row1, col1);

        // Get second card
        printf("Enter the row and column of the second card: ");
        scanf("%d %d", &row2, &col2);
        flip_card(board, row2, col2);

        if (match_cards(board, row1, col1, row2, col2)) {
            printf("Match!\n");
            num_matches++;
        } else {
            printf("No match.\n");
            flip_card(board, row1, col1);
            flip_card(board, row2, col2);
        }

        num_flips += 2;
    }

    printf("Game over!\n");
    printf("Number of flips: %d\n", num_flips);
    printf("Number of matches: %d\n", num_matches);

    return 0;
}