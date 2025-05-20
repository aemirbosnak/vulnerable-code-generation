//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 9

typedef struct BingoCard {
    int numbers[MAX_NUM];
    int isWinner;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
    for (int i = 0; i < MAX_NUM; i++) {
        card->numbers[i] = 0;
    }
    card->isWinner = 0;
}

void generateBingoNumbers(BingoCard *card) {
    srand(time(NULL));
    for (int i = 0; i < MAX_NUM; i++) {
        card->numbers[i] = rand() % MAX_NUM + 1;
    }
}

void checkBingo(BingoCard *card) {
    for (int i = 0; i < MAX_NUM; i++) {
        if (card->numbers[i] == card->numbers[0]) {
            card->isWinner = 1;
            return;
        }
    }
    card->isWinner = 0;
}

int main() {
    BingoCard *card = malloc(sizeof(BingoCard));
    initializeBingoCard(card);
    generateBingoNumbers(card);
    checkBingo(card);

    if (card->isWinner) {
        printf("You won!");
    } else {
        printf("Sorry, you lost.");
    }

    free(card);

    return 0;
}