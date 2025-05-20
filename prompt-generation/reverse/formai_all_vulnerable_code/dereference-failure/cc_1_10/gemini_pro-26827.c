//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bingo card dimensions
#define ROWS 5
#define COLS 5

// Number of balls to draw
#define BALLS_TO_DRAW 75

// Function to create a new bingo card
int** create_card() {
    // Allocate memory for the card
    int** card = malloc(ROWS * sizeof(int*));
    for (int i = 0; i < ROWS; i++) {
        card[i] = malloc(COLS * sizeof(int));
    }

    // Generate random numbers for the card
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            card[i][j] = rand() % 90 + 1;
        }
    }

    // Return the card
    return card;
}

// Function to print a bingo card
void print_card(int** card) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", card[i][j]);
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

// Function to play a round of bingo
void play_round(int** card, int* balls_drawn) {
    // Draw a random ball
    int ball = rand() % 90 + 1;

    // Check if the ball has already been drawn
    if (balls_drawn[ball] == 1) {
        return;
    }

    // Mark the ball as drawn
    balls_drawn[ball] = 1;

    // Check if the ball is on the card
    if (check_number(card, ball)) {
        printf("Ball %d is on your card!\n", ball);
    }
}

// Function to check if a bingo has been won
int check_bingo(int** card) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == 0) {
                count++;
            }
        }
        if (count == COLS) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++) {
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            if (card[i][j] == 0) {
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
        if (card[i][i] == 0) {
            count1++;
        }
        if (card[i][ROWS - i - 1] == 0) {
            count2++;
        }
    }
    if (count1 == ROWS || count2 == ROWS) {
        return 1;
    }

    // No bingo yet
    return 0;
}

// Main function
int main() {
    // Create a new bingo card
    int** card = create_card();

    // Print the bingo card
    printf("Your bingo card:\n");
    print_card(card);

    // Create an array to store the balls that have been drawn
    int* balls_drawn = malloc(91 * sizeof(int));
    for (int i = 0; i < 91; i++) {
        balls_drawn[i] = 0;
    }

    // Play rounds of bingo until a bingo is won
    int bingo = 0;
    int rounds = 0;
    while (!bingo) {
        // Play a round of bingo
        play_round(card, balls_drawn);

        // Check if a bingo has been won
        bingo = check_bingo(card);

        // Increment the round count
        rounds++;
    }

    // Print the number of rounds it took to win bingo
    printf("You won bingo in %d rounds!\n", rounds);

    // Free the memory allocated for the bingo card and the array of balls drawn
    for (int i = 0; i < ROWS; i++) {
        free(card[i]);
    }
    free(card);
    free(balls_drawn);

    return 0;
}