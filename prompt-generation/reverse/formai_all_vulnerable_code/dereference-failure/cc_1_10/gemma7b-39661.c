//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 25
#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct BingoCard {
    int **numbers;
    int size;
    int wins;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
    card->size = MAX_NUM;
    card->numbers = (int **)malloc(NUM_ROWS * sizeof(int *));
    for (int r = 0; r < NUM_ROWS; r++) {
        card->numbers[r] = (int *)malloc(NUM_COLS * sizeof(int));
        for (int c = 0; c < NUM_COLS; c++) {
            card->numbers[r][c] = 0;
        }
    }
    card->wins = 0;
}

void generateBingoNumbers(BingoCard *card) {
    for (int i = 0; i < card->size; i++) {
        int num = rand() % MAX_NUM + 1;
        if (card->numbers[num] == 0) {
            card->numbers[num] = 1;
        } else {
            i--;
        }
    }
}

int checkBingo(BingoCard *card) {
    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLS; c++) {
            if (card->numbers[r][c] == 5) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    BingoCard *card = malloc(sizeof(BingoCard));
    initializeBingoCard(card);
    generateBingoNumbers(card);
    if (checkBingo(card)) {
        printf("Bingo!\n");
        card->wins++;
    } else {
        printf("No bingo.\n");
    }

    free(card->numbers);
    free(card);

    return 0;
}