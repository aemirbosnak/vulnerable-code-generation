//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define a bingo card
typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces[24];
    int numWins;
} BingoCard;

// Create a bingo card
BingoCard* createBingoCard() {
    BingoCard* card = malloc(sizeof(BingoCard));
    card->numWins = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->numbers[i][j] = 0;
        }
    }
    for (int i = 0; i < 24; i++) {
        card->freeSpaces[i] = 0;
    }
    return card;
}

// Mark a number on a bingo card
void markNumber(BingoCard* card, int number) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (card->numbers[i][j] == number) {
                card->freeSpaces[i * 5 + j] = 1;
            }
        }
    }
}

// Check if a bingo card has won
int hasWon(BingoCard* card) {
    // Check rows
    for (int i = 0; i < 5; i++) {
        if (card->freeSpaces[i * 5] == 5) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 5; j++) {
        if (card->freeSpaces[j] == 5) {
            return 1;
        }
    }

    // Check diagonals
    if (card->freeSpaces[0] == 5 && card->freeSpaces[6] == 5) {
        return 1;
    }
    if (card->freeSpaces[1] == 5 && card->freeSpaces[7] == 5) {
        return 1;
    }

    return 0;
}

// Main game loop
int main() {
    // Create a bingo card
    BingoCard* card = createBingoCard();

    // Mark numbers on the card
    markNumber(card, 1);
    markNumber(card, 2);
    markNumber(card, 3);
    markNumber(card, 4);
    markNumber(card, 5);

    // Check if the card has won
    if (hasWon(card)) {
        printf("You have won!");
    } else {
        printf("You have not won.");
    }

    return 0;
}