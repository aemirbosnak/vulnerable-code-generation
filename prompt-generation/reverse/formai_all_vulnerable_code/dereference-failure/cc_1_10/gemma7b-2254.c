//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define a Bingo Card structure
typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces;
} BingoCard;

// Function to generate a Bingo card
BingoCard* generateBingoCard() {
    BingoCard* card = malloc(sizeof(BingoCard));
    card->freeSpaces = 24;

    // Generate the numbers for the card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->numbers[i][j] = rand() % 90 + 1;
        }
    }

    return card;
}

// Function to check if a number is on a Bingo card
int isNumberOnCard(BingoCard* card, int number) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (card->numbers[i][j] == number) {
                return 1;
            }
        }
    }

    return 0;
}

// Function to play Bingo
int playBingo(BingoCard* card) {
    // Draw a number
    int number = rand() % 90 + 1;

    // Check if the number is on the card
    if (isNumberOnCard(card, number)) {
        // Mark the number as called
        card->numbers[rand() % 5][rand() % 5] = -1;

        // Check if the card is complete
        if (card->freeSpaces == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    // Generate a Bingo card
    BingoCard* card = generateBingoCard();

    // Play Bingo
    while (!playBingo(card)) {}

    // Print the winner
    printf("Congratulations! You won!");

    return 0;
}