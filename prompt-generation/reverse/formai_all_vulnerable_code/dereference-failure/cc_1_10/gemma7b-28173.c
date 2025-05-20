//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the bingo card size
#define CARD_SIZE 5

// Define the number of balls to draw
#define BALLS_TO_DRAW 10

// Define the bingo card format
typedef struct BingoCard {
    int numbers[CARD_SIZE][CARD_SIZE];
    int cardsWon;
} BingoCard;

// Function to generate a bingo card
BingoCard* generateBingoCard() {
    BingoCard* card = malloc(sizeof(BingoCard));
    card->cardsWon = 0;

    // Generate the numbers for the card
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            card->numbers[i][j] = rand() % 90 + 1;
        }
    }

    return card;
}

// Function to check if a card has won
int checkBingo(BingoCard* card) {
    // Check if the card has won in a row
    for (int i = 0; i < CARD_SIZE; i++) {
        // Check if all numbers in a row are the same
        for (int j = 0; j < CARD_SIZE; j++) {
            if (card->numbers[i][j] == card->numbers[i][0] && card->numbers[i][j] != 0) {
                return 1;
            }
        }
    }

    // Check if the card has won in a column
    for (int j = 0; j < CARD_SIZE; j++) {
        // Check if all numbers in a column are the same
        for (int i = 0; i < CARD_SIZE; i++) {
            if (card->numbers[i][j] == card->numbers[0][j] && card->numbers[i][j] != 0) {
                return 1;
            }
        }
    }

    // Check if the card has won in the diagonal
    if (card->numbers[0][0] == card->numbers[CARD_SIZE - 1][CARD_SIZE - 1] && card->numbers[0][0] != 0) {
        return 1;
    }

    return 0;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a bingo card
    BingoCard* card = generateBingoCard();

    // Draw the balls
    for (int i = 0; i < BALLS_TO_DRAW; i++) {
        // Get the number of the ball
        int number = rand() % 90 + 1;

        // Check if the ball has been called
        if (card->numbers[number][number] == 0) {
            // Mark the ball as called
            card->numbers[number][number] = 1;

            // Check if the card has won
            if (checkBingo(card)) {
                // Increment the number of cards won
                card->cardsWon++;

                // Print the winning card
                printf("Congratulations! You have won %d cards!\n", card->cardsWon);
            }
        }
    }

    return 0;
}