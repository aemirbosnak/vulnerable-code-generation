//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 5

typedef struct BingoCard {
    int **numbers;
    int rows;
    int cols;
} BingoCard;

BingoCard* createBingoCard(int rows, int cols) {
    BingoCard* card = (BingoCard*)malloc(sizeof(BingoCard));
    card->rows = rows;
    card->cols = cols;
    card->numbers = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        card->numbers[i] = (int*)malloc(cols * sizeof(int));
    }
    return card;
}

void fillBingoCard(BingoCard* card) {
    for (int i = 0; i < card->rows; i++) {
        for (int j = 0; j < card->cols; j++) {
            card->numbers[i][j] = rand() % MAX_NUM + 1;
        }
    }
}

int checkBingo(BingoCard* card) {
    for (int i = 0; i < card->rows; i++) {
        for (int j = 0; j < card->cols; j++) {
            if (card->numbers[i][j] == card->numbers[0][0]) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    BingoCard* card = createBingoCard(5, 5);
    fillBingoCard(card);
    if (checkBingo(card)) {
        printf("Bingo!");
    } else {
        printf("Sorry, no bingo.");
    }

    return 0;
}