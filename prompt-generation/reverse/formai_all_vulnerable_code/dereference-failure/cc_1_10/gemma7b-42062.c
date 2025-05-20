//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the bingo card structure
typedef struct BingoCard {
    int numbers[5][5];
    int bingo[5];
} BingoCard;

// Function to generate a bingo card
BingoCard* generateBingoCard() {
    BingoCard* card = (BingoCard*)malloc(sizeof(BingoCard));

    // Generate the numbers for the card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->numbers[i][j] = rand() % 90 + 1;
        }
    }

    // Mark the numbers that have already been called
    for (int i = 0; i < 5; i++) {
        card->bingo[i] = 0;
    }

    return card;
}

// Function to check if a bingo card has won
int checkBingo(BingoCard* card) {
    // Check the rows
    for (int i = 0; i < 5; i++) {
        if (card->bingo[i] == 5) {
            return 1;
        }
    }

    // Check the columns
    for (int j = 0; j < 5; j++) {
        if (card->bingo[j] == 5) {
            return 1;
        }
    }

    // Check the diagonals
    if (card->bingo[2] == 5 && card->bingo[4] == 5) {
        return 1;
    }

    return 0;
}

int main() {
    // Create two bingo cards
    BingoCard* card1 = generateBingoCard();
    BingoCard* card2 = generateBingoCard();

    // Simulate the bingo drawing
    for (int i = 0; i < 20; i++) {
        // Generate a random number
        int number = rand() % 90 + 1;

        // Check if the number has already been called
        if (card1->bingo[number] == 0 && card2->bingo[number] == 0) {
            // Call the number
            printf("%d ", number);

            // Mark the number as called
            card1->bingo[number] = 1;
            card2->bingo[number] = 1;

            // Check if either card has won
            if (checkBingo(card1) || checkBingo(card2)) {
                printf("Winner!");
            }
        }
    }

    return 0;
}