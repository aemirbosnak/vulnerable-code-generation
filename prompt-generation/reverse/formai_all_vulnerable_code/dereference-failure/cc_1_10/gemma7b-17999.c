//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure to represent a bingo card
typedef struct BingoCard {
    int numbers[5][5];
    int cardsWon;
} BingoCard;

// Function to generate a bingo card
BingoCard* generateBingoCard() {
    BingoCard* card = malloc(sizeof(BingoCard));
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
int checkBingo(BingoCard* card) {
    // Check if the card has won in a row
    for (int i = 0; i < 5; i++) {
        if (card->numbers[0][i] == card->numbers[1][i] &&
            card->numbers[0][i] == card->numbers[2][i] &&
            card->numbers[0][i] == card->numbers[3][i] &&
            card->numbers[0][i] == card->numbers[4][i]) {
            return 1;
        }
    }

    // Check if the card has won in a column
    for (int j = 0; j < 5; j++) {
        if (card->numbers[j][0] == card->numbers[j][1] &&
            card->numbers[j][0] == card->numbers[j][2] &&
            card->numbers[j][0] == card->numbers[j][3] &&
            card->numbers[j][0] == card->numbers[j][4]) {
            return 1;
        }
    }

    // Check if the card has won in the diagonal
    if (card->numbers[0][0] == card->numbers[2][2] &&
        card->numbers[0][0] == card->numbers[4][4]) {
        return 1;
    }

    // If the card has not won, return 0
    return 0;
}

int main() {
    // Generate a bingo card
    BingoCard* card = generateBingoCard();

    // Check if the card has won
    if (checkBingo(card)) {
        // The card has won, so print a message
        printf("Congratulations, you have won!");
    } else {
        // The card has not won, so print a message
        printf("Sorry, you have not won.");
    }

    return 0;
}