//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the bingo card size
#define CARD_SIZE 5

// Define the number of bingo cards to generate
#define NUM_CARDS 10

// Define the range of numbers for the bingo balls
#define MIN_BALL 1
#define MAX_BALL 75

// Create a bingo card
int **create_card() {
    // Allocate memory for the bingo card
    int **card = (int **)malloc(CARD_SIZE * sizeof(int *));
    for (int i = 0; i < CARD_SIZE; i++) {
        card[i] = (int *)malloc(CARD_SIZE * sizeof(int));
    }

    // Generate random numbers for the bingo card
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            card[i][j] = (rand() % (MAX_BALL - MIN_BALL + 1)) + MIN_BALL;
        }
    }

    // Return the bingo card
    return card;
}

// Print a bingo card
void print_card(int **card) {
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }
}

// Check if a bingo card has won
int check_card(int **card, int ball) {
    // Check each row
    for (int i = 0; i < CARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < CARD_SIZE; j++) {
            if (card[i][j] == ball) {
                count++;
            }
        }
        if (count == CARD_SIZE) {
            return 1;
        }
    }

    // Check each column
    for (int i = 0; i < CARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < CARD_SIZE; j++) {
            if (card[j][i] == ball) {
                count++;
            }
        }
        if (count == CARD_SIZE) {
            return 1;
        }
    }

    // Check each diagonal
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < CARD_SIZE; i++) {
        if (card[i][i] == ball) {
            count1++;
        }
        if (card[i][CARD_SIZE - 1 - i] == ball) {
            count2++;
        }
    }
    if (count1 == CARD_SIZE || count2 == CARD_SIZE) {
        return 1;
    }

    // No winning combination found
    return 0;
}

// Play a bingo game
void play_bingo() {
    // Create a list of bingo cards
    int ***cards = (int ***)malloc(NUM_CARDS * sizeof(int **));
    for (int i = 0; i < NUM_CARDS; i++) {
        cards[i] = create_card();
    }

    // Print the bingo cards
    for (int i = 0; i < NUM_CARDS; i++) {
        printf("Bingo Card %d:\n", i + 1);
        print_card(cards[i]);
        printf("\n");
    }

    // Generate random bingo balls until a winner is found
    int ball;
    int winner_found = 0;
    while (!winner_found) {
        ball = (rand() % (MAX_BALL - MIN_BALL + 1)) + MIN_BALL;
        printf("Bingo ball: %d\n", ball);

        // Check each bingo card for a winner
        for (int i = 0; i < NUM_CARDS; i++) {
            if (check_card(cards[i], ball)) {
                printf("Bingo! Card %d wins!\n", i + 1);
                winner_found = 1;
                break;
            }
        }
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Play a bingo game
    play_bingo();

    return 0;
}