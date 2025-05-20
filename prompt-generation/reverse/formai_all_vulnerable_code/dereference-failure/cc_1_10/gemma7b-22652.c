//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the Bingo Card structure
typedef struct BingoCard {
    int **numbers;
    int rows;
    int cols;
    int freeSpaces;
} BingoCard;

// Create a bingo card
BingoCard* createBingoCard(int rows, int cols) {
    BingoCard* card = malloc(sizeof(BingoCard));
    card->rows = rows;
    card->cols = cols;
    card->numbers = malloc(rows * cols * sizeof(int));
    card->freeSpaces = rows * cols;
    return card;
}

// Fill the bingo card with random numbers
void fillBingoCard(BingoCard* card) {
    srand(time(NULL));
    for (int i = 0; i < card->rows; i++) {
        for (int j = 0; j < card->cols; j++) {
            card->numbers[i][j] = rand() % 90 + 1;
        }
    }
}

// Check if a number is on the bingo card
int isNumberOnCard(BingoCard* card, int number) {
    for (int i = 0; i < card->rows; i++) {
        for (int j = 0; j < card->cols; j++) {
            if (card->numbers[i][j] == number) {
                return 1;
            }
        }
    }
    return 0;
}

// Main game loop
int main() {
    // Create a bingo card
    BingoCard* card = createBingoCard(5, 5);

    // Fill the bingo card with random numbers
    fillBingoCard(card);

    // Draw numbers
    int drawnNumbers[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30};

    // Check if each number is on the bingo card
    for (int i = 0; i < 15; i++) {
        if (isNumberOnCard(card, drawnNumbers[i])) {
            printf("Number %d is on the card.\n", drawnNumbers[i]);
        }
    }

    // Free the memory allocated for the bingo card
    free(card->numbers);
    free(card);

    return 0;
}