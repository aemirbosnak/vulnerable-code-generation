//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Macros for the dimensions of the bingo card
#define CARD_WIDTH 5
#define CARD_HEIGHT 5

// Macro for the number of balls to draw
#define NUM_BALLS 75

// Structure to represent a bingo card
typedef struct {
    int numbers[CARD_WIDTH][CARD_HEIGHT];
    int marked[CARD_WIDTH][CARD_HEIGHT];
} BingoCard;

// Function to create a new bingo card
BingoCard* create_card() {
    BingoCard* card = malloc(sizeof(BingoCard));
    for (int i = 0; i < CARD_WIDTH; i++) {
        for (int j = 0; j < CARD_HEIGHT; j++) {
            // Generate a random number between 1 and 75
            int num = rand() % 75 + 1;
            // Check if the number is already on the card
            while (card->numbers[i][j] == num) {
                num = rand() % 75 + 1;
            }
            // Add the number to the card
            card->numbers[i][j] = num;
            // Set the marked flag to false
            card->marked[i][j] = 0;
        }
    }
    return card;
}

// Function to print a bingo card
void print_card(BingoCard* card) {
    for (int i = 0; i < CARD_WIDTH; i++) {
        for (int j = 0; j < CARD_HEIGHT; j++) {
            printf("%2d ", card->numbers[i][j]);
        }
        printf("\n");
    }
}

// Function to mark a number on a bingo card
void mark_number(BingoCard* card, int number) {
    for (int i = 0; i < CARD_WIDTH; i++) {
        for (int j = 0; j < CARD_HEIGHT; j++) {
            if (card->numbers[i][j] == number) {
                card->marked[i][j] = 1;
            }
        }
    }
}

// Function to check if a bingo card has won
int check_win(BingoCard* card) {
    // Check for horizontal wins
    for (int i = 0; i < CARD_WIDTH; i++) {
        int count = 0;
        for (int j = 0; j < CARD_HEIGHT; j++) {
            count += card->marked[i][j];
        }
        if (count == CARD_HEIGHT) {
            return 1;
        }
    }

    // Check for vertical wins
    for (int i = 0; i < CARD_HEIGHT; i++) {
        int count = 0;
        for (int j = 0; j < CARD_WIDTH; j++) {
            count += card->marked[j][i];
        }
        if (count == CARD_WIDTH) {
            return 1;
        }
    }

    // Check for diagonal wins
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < CARD_WIDTH; i++) {
        count1 += card->marked[i][i];
        count2 += card->marked[i][CARD_WIDTH - i - 1];
    }
    if (count1 == CARD_WIDTH || count2 == CARD_WIDTH) {
        return 1;
    }

    // No win yet
    return 0;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new bingo card
    BingoCard* card = create_card();

    // Print the bingo card
    printf("Your bingo card:\n");
    print_card(card);

    // Draw the bingo balls
    int balls[NUM_BALLS];
    for (int i = 0; i < NUM_BALLS; i++) {
        // Generate a random number between 1 and 75
        int num = rand() % 75 + 1;
        // Check if the number has already been drawn
        while (balls[i] == num) {
            num = rand() % 75 + 1;
        }
        // Add the number to the list of drawn balls
        balls[i] = num;
    }

    // Play the bingo game
    int winner = 0;
    for (int i = 0; i < NUM_BALLS; i++) {
        // Mark the number on the bingo card
        mark_number(card, balls[i]);

        // Check if the bingo card has won
        if (check_win(card)) {
            winner = 1;
            break;
        }

        // Print the number that was drawn
        printf("Ball %d: %d\n", i + 1, balls[i]);
    }

    // Print the result
    if (winner) {
        printf("You won!\n");
    } else {
        printf("You lost!\n");
    }

    return 0;
}