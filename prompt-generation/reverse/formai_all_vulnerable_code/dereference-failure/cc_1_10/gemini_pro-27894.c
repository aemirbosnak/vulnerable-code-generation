//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bingo card dimensions
#define ROWS 5
#define COLS 5

// Maximum number on a bingo card
#define MAX_NUM 75

// Function to create a new bingo card
int** create_card() {
    // Allocate memory for the card
    int** card = (int**)malloc(sizeof(int*) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        card[i] = (int*)malloc(sizeof(int) * COLS);
    }

    // Fill the card with random numbers
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            card[i][j] = rand() % MAX_NUM + 1;
        }
    }

    // Return the card
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
int check_card(int** card, int num) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to play a round of bingo
int play_round(int** card, int num) {
    // Check if the number is on the card
    if (check_card(card, num)) {
        // Mark the number as called
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (card[i][j] == num) {
                    card[i][j] = -1;
                }
            }
        }

        // Check if the card has won
        if (check_win(card)) {
            return 1;
        }
    }

    // The card has not won
    return 0;
}

// Function to check if a bingo card has won
int check_win(int** card) {
    // Check for horizontal wins
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

    // Check for vertical wins
    for (int j = 0; j < COLS; j++) {
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            if (card[i][j] == -1) {
                count++;
            }
        }
        if (count == ROWS) {
            return 1;
        }
    }

    // Check for diagonal wins
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < ROWS; i++) {
        if (card[i][i] == -1) {
            count1++;
        }
        if (card[i][ROWS - 1 - i] == -1) {
            count2++;
        }
    }
    if (count1 == ROWS || count2 == ROWS) {
        return 1;
    }

    // The card has not won
    return 0;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new bingo card
    int** card = create_card();

    // Print the bingo card
    printf("Your bingo card:\n");
    print_card(card);

    // Play the game
    int num;
    while (1) {
        // Get a random number
        num = rand() % MAX_NUM + 1;

        // Print the number
        printf("Number called: %d\n", num);

        // Play the round
        if (play_round(card, num)) {
            // The card has won
            printf("You won!\n");
            break;
        }
    }

    // Free the memory allocated for the card
    for (int i = 0; i < ROWS; i++) {
        free(card[i]);
    }
    free(card);

    return 0;
}