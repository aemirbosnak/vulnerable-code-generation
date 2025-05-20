//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_BINGO_CARDS 10

typedef struct BingoCard {
    int **numbers;
    int numRows;
    int numCols;
} BingoCard;

BingoCard *createBingoCard(int rows, int cols) {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->numRows = rows;
    card->numCols = cols;
    card->numbers = malloc(rows * cols * sizeof(int));
    return card;
}

void generateBingoNumbers(BingoCard *card) {
    for (int r = 0; r < card->numRows; r++) {
        for (int c = 0; c < card->numCols; c++) {
            card->numbers[r][c] = rand() % 90 + 1;
        }
    }
}

void printBingoCard(BingoCard *card) {
    for (int r = 0; r < card->numRows; r++) {
        for (int c = 0; c < card->numCols; c++) {
            printf("%d ", card->numbers[r][c]);
        }
        printf("\n");
    }
}

int main() {
    BingoCard *cards[MAX_NUM_BINGO_CARDS];
    int numCards = 5;

    // Create and generate bingo cards
    for (int i = 0; i < numCards; i++) {
        cards[i] = createBingoCard(5, 5);
        generateBingoNumbers(cards[i]);
    }

    // Print bingo cards
    for (int i = 0; i < numCards; i++) {
        printBingoCard(cards[i]);
    }

    return 0;
}