//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the Bingo Card
typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces;
    int winningNumbers[5];
} BingoCard;

// Function to generate a Bingo Card
BingoCard* generateBingoCard() {
    BingoCard* card = malloc(sizeof(BingoCard));
    card->freeSpaces = 24;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->numbers[i][j] = 0;
        }
    }
    return card;
}

// Function to mark a number on the Bingo Card
void markNumber(BingoCard* card, int number) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (card->numbers[i][j] == number) {
                card->numbers[i][j] = -1;
                card->freeSpaces--;
            }
        }
    }
}

// Function to check if the Bingo Card has won
int hasWon(BingoCard* card) {
    // Check rows
    for (int i = 0; i < 5; i++) {
        if (card->numbers[i][0] == card->numbers[i][1] && card->numbers[i][0] == card->numbers[i][2] && card->numbers[i][0] == card->numbers[i][3] && card->numbers[i][0] == card->numbers[i][4]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 5; j++) {
        if (card->numbers[0][j] == card->numbers[1][j] && card->numbers[0][j] == card->numbers[2][j] && card->numbers[0][j] == card->numbers[3][j] && card->numbers[0][j] == card->numbers[4][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (card->numbers[0][0] == card->numbers[1][1] && card->numbers[0][0] == card->numbers[2][2] && card->numbers[0][0] == card->numbers[3][3] && card->numbers[0][0] == card->numbers[4][4]) {
        return 1;
    }

    // If no wins, return 0
    return 0;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a Bingo Card
    BingoCard* card = generateBingoCard();

    // Mark a few numbers on the card
    markNumber(card, 12);
    markNumber(card, 15);
    markNumber(card, 21);
    markNumber(card, 24);

    // Check if the card has won
    if (hasWon(card)) {
        printf("You have won!");
    } else {
        printf("You have not won.");
    }

    return 0;
}