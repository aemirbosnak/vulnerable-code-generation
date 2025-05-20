//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bingo card size
#define CARD_SIZE 5

// Number of rows and columns in the bingo card
#define ROWS 5
#define COLS 5

// Function to create a new bingo card
int** create_card() {
    // Allocate memory for the bingo card
    int** card = malloc(ROWS * sizeof(int*));
    for (int i = 0; i < ROWS; i++) {
        card[i] = malloc(COLS * sizeof(int));
    }

    // Generate random numbers for the bingo card
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            card[i][j] = rand() % 100 + 1;
        }
    }

    return card;
}

// Function to print a bingo card
void print_card(int** card) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number is on a bingo card
int check_number(int** card, int number) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == number) {
                return 1;
            }
        }
    }

    return 0;
}

// Function to check if a bingo card has won
int check_win(int** card) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == -1) {
                count++;
            }
        }
        if (count == COLS) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < COLS; i++) {
        int count = 0;
        for (int j = 0; j < ROWS; j++) {
            if (card[j][i] == -1) {
                count++;
            }
        }
        if (count == ROWS) {
            return 1;
        }
    }

    // Check diagonals
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < ROWS; i++) {
        if (card[i][i] == -1) {
            count1++;
        }
        if (card[i][ROWS - i - 1] == -1) {
            count2++;
        }
    }
    if (count1 == ROWS || count2 == ROWS) {
        return 1;
    }

    return 0;
}

// Main function
int main() {
    // Create a new bingo card
    int** card = create_card();

    // Print the bingo card
    printf("Your bingo card:\n");
    print_card(card);

    // Play the bingo game
    int number;
    while (1) {
        // Generate a random number
        number = rand() % 100 + 1;

        // Check if the number is on the bingo card
        if (check_number(card, number)) {
            // Mark the number on the bingo card
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (card[i][j] == number) {
                        card[i][j] = -1;
                    }
                }
            }

            // Check if the bingo card has won
            if (check_win(card)) {
                printf("You won!\n");
                break;
            }
        }

        // Print the updated bingo card
        printf("Your bingo card:\n");
        print_card(card);
    }

    // Free the memory allocated for the bingo card
    for (int i = 0; i < ROWS; i++) {
        free(card[i]);
    }
    free(card);

    return 0;
}