//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 50

typedef struct BingoCard {
    int **numbers;
    int rows;
    int cols;
    int wins;
} BingoCard;

BingoCard *createBingoCard(int rows, int cols) {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->numbers = malloc(rows * cols * sizeof(int));
    card->rows = rows;
    card->cols = cols;
    card->wins = 0;
    return card;
}

void generateBingoNumbers(BingoCard *card) {
    srand(time(NULL));
    for (int i = 0; i < card->rows * card->cols; i++) {
        card->numbers[i] = rand() % MAX_NUM + 1;
    }
}

int checkBingo(BingoCard *card) {
    for (int i = 0; i < card->rows; i++) {
        for (int j = 0; j < card->cols; j++) {
            if (card->numbers[i * card->cols + j] == card->numbers[0]) {
                return 1;
            }
        }
    }
    return 0;
}

void printBingoCard(BingoCard *card) {
    for (int i = 0; i < card->rows; i++) {
        for (int j = 0; j < card->cols; j++) {
            printf("%d ", card->numbers[i * card->cols + j]);
        }
        printf("\n");
    }
}

int main() {
    BingoCard *card = createBingoCard(5, 5);
    generateBingoNumbers(card);
    printBingoCard(card);
    if (checkBingo(card)) {
        printf("Bingo!\n");
        card->wins++;
    }
    printBingoCard(card);
    free(card->numbers);
    free(card);

    return 0;
}