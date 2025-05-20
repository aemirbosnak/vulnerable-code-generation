//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_CARD_SIZE 5
#define MAX_NUMS_PER_ROW 5

typedef struct BingoCard {
    int **numbers;
    int rows;
    int cols;
    int winning_number;
} BingoCard;

BingoCard *createBingoCard() {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->numbers = malloc(MAX_BINGO_CARD_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_BINGO_CARD_SIZE; i++) {
        card->numbers[i] = malloc(MAX_NUMS_PER_ROW * sizeof(int));
    }
    card->rows = MAX_BINGO_CARD_SIZE;
    card->cols = MAX_NUMS_PER_ROW;
    card->winning_number = -1;
    return card;
}

void generateBingoNumbers(BingoCard *card) {
    srand(time(NULL));
    for (int i = 0; i < card->rows; i++) {
        for (int j = 0; j < card->cols; j++) {
            card->numbers[i][j] = rand() % 100 + 1;
        }
    }
}

int checkBingo(BingoCard *card) {
    for (int i = 0; i < card->rows; i++) {
        if (card->numbers[i][0] == card->winning_number) {
            return 1;
        }
    }
    return 0;
}

int main() {
    BingoCard *card = createBingoCard();
    generateBingoNumbers(card);
    card->winning_number = 25;
    if (checkBingo(card)) {
        printf("Bingo!");
    } else {
        printf("Sorry, no bingo.");
    }
    return 0;
}