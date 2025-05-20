//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 25
#define MAX_ROUNDS 10

typedef struct BingoCard {
    int numbers[MAX_NUM];
    int markedNumbers[MAX_NUM];
    int roundsWon;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
    for (int i = 0; i < MAX_NUM; i++) {
        card->numbers[i] = -1;
        card->markedNumbers[i] = 0;
    }
    card->roundsWon = 0;
}

void generateBingoNumbers(BingoCard *card) {
    for (int i = 0; i < MAX_NUM; i++) {
        if (card->numbers[i] == -1) {
            card->numbers[i] = rand() % MAX_NUM + 1;
        }
    }
}

void markBingoNumber(BingoCard *card, int number) {
    for (int i = 0; i < MAX_NUM; i++) {
        if (card->numbers[i] == number) {
            card->markedNumbers[i] = 1;
        }
    }
}

int checkBingo(BingoCard *card) {
    for (int i = 0; i < MAX_NUM; i++) {
        if (card->markedNumbers[i] != 1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    BingoCard *card = malloc(sizeof(BingoCard));
    initializeBingoCard(card);

    for (int round = 0; round < MAX_ROUNDS; round++) {
        generateBingoNumbers(card);
        // Simulate drawing numbers
        markBingoNumber(card, rand() % MAX_NUM + 1);
        markBingoNumber(card, rand() % MAX_NUM + 1);
        markBingoNumber(card, rand() % MAX_NUM + 1);

        if (checkBingo(card)) {
            card->roundsWon++;
            printf("Bingo! Round %d, Won %d rounds!\n", round, card->roundsWon);
        }
    }

    free(card);
    return 0;
}