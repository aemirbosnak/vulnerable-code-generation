//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define the bingo card structure
typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces[5];
    int wins[1];
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
    card->freeSpaces[0] = 2;
    card->freeSpaces[1] = 4;
    card->freeSpaces[2] = 6;
    card->freeSpaces[3] = 8;
    card->freeSpaces[4] = 10;

    // Set the wins
    card->wins[0] = 0;

    return card;
}

// Function to check if a card has won
int checkWin(BingoCard* card) {
    // Check for a win in the rows
    for (int i = 0; i < 5; i++) {
        int win = 1;
        for (int j = 0; j < 5; j++) {
            if (card->numbers[i][j] != card->freeSpaces[j]) {
                win = 0;
            }
        }

        if (win) {
            card->wins[0] = 1;
            return 1;
        }
    }

    // Check for a win in the columns
    for (int j = 0; j < 5; j++) {
        int win = 1;
        for (int i = 0; i < 5; i++) {
            if (card->numbers[i][j] != card->freeSpaces[i]) {
                win = 0;
            }
        }

        if (win) {
            card->wins[0] = 1;
            return 1;
        }
    }

    // Check for a win in the diagonal
    int win = 1;
    for (int i = 0; i < 5; i++) {
        if (card->numbers[i][i] != card->freeSpaces[i]) {
            win = 0;
        }
    }

    if (win) {
        card->wins[0] = 1;
        return 1;
    }

    return 0;
}

int main() {
    BingoCard* card = generateBingoCard();

    // Print the bingo card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", card->numbers[i][j]);
        }
        printf("\n");
    }

    // Check if the card has won
    if (checkWin(card)) {
        printf("You have won!\n");
    } else {
        printf("You have not won.\n");
    }

    return 0;
}