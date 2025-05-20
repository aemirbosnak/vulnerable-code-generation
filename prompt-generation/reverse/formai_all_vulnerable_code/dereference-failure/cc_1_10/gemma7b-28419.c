//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a bingo card structure
typedef struct BingoCard {
    int numbers[5][5];
    int cardsWon;
} BingoCard;

// Function to generate a bingo card
BingoCard* generateBingoCard() {
    BingoCard* card = malloc(sizeof(BingoCard));
    card->cardsWon = 0;

    // Populate the card with random numbers
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->numbers[i][j] = rand() % 90 + 1;
        }
    }

    return card;
}

// Function to check if a card has won
int checkBingo(BingoCard* card) {
    // Check rows
    for (int i = 0; i < 5; i++) {
        if (card->numbers[i][0] == card->numbers[i][1] &&
            card->numbers[i][0] == card->numbers[i][2] &&
            card->numbers[i][0] == card->numbers[i][3] &&
            card->numbers[i][0] == card->numbers[i][4]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 5; j++) {
        if (card->numbers[0][j] == card->numbers[1][j] &&
            card->numbers[0][j] == card->numbers[2][j] &&
            card->numbers[0][j] == card->numbers[3][j] &&
            card->numbers[0][j] == card->numbers[4][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (card->numbers[0][0] == card->numbers[2][2] &&
        card->numbers[0][0] == card->numbers[4][4]) {
        return 1;
    }

    return 0;
}

int main() {
    // Generate a bingo card
    BingoCard* card = generateBingoCard();

    // Draw numbers
    for (int i = 0; i < 20; i++) {
        int number = rand() % 90 + 1;

        // Check if the number is on the card
        if (card->numbers[number / 5][number % 5] != 0) {
            // Mark the number as called
            card->numbers[number / 5][number % 5] = -1;

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