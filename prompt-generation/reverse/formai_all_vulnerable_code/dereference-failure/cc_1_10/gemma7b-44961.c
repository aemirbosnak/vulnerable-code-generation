//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

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
int hasWon(BingoCard* card) {
    // Check if the card has won in a row
    for (int i = 0; i < 5; i++) {
        if (card->numbers[i][0] == card->numbers[i][1] && card->numbers[i][0] == card->numbers[i][2] && card->numbers[i][0] == card->numbers[i][3] && card->numbers[i][0] == card->numbers[i][4]) {
            return 1;
        }
    }

    // Check if the card has won in a column
    for (int j = 0; j < 5; j++) {
        if (card->numbers[0][j] == card->numbers[1][j] && card->numbers[0][j] == card->numbers[2][j] && card->numbers[0][j] == card->numbers[3][j] && card->numbers[0][j] == card->numbers[4][j]) {
            return 1;
        }
    }

    // Check if the card has won in the diagonal
    if (card->numbers[0][0] == card->numbers[1][1] && card->numbers[0][0] == card->numbers[2][2] && card->numbers[0][0] == card->numbers[3][3] && card->numbers[0][0] == card->numbers[4][4]) {
        return 1;
    }

    return 0;
}

// Function to play the bingo game
void playBingo(BingoCard* card) {
    // Draw the numbers from the bingo cage
    int numberDrawn = rand() % 90 + 1;

    // Check if the number drawn is on the card
    if (card->numbers[numberDrawn / 5][numberDrawn % 5] == numberDrawn) {
        // Mark the number as called
        card->numbers[numberDrawn / 5][numberDrawn % 5] = -1;

        // Check if the card has won
        if (hasWon(card)) {
            // Increment the number of cards won
            card->cardsWon++;

            // Print a message to the console
            printf("Congratulations! You have won %d cards!\n", card->cardsWon);
        }
    }
}

int main() {
    // Generate a bingo card
    BingoCard* card = generateBingoCard();

    // Play the bingo game
    playBingo(card);

    return 0;
}