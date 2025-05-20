//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BINGO_COLUMNS 5
#define NUM_BINGO_ROWS 5

typedef struct BingoCard {
    int **numbers;
    int wins;
} BingoCard;

BingoCard *createBingoCard() {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->numbers = malloc(NUM_BINGO_ROWS * sizeof(int *));
    for (int r = 0; r < NUM_BINGO_ROWS; r++) {
        card->numbers[r] = malloc(NUM_BINGO_COLUMNS * sizeof(int));
    }
    card->wins = 0;
    return card;
}

void drawBingoNumber(BingoCard *card) {
    int number = rand() % 90 + 1;
    for (int r = 0; r < NUM_BINGO_ROWS; r++) {
        for (int c = 0; c < NUM_BINGO_COLUMNS; c++) {
            if (card->numbers[r][c] == number) {
                card->numbers[r][c] = -1;
            }
        }
    }
}

int main() {
    BingoCard *card = createBingoCard();
    drawBingoNumber(card);
    drawBingoNumber(card);
    drawBingoNumber(card);

    if (card->wins == 0) {
        printf("You have not won!\n");
    } else {
        printf("You have won!\n");
    }

    free(card->numbers);
    free(card);

    return 0;
}