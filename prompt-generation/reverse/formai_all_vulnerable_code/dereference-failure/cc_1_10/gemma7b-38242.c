//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 25

// Bingo Card Structure
typedef struct BingoCard {
    int numbers[MAX_NUM];
    int markedNumbers[MAX_NUM];
    int numMarked;
} BingoCard;

// Function to generate a bingo card
BingoCard *generateBingoCard() {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->numMarked = 0;
    for (int i = 0; i < MAX_NUM; i++) {
        card->numbers[i] = rand() % MAX_NUM + 1;
        card->markedNumbers[i] = 0;
    }
    return card;
}

// Function to mark a number on a bingo card
void markNumber(BingoCard *card, int number) {
    for (int i = 0; i < MAX_NUM; i++) {
        if (card->numbers[i] == number && card->markedNumbers[i] == 0) {
            card->markedNumbers[i] = 1;
            card->numMarked++;
        }
    }
}

// Function to check if a card has won
int hasWon(BingoCard *card) {
    // Check rows
    for (int i = 0; i < MAX_NUM; i++) {
        if (card->markedNumbers[i] == card->numMarked) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < MAX_NUM; i++) {
        int columnWon = 1;
        for (int j = 0; j < MAX_NUM; j++) {
            if (card->markedNumbers[j] != card->numMarked) {
                columnWon = 0;
            }
        }
        if (columnWon) {
            return 1;
        }
    }

    // Check diagonals
    if (card->markedNumbers[0] == card->numMarked && card->markedNumbers[5] == card->numMarked) {
        return 1;
    }
    if (card->markedNumbers[1] == card->numMarked && card->markedNumbers[6] == card->numMarked) {
        return 1;
    }

    return 0;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a bingo card
    BingoCard *card = generateBingoCard();

    // Mark numbers on the card
    markNumber(card, 12);
    markNumber(card, 15);
    markNumber(card, 19);
    markNumber(card, 22);
    markNumber(card, 24);

    // Check if the card has won
    if (hasWon(card)) {
        printf("You have won!");
    } else {
        printf("You have not won.");
    }

    return 0;
}