//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct BingoCard {
    int **numbers;
    int rows;
    int cols;
    int wins;
} BingoCard;

BingoCard *createBingoCard() {
    BingoCard *card = (BingoCard *)malloc(sizeof(BingoCard));
    card->numbers = (int **)malloc(NUM_ROWS * sizeof(int *));
    for (int r = 0; r < NUM_ROWS; r++) {
        card->numbers[r] = (int *)malloc(NUM_COLS * sizeof(int));
    }
    card->rows = NUM_ROWS;
    card->cols = NUM_COLS;
    card->wins = 0;
    return card;
}

void drawBingoCard(BingoCard *card) {
    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->cols; c++) {
            card->numbers[r][c] = rand() % 90 + 1;
        }
    }
}

int checkBingo(BingoCard *card) {
    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->cols; c++) {
            if (card->numbers[r][c] == card->numbers[r][0]) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    BingoCard *card = createBingoCard();
    drawBingoCard(card);

    if (checkBingo(card)) {
        printf("Bingo!");
    } else {
        printf("No bingo!");
    }

    free(card->numbers);
    free(card);

    return 0;
}