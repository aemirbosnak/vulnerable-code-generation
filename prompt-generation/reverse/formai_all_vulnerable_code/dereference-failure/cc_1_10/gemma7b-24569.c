//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a Bingo card structure
typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces;
    int winningNumbers[5];
} BingoCard;

// Function to generate a Bingo card
BingoCard *generateBingoCard() {
    BingoCard *card = (BingoCard *)malloc(sizeof(BingoCard));

    // Initialize the numbers array
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->numbers[i][j] = 0;
        }
    }

    // Set the free spaces
    card->freeSpaces = 24;

    // Generate the winning numbers
    for (int i = 0; i < 5; i++) {
        card->winningNumbers[i] = rand() % 90 + 1;
    }

    return card;
}

// Function to mark a number on a Bingo card
void markNumber(BingoCard *card, int number) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (card->numbers[i][j] == number) {
                card->numbers[i][j] = -1;
            }
        }
    }
}

// Function to check if a Bingo card has won
int hasWon(BingoCard *card) {
    // Check rows
    for (int i = 0; i < 5; i++) {
        if (card->numbers[i][0] == card->numbers[i][1] &&
            card->numbers[i][0] == card->numbers[i][2] &&
            card->numbers[i][0] == card->numbers[i][3] &&
            card->numbers[i][0] == card->numbers[i][4] &&
            card->numbers[i][0] == card->winningNumbers[i]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 5; j++) {
        if (card->numbers[0][j] == card->numbers[1][j] &&
            card->numbers[0][j] == card->numbers[2][j] &&
            card->numbers[0][j] == card->numbers[3][j] &&
            card->numbers[0][j] == card->numbers[4][j] &&
            card->numbers[0][j] == card->winningNumbers[j]) {
            return 1;
        }
    }

    // Check diagonals
    if (card->numbers[0][0] == card->numbers[1][1] &&
        card->numbers[0][0] == card->numbers[2][2] &&
        card->numbers[0][0] == card->numbers[3][3] &&
        card->numbers[0][0] == card->numbers[4][4] &&
        card->numbers[0][0] == card->winningNumbers[0]) {
        return 1;
    }

    // If all else fails, the card has not won
    return 0;
}

int main() {
    // Generate a Bingo card
    BingoCard *card = generateBingoCard();

    // Mark numbers on the card
    markNumber(card, 12);
    markNumber(card, 24);
    markNumber(card, 36);
    markNumber(card, 48);
    markNumber(card, 60);

    // Check if the card has won
    if (hasWon(card)) {
        printf("Congratulations! You have won!");
    } else {
        printf("Sorry, you have not won.");
    }

    return 0;
}