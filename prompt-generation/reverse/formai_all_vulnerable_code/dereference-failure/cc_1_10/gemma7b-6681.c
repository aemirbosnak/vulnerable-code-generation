//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a Bingo Card
typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces;
    int cardsWon;
} BingoCard;

// Function to generate a bingo card
BingoCard* generateBingoCard() {
    BingoCard* card = malloc(sizeof(BingoCard));
    card->freeSpaces = 24;
    card->cardsWon = 0;

    // Generate the numbers for the card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->numbers[i][j] = rand() % 90 + 1;
        }
    }

    return card;
}

// Function to check if a card has won
int hasWon(BingoCard* card) {
    // Check for a win in the rows
    for (int i = 0; i < 5; i++) {
        if (card->numbers[0][i] == card->numbers[1][i] && card->numbers[0][i] == card->numbers[2][i] && card->numbers[0][i] == card->numbers[3][i] && card->numbers[0][i] == card->numbers[4][i]) {
            return 1;
        }
    }

    // Check for a win in the columns
    for (int j = 0; j < 5; j++) {
        if (card->numbers[j][0] == card->numbers[j][1] && card->numbers[j][0] == card->numbers[j][2] && card->numbers[j][0] == card->numbers[j][3] && card->numbers[j][0] == card->numbers[j][4]) {
            return 1;
        }
    }

    // Check for a win in the diagonals
    if (card->numbers[0][0] == card->numbers[1][1] && card->numbers[0][0] == card->numbers[2][2] && card->numbers[0][0] == card->numbers[3][3] && card->numbers[0][0] == card->numbers[4][4]) {
        return 1;
    }

    // If no wins, return 0
    return 0;
}

// Main game loop
int main() {
    // Create a bingo card
    BingoCard* card = generateBingoCard();

    // Print the bingo card
    printf("Your bingo card:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", card->numbers[i][j]);
        }
        printf("\n");
    }

    // Simulate the drawing of numbers
    for (int i = 0; i < 10; i++) {
        // Draw a number
        int number = rand() % 90 + 1;

        // Check if the number is on the card
        if (card->numbers[card->freeSpaces][0] == number) {
            // Mark the space as occupied
            card->freeSpaces--;

            // Check if the card has won
            if (hasWon(card)) {
                // Increment the number of cards won
                card->cardsWon++;

                // Print a winning message
                printf("Congratulations! You have won %d cards!\n", card->cardsWon);
            }
        }
    }

    // Free the memory allocated for the card
    free(card);

    return 0;
}