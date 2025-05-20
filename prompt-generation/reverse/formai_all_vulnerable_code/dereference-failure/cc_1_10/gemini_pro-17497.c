//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the game board
void initialize_board(char board[][4]) {
    int i, j;

    // Set all board positions to ' ' (empty)
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the game board
void print_board(char board[][4]) {
    int i, j;

    printf("\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to get a random number between 0 and 3
int get_random_number() {
    return rand() % 4;
}

// Function to check if two positions have the same character
int check_match(char board[][4], int row1, int col1, int row2, int col2) {
    return board[row1][col1] == board[row2][col2];
}

// Function to play the game
void play_game() {
    char board[4][4];
    int i, j, row1, col1, row2, col2, count = 0;

    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the game board
    initialize_board(board);

    // Print the initial game board
    print_board(board);

    // Loop until all pairs have been matched
    while (count < 8) {
        // Get the first position
        printf("\nEnter the coordinates of the first card (row, column): ");
        scanf("%d %d", &row1, &col1);

        // Uncover the first position
        board[row1][col1] = get_random_number() + 'A';

        // Print the game board
        print_board(board);

        // Get the second position
        printf("\nEnter the coordinates of the second card (row, column): ");
        scanf("%d %d", &row2, &col2);

        // Uncover the second position
        board[row2][col2] = get_random_number() + 'A';

        // Print the game board
        print_board(board);

        // Check if the two positions have the same character
        if (check_match(board, row1, col1, row2, col2)) {
            count++;
            printf("\nMatch found!\n");
        } else {
            printf("\nNo match found. Try again.\n");
        }

        // Cover the two positions
        board[row1][col1] = ' ';
        board[row2][col2] = ' ';
    }

    // Print a congratulatory message
    printf("\nCongratulations! You have matched all the pairs!\n");
}

int main() {
    // Play the game
    play_game();

    return 0;
}