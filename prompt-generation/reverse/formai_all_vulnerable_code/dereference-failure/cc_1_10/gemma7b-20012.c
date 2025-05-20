//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BINGO_CARD_SIZE 5

typedef struct BingoCard {
    int **numbers;
    int size;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
    card->numbers = (int **)malloc(card->size * sizeof(int *));
    for (int i = 0; i < card->size; i++) {
        card->numbers[i] = (int *)malloc(card->size * sizeof(int));
    }
    for (int i = 0; i < card->size; i++) {
        for (int j = 0; j < card->size; j++) {
            card->numbers[i][j] = 0;
        }
    }
}

void generateBingoCard(BingoCard *card) {
    int num = 0;
    for (int i = 0; i < card->size; i++) {
        for (int j = 0; j < card->size; j++) {
            card->numbers[i][j] = num++;
        }
    }
}

void printBingoCard(BingoCard *card) {
    for (int i = 0; i < card->size; i++) {
        for (int j = 0; j < card->size; j++) {
            printf("%d ", card->numbers[i][j]);
        }
        printf("\n");
    }
}

int main() {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->size = MAX_BINGO_CARD_SIZE;
    initializeBingoCard(card);
    generateBingoCard(card);
    printBingoCard(card);

    free(card->numbers);
    free(card);

    return 0;
}