//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct BingoCard {
    int **numbers;
    int wins;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
    card->numbers = (int **)malloc(NUM_ROWS * sizeof(int *));
    for (int r = 0; r < NUM_ROWS; r++) {
        card->numbers[r] = (int *)malloc(NUM_COLS * sizeof(int));
        for (int c = 0; c < NUM_COLS; c++) {
            card->numbers[r][c] = 0;
        }
    }
    card->wins = 0;
}

void markBingoCard(BingoCard *card, int number) {
    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLS; c++) {
            if (card->numbers[r][c] == number) {
                card->numbers[r][c] = -1;
            }
        }
    }
}

int checkBingo(BingoCard *card) {
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
    BingoCard *card = malloc(sizeof(BingoCard));
    initializeBingoCard(card);

    // Mark the card
    markBingoCard(card, 1);
    markBingoCard(card, 2);
    markBingoCard(card, 3);
    markBingoCard(card, 4);
    markBingoCard(card, 5);

    // Check if the card has won
    if (checkBingo(card)) {
        printf("You have won!");
    } else {
        printf("You have not won.");
    }

    return 0;
}