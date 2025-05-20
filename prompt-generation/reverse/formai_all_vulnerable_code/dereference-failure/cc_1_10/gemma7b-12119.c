//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the Bingo Card Structure
typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces;
    int linesCompleted;
} BingoCard;

// Function to generate a Bingo Card
BingoCard* generateBingoCard() {
    BingoCard* card = malloc(sizeof(BingoCard));
    card->freeSpaces = 24;
    card->linesCompleted = 0;

    // Generate the numbers for the card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->numbers[i][j] = rand() % 90 + 1;
        }
    }

    return card;
}

// Function to check if a number is on the Bingo Card
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

// Function to mark a number on the Bingo Card
void markNumberOnCard(BingoCard* card, int number) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (card->numbers[i][j] == number) {
                card->numbers[i][j] = -1;
                card->freeSpaces--;
            }
        }
    }
}

// Function to check if the Bingo Card is complete
int isCardComplete(BingoCard* card) {
    // Check if all lines are complete
    for (int i = 0; i < 5; i++) {
        int isLineComplete = 1;
        for (int j = 0; j < 5; j++) {
            if (card->numbers[i][j] != -1) {
                isLineComplete = 0;
            }
        }

        if (isLineComplete) {
            card->linesCompleted++;
        }
    }

    // Check if the card is complete
    return card->linesCompleted == 3;
}

int main() {
    // Generate a Bingo Card
    BingoCard* card = generateBingoCard();

    // Print the Bingo Card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", card->numbers[i][j]);
        }
        printf("\n");
    }

    // Draw numbers
    for (int i = 0; i < 20; i++) {
        int number = rand() % 90 + 1;

        // Check if the number is on the card
        if (isNumberOnCard(card, number)) {
            // Mark the number on the card
            markNumberOnCard(card, number);

            // Check if the card is complete
            if (isCardComplete(card)) {
                printf("Bingo!\n");
            }
        }
    }

    return 0;
}