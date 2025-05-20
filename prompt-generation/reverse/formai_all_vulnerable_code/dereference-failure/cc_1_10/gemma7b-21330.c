//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store a bingo card
typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces[25];
    int wins[1];
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

    // Calculate the free spaces
    card->freeSpaces[0] = 24;
    for (int i = 1; i < 25; i++) {
        card->freeSpaces[i] = card->freeSpaces[i - 1] - 1;
    }

    // Initialize the wins array
    card->wins[0] = 0;

    return card;
}

// Function to check if a card has won
int checkWin(BingoCard* card) {
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

    // If there has not been a win, return 0
    return 0;
}

int main() {
    // Generate a bingo card
    BingoCard* card = generateBingoCard();

    // Check if the card has won
    if (checkWin(card) == 1) {
        // The card has won!
        printf("You have won!");
    } else {
        // The card has not won.
        printf("You have not won.");
    }

    return 0;
}