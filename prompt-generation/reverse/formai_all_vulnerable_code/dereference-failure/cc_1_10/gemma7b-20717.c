//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 25
#define NUM_COL 5

typedef struct BingoCard {
    int **numbers;
    int size;
    int win;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
    card->numbers = (int **)malloc(card->size * sizeof(int *));
    for (int i = 0; i < card->size; i++) {
        card->numbers[i] = (int *)malloc(NUM_COL * sizeof(int));
    }
    card->win = 0;
}

void generateBingoNumbers(BingoCard *card) {
    for (int i = 0; i < card->size; i++) {
        for (int j = 0; j < NUM_COL; j++) {
            card->numbers[i][j] = rand() % MAX_NUM + 1;
        }
    }
}

void checkBingo(BingoCard *card) {
    for (int i = 0; i < card->size; i++) {
        for (int j = 0; j < NUM_COL; j++) {
            if (card->numbers[i][j] == card->numbers[0][0]) {
                card->win = 1;
            }
        }
    }
}

int main() {
    BingoCard *card = malloc(sizeof(BingoCard));
    initializeBingoCard(card);
    generateBingoNumbers(card);
    checkBingo(card);

    if (card->win) {
        printf("Congratulations! You won!\n");
    } else {
        printf("Sorry, you lose.\n");
    }

    free(card->numbers);
    free(card);

    return 0;
}