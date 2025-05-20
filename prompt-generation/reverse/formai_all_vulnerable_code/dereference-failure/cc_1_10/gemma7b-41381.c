//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the Bingo Card structure
typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces;
    int winStatus;
} BingoCard;

// Create a Bingo Card
BingoCard* createBingoCard() {
    BingoCard* card = (BingoCard*)malloc(sizeof(BingoCard));
    card->freeSpaces = 24;
    card->winStatus = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->numbers[i][j] = 0;
        }
    }
    return card;
}

// Generate numbers for the Bingo Card
void generateNumbers(BingoCard* card) {
    for (int i = 0; i < 24; i++) {
        int number = rand() % 90 + 1;
        card->numbers[rand() % 5][rand() % 5] = number;
    }
}

// Check if the Bingo Card has won
int checkWin(BingoCard* card) {
    // Check rows
    for (int i = 0; i < 5; i++) {
        if (card->numbers[i][0] == card->numbers[i][1] &&
            card->numbers[i][0] == card->numbers[i][2] &&
            card->numbers[i][0] == card->numbers[i][3] &&
            card->numbers[i][0] == card->numbers[i][4] &&
            card->numbers[i][0] != 0) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 5; j++) {
        if (card->numbers[0][j] == card->numbers[1][j] &&
            card->numbers[0][j] == card->numbers[2][j] &&
            card->numbers[0][j] == card->numbers[3][j] &&
            card->numbers[0][j] == card->numbers[4][j] &&
            card->numbers[0][j] != 0) {
            return 1;
        }
    }

    // Check diagonals
    if (card->numbers[0][0] == card->numbers[2][2] &&
        card->numbers[0][0] == card->numbers[4][4] &&
        card->numbers[0][0] != 0) {
        return 1;
    }

    return 0;
}

// Main game loop
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a Bingo Card
    BingoCard* card = createBingoCard();

    // Generate numbers for the Bingo Card
    generateNumbers(card);

    // Play the game
    int win = 0;
    while (!win) {
        // Get the number called
        int numberCalled = rand() % 90 + 1;

        // Mark the number on the Bingo Card
        card->numbers[rand() % 5][rand() % 5] = numberCalled;

        // Check if the Bingo Card has won
        win = checkWin(card);

        // If the Bingo Card has won, print the winning message
        if (win) {
            printf("You have won!\n");
        }
    }

    // Free the Bingo Card memory
    free(card);

    return 0;
}