//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a bingo card
typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces[25];
    int numWins;
} BingoCard;

// Function to generate a bingo card
BingoCard* generateBingoCard() {
    BingoCard* card = malloc(sizeof(BingoCard));
    card->numWins = 0;

    // Generate the numbers for the card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->numbers[i][j] = rand() % 90 + 1;
        }
    }

    // Mark the free spaces on the card
    for (int i = 0; i < 25; i++) {
        card->freeSpaces[i] = 1;
    }

    return card;
}

// Function to mark a space on a bingo card
void markSpace(BingoCard* card, int number) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (card->numbers[i][j] == number) {
                card->freeSpaces[i * 5 + j] = 0;
            }
        }
    }
}

// Function to check if a bingo card has won
int hasWon(BingoCard* card) {
    // Check for a win in the rows
    for (int i = 0; i < 5; i++) {
        if (card->freeSpaces[i * 5] == 0) {
            return 1;
        }
    }

    // Check for a win in the columns
    for (int j = 0; j < 5; j++) {
        if (card->freeSpaces[j] == 0) {
            return 1;
        }
    }

    // Check for a win in the diagonals
    if (card->freeSpaces[0] == 0 && card->freeSpaces[6] == 0) {
        return 1;
    }

    // If no win, return 0
    return 0;
}

int main() {
    // Create a bingo card
    BingoCard* card = generateBingoCard();

    // Mark spaces on the card
    markSpace(card, 12);
    markSpace(card, 24);
    markSpace(card, 36);

    // Check if the card has won
    if (hasWon(card)) {
        printf("You have won!");
    } else {
        printf("You have not won.");
    }

    return 0;
}