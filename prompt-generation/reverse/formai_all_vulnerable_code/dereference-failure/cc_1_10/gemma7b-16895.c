//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the Bingo Card structure
typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces[2];
} BingoCard;

// Function to generate a bingo card
BingoCard* generateBingoCard() {
    BingoCard* card = malloc(sizeof(BingoCard));

    // Generate the numbers for the card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->numbers[i][j] = rand() % 90 + 1;
        }
    }

    // Set the free spaces
    card->freeSpaces[0] = rand() % 2;
    card->freeSpaces[1] = rand() % 2;

    return card;
}

// Function to check if a card has won
int checkBingo(BingoCard* card) {
    // Check the rows
    for (int i = 0; i < 5; i++) {
        if (card->numbers[0][i] == card->numbers[1][i] && card->numbers[0][i] == card->numbers[2][i] && card->numbers[0][i] == card->numbers[3][i] && card->numbers[0][i] == card->numbers[4][i]) {
            return 1;
        }
    }

    // Check the columns
    for (int j = 0; j < 5; j++) {
        if (card->numbers[j][0] == card->numbers[j][1] && card->numbers[j][0] == card->numbers[j][2] && card->numbers[j][0] == card->numbers[j][3] && card->numbers[j][0] == card->numbers[j][4]) {
            return 1;
        }
    }

    // Check the diagonals
    if (card->numbers[0][0] == card->numbers[1][1] && card->numbers[0][0] == card->numbers[2][2] && card->numbers[0][0] == card->numbers[3][3] && card->numbers[0][0] == card->numbers[4][4]) {
        return 1;
    }

    // If all else fails, the card has not won
    return 0;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a bingo card
    BingoCard* card = generateBingoCard();

    // Check if the card has won
    int won = checkBingo(card);

    // Print the results
    if (won) {
        printf("Congratulations! You have won!\n");
    } else {
        printf("Sorry, you have not won.\n");
    }

    return 0;
}