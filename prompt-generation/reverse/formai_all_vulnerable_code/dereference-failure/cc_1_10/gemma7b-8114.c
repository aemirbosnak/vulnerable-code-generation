//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct BingoCard {
    int **numbers;
    int wins;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
    card->numbers = malloc(NUM_ROWS * sizeof(int *));
    for (int r = 0; r < NUM_ROWS; r++) {
        card->numbers[r] = malloc(NUM_COLS * sizeof(int));
    }
    card->wins = 0;
}

void generateBingoNumbers(BingoCard *card) {
    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLS; c++) {
            card->numbers[r][c] = rand() % 90 + 1;
        }
    }
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

int checkBingoCard(BingoCard *card) {
    for (int r = 0; r < NUM_ROWS; r++) {
        if (card->numbers[r][0] == -1 && card->numbers[r][1] == -1 && card->numbers[r][2] == -1 && card->numbers[r][3] == -1 && card->numbers[r][4] == -1) {
            return 1;
        }
    }

    for (int c = 0; c < NUM_COLS; c++) {
        if (card->numbers[0][c] == -1 && card->numbers[1][c] == -1 && card->numbers[2][c] == -1 && card->numbers[3][c] == -1 && card->numbers[4][c] == -1) {
            return 1;
        }
    }

    return 0;
}

int main() {
    BingoCard *card = malloc(sizeof(BingoCard));
    initializeBingoCard(card);
    generateBingoNumbers(card);

    markBingoCard(card, 22);
    markBingoCard(card, 13);
    markBingoCard(card, 44);
    markBingoCard(card, 29);

    if (checkBingoCard(card)) {
        printf("Bingo!\n");
        card->wins++;
    } else {
        printf("No bingo.\n");
    }

    free(card->numbers);
    free(card);

    return 0;
}