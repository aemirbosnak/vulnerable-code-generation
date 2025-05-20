//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the bingo card structure
typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces[25];
    int wins;
} BingoCard;

// Function to generate a bingo card
BingoCard* generateBingoCard() {
    BingoCard* card = malloc(sizeof(BingoCard));
    card->wins = 0;

    // Generate the numbers for the card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->numbers[i][j] = rand() % 90 + 1;
        }
    }

    // Calculate the free spaces
    card->freeSpaces[0] = 24;
    for (int i = 1; i < 25; i++) {
        card->freeSpaces[i] = card->numbers[i - 1][0] - 1;
    }

    return card;
}

// Function to check if a card has won
int checkWin(BingoCard* card) {
    // Check if the card has won in a row
    for (int i = 0; i < 5; i++) {
        if (card->numbers[0][i] == card->numbers[1][i] && card->numbers[0][i] == card->numbers[2][i] && card->numbers[0][i] == card->numbers[3][i] && card->numbers[0][i] == card->numbers[4][i]) {
            return 1;
        }
    }

    // Check if the card has won in a column
    for (int j = 0; j < 5; j++) {
        if (card->numbers[j][0] == card->numbers[j][1] && card->numbers[j][0] == card->numbers[j][2] && card->numbers[j][0] == card->numbers[j][3] && card->numbers[j][0] == card->numbers[j][4]) {
            return 1;
        }
    }

    // Check if the card has won in the diagonal
    if (card->numbers[0][0] == card->numbers[2][2] && card->numbers[0][0] == card->numbers[4][4]) {
        return 1;
    }

    return 0;
}

// Main game loop
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a bingo card
    BingoCard* card = generateBingoCard();

    // Draw the bingo card
    printf("Your bingo card:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", card->numbers[i][j]);
        }
        printf("\n");
    }

    // Check if the card has won
    int won = checkWin(card);

    // If the card has won, print a winning message
    if (won) {
        printf("You have won!\n");
    } else {
        // If the card has not won, print a message saying that the player has not won
        printf("Sorry, you have not won.\n");
    }

    return 0;
}