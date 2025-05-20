//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 5
#define MAX_ROW 5
#define MAX_COL 5

typedef struct BingoCard {
    int **numbers;
    int **markedNumbers;
    int rows;
    int cols;
} BingoCard;

BingoCard *createBingoCard() {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->numbers = malloc(MAX_ROW * sizeof(int *));
    card->markedNumbers = malloc(MAX_ROW * sizeof(int *));
    card->rows = MAX_ROW;
    card->cols = MAX_COL;

    for (int r = 0; r < card->rows; r++) {
        card->numbers[r] = malloc(card->cols * sizeof(int));
        card->markedNumbers[r] = malloc(card->cols * sizeof(int));
    }

    return card;
}

void drawBingoNumber(BingoCard *card) {
    int num = rand() % MAX_NUM + 1;

    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->cols; c++) {
            if (card->numbers[r][c] == num) {
                card->markedNumbers[r][c] = 1;
            }
        }
    }
}

int main() {
    BingoCard *card = createBingoCard();

    for (int i = 0; i < 10; i++) {
        drawBingoNumber(card);
    }

    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->cols; c++) {
            if (card->markedNumbers[r][c] == 1) {
                printf("%d ", card->numbers[r][c]);
            }
        }
        printf("\n");
    }

    return 0;
}