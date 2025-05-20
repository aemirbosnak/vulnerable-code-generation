//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the bingo card structure
typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces;
    int winningNumbers[5];
} BingoCard;

// Function to generate a random number between 1 and 99
int generateRandomNumber() {
    return rand() % 100 + 1;
}

// Function to mark a number on the bingo card
void markNumber(BingoCard *card, int number) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (card->numbers[i][j] == number) {
                card->numbers[i][j] = -1;
            }
        }
    }
}

// Function to check if the bingo card has won
int hasWon(BingoCard *card) {
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

    // If all else fails, the card has not won
    return 0;
}

int main() {
    // Create a bingo card
    BingoCard *card = malloc(sizeof(BingoCard));
    card->freeSpaces = 15;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->numbers[i][j] = generateRandomNumber();
        }
    }

    // Generate the winning numbers
    for (int i = 0; i < 5; i++) {
        card->winningNumbers[i] = generateRandomNumber();
    }

    // Mark the winning numbers on the card
    for (int i = 0; i < 5; i++) {
        markNumber(card, card->winningNumbers[i]);
    }

    // Check if the card has won
    if (hasWon(card)) {
        printf("You have won!");
    } else {
        printf("Sorry, you have not won.");
    }

    return 0;
}