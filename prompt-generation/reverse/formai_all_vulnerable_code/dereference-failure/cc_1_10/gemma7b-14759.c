//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_BINGO 5

typedef struct BingoCard {
    int **numbers;
    int numCards;
    int winner;
} BingoCard;

BingoCard *createBingoCard(int numCards) {
    BingoCard *card = (BingoCard *)malloc(sizeof(BingoCard));
    card->numbers = (int **)malloc(numCards * sizeof(int *));
    for (int i = 0; i < numCards; i++) {
        card->numbers[i] = (int *)malloc(MAX_NUM_BINGO * sizeof(int));
    }
    card->numCards = numCards;
    card->winner = 0;
    return card;
}

void generateBingoNumbers(BingoCard *card) {
    for (int i = 0; i < card->numCards; i++) {
        for (int j = 0; j < MAX_NUM_BINGO; j++) {
            card->numbers[i][j] = rand() % 90 + 1;
        }
    }
}

void checkBingo(BingoCard *card) {
    for (int i = 0; i < card->numCards; i++) {
        for (int j = 0; j < MAX_NUM_BINGO; j++) {
            if (card->numbers[i][j] == card->numbers[i][0]) {
                card->winner = 1;
            }
        }
    }
}

int main() {
    BingoCard *card = createBingoCard(2);
    generateBingoNumbers(card);
    checkBingo(card);
    if (card->winner) {
        printf("Winner!\n");
    } else {
        printf("No winner.\n");
    }
    return 0;
}