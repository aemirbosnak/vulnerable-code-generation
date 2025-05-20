//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the bingo card structure
typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces;
    int winStatus;
} BingoCard;

// Function to generate a bingo card
BingoCard* generateBingoCard() {
    BingoCard* card = malloc(sizeof(BingoCard));
    card->freeSpaces = 24;
    card->winStatus = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->numbers[i][j] = 0;
        }
    }

    return card;
}

// Function to mark a number on the bingo card
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

// Function to check if the player has won
int hasWon(BingoCard* card) {
    // Check rows
    for (int i = 0; i < 5; i++) {
        if (card->numbers[i][0] == card->numbers[i][1] &&
            card->numbers[i][0] == card->numbers[i][2] &&
            card->numbers[i][0] == card->numbers[i][3] &&
            card->numbers[i][0] == card->numbers[i][4] &&
            card->numbers[i][0] != -1) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 5; j++) {
        if (card->numbers[0][j] == card->numbers[1][j] &&
            card->numbers[0][j] == card->numbers[2][j] &&
            card->numbers[0][j] == card->numbers[3][j] &&
            card->numbers[0][j] == card->numbers[4][j] &&
            card->numbers[0][j] != -1) {
            return 1;
        }
    }

    // Check diagonals
    if (card->numbers[0][0] == card->numbers[2][2] &&
        card->numbers[0][0] == card->numbers[4][4] &&
        card->numbers[0][0] != -1) {
        return 1;
    }

    // If no wins, return 0
    return 0;
}

int main() {
    // Generate a bingo card
    BingoCard* card = generateBingoCard();

    // Mark numbers on the card
    markNumber(card, 12);
    markNumber(card, 24);
    markNumber(card, 36);
    markNumber(card, 48);
    markNumber(card, 60);

    // Check if the player has won
    if (hasWon(card)) {
        printf("You have won!");
    } else {
        printf("You have not won.");
    }

    return 0;
}