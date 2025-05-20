//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct BingoCard {
    int **numbers;
    int wins;
} BingoCard;

BingoCard *createBingoCard() {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->numbers = malloc(NUM_ROWS * sizeof(int *));
    for (int i = 0; i < NUM_ROWS; i++) {
        card->numbers[i] = malloc(NUM_COLS * sizeof(int));
    }
    card->wins = 0;
    return card;
}

void fillBingoCard(BingoCard *card) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            card->numbers[i][j] = rand() % 90 + 1;
        }
    }
}

int checkBingo(BingoCard *card) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (card->numbers[i][j] == card->numbers[0][0]) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    BingoCard *card = createBingoCard();
    fillBingoCard(card);

    if (checkBingo(card)) {
        printf("Bingo!");
    } else {
        printf("Not yet...");
    }

    free(card);

    return 0;
}