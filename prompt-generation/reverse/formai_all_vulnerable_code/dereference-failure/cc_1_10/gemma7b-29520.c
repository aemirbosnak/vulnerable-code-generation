//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a Bingo Card structure
typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces;
    int isWinner;
} BingoCard;

// Function to generate a bingo card
BingoCard *generateBingoCard() {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->freeSpaces = 24;
    card->isWinner = 0;

    // Generate random numbers for the card
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->numbers[i][j] = rand() % 90 + 1;
        }
    }

    return card;
}

// Function to check if a card is a winner
int checkWinner(BingoCard *card) {
    // Check rows
    for (int i = 0; i < 5; i++) {
        if (card->numbers[0][i] == card->numbers[1][i] && card->numbers[0][i] == card->numbers[2][i] && card->numbers[0][i] == card->numbers[3][i] && card->numbers[0][i] == card->numbers[4][i]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 5; j++) {
        if (card->numbers[j][0] == card->numbers[j][1] && card->numbers[j][0] == card->numbers[j][2] && card->numbers[j][0] == card->numbers[j][3] && card->numbers[j][0] == card->numbers[j][4]) {
            return 1;
        }
    }

    // Check diagonals
    if (card->numbers[0][0] == card->numbers[1][1] && card->numbers[0][0] == card->numbers[2][2] && card->numbers[0][0] == card->numbers[3][3] && card->numbers[0][0] == card->numbers[4][4]) {
        return 1;
    }

    // Check if free spaces are filled
    if (card->freeSpaces == 0) {
        return 1;
    }

    return 0;
}

int main() {
    // Generate a bingo card
    BingoCard *card = generateBingoCard();

    // Check if the card is a winner
    if (checkWinner(card)) {
        printf("You are a winner!");
    } else {
        printf("Sorry, you are not a winner.");
    }

    return 0;
}