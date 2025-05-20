//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BINGO_CARD_SIZE 5
#define MAX_NUMBER_OF_BALLS 10

typedef struct BingoCard {
    int **numbers;
    int size;
    int numBalls;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
    card->numbers = malloc(card->size * sizeof(int *));
    for (int i = 0; i < card->size; i++) {
        card->numbers[i] = malloc(card->numBalls * sizeof(int));
    }
    card->size = card->size;
    card->numBalls = card->numBalls;
}

void fillBingoCard(BingoCard *card) {
    for (int i = 0; i < card->size; i++) {
        for (int j = 0; j < card->numBalls; j++) {
            card->numbers[i][j] = rand() % MAX_NUMBER_OF_BALLS + 1;
        }
    }
}

void playBingo(BingoCard *card) {
    for (int i = 0; i < card->numBalls; i++) {
        int number = rand() % MAX_NUMBER_OF_BALLS + 1;
        for (int j = 0; j < card->size; j++) {
            for (int k = 0; k < card->numBalls; k++) {
                if (card->numbers[j][k] == number) {
                    card->numbers[j][k] = -1;
                }
            }
        }
    }

    int won = 0;
    for (int i = 0; i < card->size; i++) {
        if (card->numbers[i][0] == -1) {
            won = 1;
        }
    }

    if (won) {
        printf("Congratulations! You won!");
    } else {
        printf("Sorry, you lost.");
    }
}

int main() {
    BingoCard *card = malloc(sizeof(BingoCard));
    initializeBingoCard(card);
    fillBingoCard(card);
    playBingo(card);
    free(card);

    return 0;
}