//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the Bingo Card Structure
typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces;
    int wins;
} BingoCard;

// Function to generate a Bingo Card
BingoCard* generateBingoCard() {
    BingoCard* card = malloc(sizeof(BingoCard));
    card->freeSpaces = 24;
    card->wins = 0;

    // Generate the numbers for the card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->numbers[i][j] = rand() % 90 + 1;
        }
    }

    return card;
}

// Function to check if a card has won
int checkWin(BingoCard* card) {
    // Check for a win in the rows
    for (int i = 0; i < 5; i++) {
        if (card->numbers[0][i] == card->numbers[1][i] &&
            card->numbers[0][i] == card->numbers[2][i] &&
            card->numbers[0][i] == card->numbers[3][i] &&
            card->numbers[0][i] == card->numbers[4][i]) {
            return 1;
        }
    }

    // Check for a win in the columns
    for (int j = 0; j < 5; j++) {
        if (card->numbers[j][0] == card->numbers[j][1] &&
            card->numbers[j][0] == card->numbers[j][2] &&
            card->numbers[j][0] == card->numbers[j][3] &&
            card->numbers[j][0] == card->numbers[j][4]) {
            return 1;
        }
    }

    // Check for a win in the diagonals
    if (card->numbers[0][0] == card->numbers[1][1] &&
        card->numbers[0][0] == card->numbers[2][2] &&
        card->numbers[0][0] == card->numbers[3][3] &&
        card->numbers[0][0] == card->numbers[4][4]) {
        return 1;
    }

    // If no win, return 0
    return 0;
}

// Main Function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a Bingo Card
    BingoCard* card = generateBingoCard();

    // Print the Bingo Card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", card->numbers[i][j]);
        }
        printf("\n");
    }

    // Check if the card has won
    int win = checkWin(card);

    // Print the result
    if (win) {
        printf("You have won!");
    } else {
        printf("You have not won.");
    }

    return 0;
}