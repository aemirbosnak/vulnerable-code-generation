//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5

// Bingo card structure
typedef struct BingoCard {
    int **numbers;
    int wins;
} BingoCard;

// Function to generate a random number between 1 and 99
int generateRandomNumber() {
    return rand() % 99 + 1;
}

// Function to mark a number on a bingo card
void markNumber(BingoCard *card, int number) {
    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLS; c++) {
            if (card->numbers[r][c] == number) {
                card->numbers[r][c] = -1;
            }
        }
    }
}

// Function to check if a bingo card has won
int hasWon(BingoCard *card) {
    // Check rows
    for (int r = 0; r < NUM_ROWS; r++) {
        if (card->numbers[r][0] == -1 && card->numbers[r][1] == -1 && card->numbers[r][2] == -1 && card->numbers[r][3] == -1 && card->numbers[r][4] == -1) {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < NUM_COLS; c++) {
        if (card->numbers[0][c] == -1 && card->numbers[1][c] == -1 && card->numbers[2][c] == -1 && card->numbers[3][c] == -1 && card->numbers[4][c] == -1) {
            return 1;
        }
    }

    // Check diagonals
    if (card->numbers[0][0] == -1 && card->numbers[1][1] == -1 && card->numbers[2][2] == -1 && card->numbers[3][3] == -1 && card->numbers[4][4] == -1) {
        return 1;
    }

    return 0;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a bingo card
    BingoCard *card = malloc(sizeof(BingoCard));
    card->numbers = malloc(NUM_ROWS * sizeof(int *));
    for (int r = 0; r < NUM_ROWS; r++) {
        card->numbers[r] = malloc(NUM_COLS * sizeof(int));
    }

    // Initialize the bingo card
    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLS; c++) {
            card->numbers[r][c] = generateRandomNumber();
        }
    }

    // Mark the numbers on the bingo card
    markNumber(card, 12);
    markNumber(card, 24);
    markNumber(card, 45);

    // Check if the bingo card has won
    if (hasWon(card)) {
        printf("You have won!\n");
    } else {
        printf("Sorry, you have not won.\n");
    }

    // Free the memory allocated for the bingo card
    free(card->numbers);
    free(card);

    return 0;
}