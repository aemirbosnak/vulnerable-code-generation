//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the bingo card size
#define CARD_SIZE 5

// Define the number of bingo cards to generate
#define NUM_CARDS 10

// Define the maximum number of balls to draw
#define MAX_BALLS 75

// Create a bingo card
int** create_card() {
    // Allocate memory for the card
    int** card = (int**)malloc(CARD_SIZE * sizeof(int*));
    for (int i = 0; i < CARD_SIZE; i++) {
        card[i] = (int*)malloc(CARD_SIZE * sizeof(int));
    }

    // Initialize the card with random numbers
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            card[i][j] = rand() % MAX_BALLS + 1;
        }
    }

    return card;
}

// Print a bingo card
void print_card(int** card) {
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

// Check if a card has won
int check_card(int** card, int* balls) {
    // Check for horizontal wins
    for (int i = 0; i < CARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < CARD_SIZE; j++) {
            for (int k = 0; k < MAX_BALLS; k++) {
                if (card[i][j] == balls[k]) {
                    count++;
                }
            }
        }
        if (count == CARD_SIZE) {
            return 1;
        }
    }

    // Check for vertical wins
    for (int i = 0; i < CARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < CARD_SIZE; j++) {
            for (int k = 0; k < MAX_BALLS; k++) {
                if (card[j][i] == balls[k]) {
                    count++;
                }
            }
        }
        if (count == CARD_SIZE) {
            return 1;
        }
    }

    // Check for diagonal wins
    int count1 = 0, count2 = 0;
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int k = 0; k < MAX_BALLS; k++) {
            if (card[i][i] == balls[k]) {
                count1++;
            }
            if (card[i][CARD_SIZE - i - 1] == balls[k]) {
                count2++;
            }
        }
    }
    if (count1 == CARD_SIZE || count2 == CARD_SIZE) {
        return 1;
    }

    return 0;
}

// Play a game of bingo
void play_bingo() {
    // Create a bingo card
    int** card = create_card();

    // Print the bingo card
    printf("Your bingo card:\n");
    print_card(card);

    // Draw balls until a winner is found
    int balls[MAX_BALLS];
    int num_balls = 0;
    while (num_balls < MAX_BALLS) {
        // Draw a ball
        int ball = rand() % MAX_BALLS + 1;

        // Check if the ball has already been drawn
        int found = 0;
        for (int i = 0; i < num_balls; i++) {
            if (balls[i] == ball) {
                found = 1;
                break;
            }
        }

        // If the ball has not been drawn, add it to the list of drawn balls
        if (!found) {
            balls[num_balls++] = ball;

            // Check if the card has won
            if (check_card(card, balls)) {
                printf("You won!\n");
                break;
            }
        }
    }

    // If no winner is found, print a message
    if (num_balls == MAX_BALLS) {
        printf("No winner.\n");
    }

    // Free the memory allocated for the card
    for (int i = 0; i < CARD_SIZE; i++) {
        free(card[i]);
    }
    free(card);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Play a game of bingo
    play_bingo();

    return 0;
}