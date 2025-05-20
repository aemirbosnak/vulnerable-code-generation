//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bingo card dimensions
#define CARD_WIDTH 5
#define CARD_HEIGHT 5

// Number of balls to draw
#define NUM_BALLS 75

// Create a bingo card
int** create_card() {
    // Allocate memory for the card
    int** card = malloc(CARD_HEIGHT * sizeof(int*));
    for (int i = 0; i < CARD_HEIGHT; i++) {
        card[i] = malloc(CARD_WIDTH * sizeof(int));
    }

    // Initialize the card with random numbers
    srand(time(NULL));
    for (int i = 0; i < CARD_HEIGHT; i++) {
        for (int j = 0; j < CARD_WIDTH; j++) {
            card[i][j] = rand() % NUM_BALLS + 1;
        }
    }

    return card;
}

// Print a bingo card
void print_card(int** card) {
    for (int i = 0; i < CARD_HEIGHT; i++) {
        for (int j = 0; j < CARD_WIDTH; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

// Check if a card has won
int check_card(int** card, int ball) {
    // Check each row
    for (int i = 0; i < CARD_HEIGHT; i++) {
        int count = 0;
        for (int j = 0; j < CARD_WIDTH; j++) {
            if (card[i][j] == ball) {
                count++;
            }
        }
        if (count == CARD_WIDTH) {
            return 1;
        }
    }

    // Check each column
    for (int j = 0; j < CARD_WIDTH; j++) {
        int count = 0;
        for (int i = 0; i < CARD_HEIGHT; i++) {
            if (card[i][j] == ball) {
                count++;
            }
        }
        if (count == CARD_HEIGHT) {
            return 1;
        }
    }

    // Check each diagonal
    int count1 = 0;
    for (int i = 0; i < CARD_HEIGHT; i++) {
        if (card[i][i] == ball) {
            count1++;
        }
    }
    if (count1 == CARD_HEIGHT) {
        return 1;
    }

    int count2 = 0;
    for (int i = 0; i < CARD_HEIGHT; i++) {
        if (card[i][CARD_WIDTH - i - 1] == ball) {
            count2++;
        }
    }
    if (count2 == CARD_HEIGHT) {
        return 1;
    }

    // No winner yet
    return 0;
}

// Play a game of bingo
void play_bingo() {
    // Create a bingo card
    int** card = create_card();

    // Print the bingo card
    printf("Your bingo card:\n");
    print_card(card);

    // Draw balls until someone wins
    int balls_drawn = 0;
    int winner = 0;
    while (!winner && balls_drawn < NUM_BALLS) {
        // Draw a ball
        int ball = rand() % NUM_BALLS + 1;
        printf("Ball drawn: %d\n", ball);

        // Check if the card has won
        winner = check_card(card, ball);

        // Increment the number of balls drawn
        balls_drawn++;
    }

    // Print the winning message
    if (winner) {
        printf("Congratulations! You won in %d balls!\n", balls_drawn);
    } else {
        printf("Sorry, you didn't win.\n");
    }

    // Free the memory allocated for the card
    for (int i = 0; i < CARD_HEIGHT; i++) {
        free(card[i]);
    }
    free(card);
}

int main() {
    // Play a game of bingo
    play_bingo();

    return 0;
}