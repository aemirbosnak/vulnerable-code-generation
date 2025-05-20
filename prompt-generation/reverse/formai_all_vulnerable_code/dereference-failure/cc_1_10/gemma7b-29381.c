//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define Bingo Card structure
typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces;
} BingoCard;

// Function to generate a Bingo card
BingoCard* generateBingoCard() {
    BingoCard* card = malloc(sizeof(BingoCard));
    card->freeSpaces = 24;

    // Generate random numbers for each space
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

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a Bingo card
    BingoCard* card = generateBingoCard();

    // Print the Bingo card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", card->numbers[i][j]);
        }
        printf("\n");
    }

    // Simulate drawing numbers
    for (int i = 0; i < 10; i++) {
        int number = rand() % 90 + 1;

        // Check if the number is on the card
        if (isNumberOnCard(card, number)) {
            printf("Number %d is on your card!\n", number);
        }
    }

    return 0;
}