//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a Bingo Card
typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces;
    int cardsWon;
} BingoCard;

// Function to generate a Bingo Card
BingoCard* generateBingoCard() {
    BingoCard* card = malloc(sizeof(BingoCard));
    card->freeSpaces = 24;
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

    // If none of the above conditions are met, the card has not won
    return 0;
}

// Function to play Bingo
int main() {
    // Generate a Bingo Card
    BingoCard* card = generateBingoCard();

    // Print the Bingo Card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", card->numbers[i][j]);
        }
        printf("\n");
    }

    // Play the Bingo Game
    while (!checkBingo(card)) {
        // Get the number drawn
        int numberDrawn = rand() % 90 + 1;

        // Check if the number drawn is on the card
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (card->numbers[i][j] == numberDrawn) {
                    card->numbers[i][j] = -1;
                }
            }
        }

        // Print the updated Bingo Card
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%d ", card->numbers[i][j]);
            }
            printf("\n");
        }
    }

    // Print the winning Bingo Card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", card->numbers[i][j]);
        }
        printf("\n");
    }

    // Print the number of cards won
    printf("Number of cards won: %d", card->cardsWon);

    return 0;
}