//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_BINGO_CARD 5
#define MAX_NUM_BALLS 30

typedef struct BingoCard {
    int **numbers;
    int rows;
    int columns;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
    card->numbers = (int **)malloc(card->rows * sizeof(int *));
    for (int i = 0; i < card->rows; i++) {
        card->numbers[i] = (int *)malloc(card->columns * sizeof(int));
    }

    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->columns; c++) {
            card->numbers[r][c] = 0;
        }
    }
}

void generateBingoNumbers(BingoCard *card) {
    srand(time(NULL));

    for (int i = 0; i < card->rows; i++) {
        for (int j = 0; j < card->columns; j++) {
            card->numbers[i][j] = rand() % MAX_NUM_BALLS + 1;
        }
    }
}

int checkBingo(BingoCard *card) {
    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->columns; c++) {
            if (card->numbers[r][c] == card->numbers[r][0] && card->numbers[r][c] == card->numbers[0][c]) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    BingoCard *card = (BingoCard *)malloc(sizeof(BingoCard));
    initializeBingoCard(card);
    generateBingoNumbers(card);

    if (checkBingo(card)) {
        printf("Bingo!");
    } else {
        printf("No bingo!");
    }

    return 0;
}