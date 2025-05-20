//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bingo card dimensions
#define CARD_WIDTH 5
#define CARD_HEIGHT 5

// Number of rows and columns in a square
#define SQUARE_SIZE 2

// Constants for the different types of squares
#define FREE_SQUARE -1
#define BINGO_SQUARE -2

// Function to create a new bingo card
int** create_card() {
    // Allocate memory for the card
    int** card = malloc(CARD_HEIGHT * sizeof(int*));
    for (int i = 0; i < CARD_HEIGHT; i++) {
        card[i] = malloc(CARD_WIDTH * sizeof(int));
    }

    // Initialize the card with empty squares
    for (int i = 0; i < CARD_HEIGHT; i++) {
        for (int j = 0; j < CARD_WIDTH; j++) {
            card[i][j] = 0;
        }
    }

    // Return the card
    return card;
}

// Function to free the memory allocated for a bingo card
void free_card(int** card) {
    for (int i = 0; i < CARD_HEIGHT; i++) {
        free(card[i]);
    }
    free(card);
}

// Function to print a bingo card
void print_card(int** card) {
    for (int i = 0; i < CARD_HEIGHT; i++) {
        for (int j = 0; j < CARD_WIDTH; j++) {
            if (card[i][j] == FREE_SQUARE) {
                printf("X");
            } else if (card[i][j] == BINGO_SQUARE) {
                printf("B");
            } else {
                printf("%d", card[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to check if a square is free
int is_free_square(int** card, int i, int j) {
    return card[i][j] == FREE_SQUARE;
}

// Function to check if a square is a bingo square
int is_bingo_square(int** card, int i, int j) {
    return card[i][j] == BINGO_SQUARE;
}

// Function to check if a square is empty
int is_empty_square(int** card, int i, int j) {
    return card[i][j] == 0;
}

// Function to check if a row is a bingo row
int is_bingo_row(int** card, int i) {
    for (int j = 0; j < CARD_WIDTH; j++) {
        if (!is_bingo_square(card, i, j)) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a column is a bingo column
int is_bingo_column(int** card, int j) {
    for (int i = 0; i < CARD_HEIGHT; i++) {
        if (!is_bingo_square(card, i, j)) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a diagonal is a bingo diagonal
int is_bingo_diagonal(int** card) {
    if (is_bingo_square(card, 0, 0) && is_bingo_square(card, 1, 1) && is_bingo_square(card, 2, 2) && is_bingo_square(card, 3, 3) && is_bingo_square(card, 4, 4)) {
        return 1;
    } else if (is_bingo_square(card, 0, 4) && is_bingo_square(card, 1, 3) && is_bingo_square(card, 2, 2) && is_bingo_square(card, 3, 1) && is_bingo_square(card, 4, 0)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if a bingo card is a winning card
int is_winning_card(int** card) {
    // Check if any row is a bingo row
    for (int i = 0; i < CARD_HEIGHT; i++) {
        if (is_bingo_row(card, i)) {
            return 1;
        }
    }

    // Check if any column is a bingo column
    for (int j = 0; j < CARD_WIDTH; j++) {
        if (is_bingo_column(card, j)) {
            return 1;
        }
    }

    // Check if any diagonal is a bingo diagonal
    if (is_bingo_diagonal(card)) {
        return 1;
    }

    // If no rows, columns, or diagonals are bingo, then the card is not a winning card
    return 0;
}

// Function to play a game of bingo
void play_bingo() {
    // Create a new bingo card
    int** card = create_card();

    // Print the bingo card
    printf("Your bingo card:\n");
    print_card(card);

    // Generate random numbers until someone wins
    int number;
    while (!is_winning_card(card)) {
        // Generate a random number
        number = (rand() % (CARD_WIDTH * CARD_HEIGHT)) + 1;

        // Find the square with the corresponding number
        int i, j;
        for (i = 0; i < CARD_HEIGHT; i++) {
            for (j = 0; j < CARD_WIDTH; j++) {
                if (card[i][j] == number) {
                    break;
                }
            }
        }

        // Mark the square as a bingo square
        card[i][j] = BINGO_SQUARE;

        // Print the updated bingo card
        printf("Your bingo card:\n");
        print_card(card);
    }

    // Print a message to the user indicating that they have won
    printf("Congratulations! You have won bingo!\n");

    // Free the memory allocated for the bingo card
    free_card(card);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Play a game of bingo
    play_bingo();

    return 0;
}