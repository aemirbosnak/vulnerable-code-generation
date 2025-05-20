//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 25

typedef struct BingoCard {
    int **numbers;
    int rows;
    int cols;
} BingoCard;

void initializeBingoCard(BingoCard *card, int rows, int cols) {
    card->rows = rows;
    card->cols = cols;
    card->numbers = (int **)malloc(rows * sizeof(int *) + 1);
    for (int i = 0; i < rows; i++) {
        card->numbers[i] = (int *)malloc(cols * sizeof(int) + 1);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            card->numbers[i][j] = 0;
        }
    }
}

void markBingoCard(BingoCard *card, int number) {
    for (int i = 0; i < card->rows; i++) {
        for (int j = 0; j < card->cols; j++) {
            if (card->numbers[i][j] == number) {
                card->numbers[i][j] = -1;
            }
        }
    }
}

int checkBingo(BingoCard *card) {
    // Check rows
    for (int i = 0; i < card->rows; i++) {
        int isBingo = 1;
        for (int j = 0; j < card->cols; j++) {
            if (card->numbers[i][j] != -1) {
                isBingo = 0;
            }
        }
        if (isBingo) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < card->cols; j++) {
        int isBingo = 1;
        for (int i = 0; i < card->rows; i++) {
            if (card->numbers[i][j] != -1) {
                isBingo = 0;
            }
        }
        if (isBingo) {
            return 1;
        }
    }

    // Check diagonals
    int isBingo = 1;
    for (int i = 0; i < card->rows; i++) {
        for (int j = 0; j < card->cols; j++) {
            if (card->numbers[i][j] != -1) {
                isBingo = 0;
            }
        }
    }
    if (isBingo) {
        return 1;
    }

    return 0;
}

int main() {
    BingoCard *card = NULL;
    initializeBingoCard(&card, 5, 5);
    markBingoCard(card, 12);
    markBingoCard(card, 15);
    markBingoCard(card, 13);
    markBingoCard(card, 22);
    markBingoCard(card, 14);

    if (checkBingo(card)) {
        printf("Bingo!");
    } else {
        printf("Not bingo.");
    }

    return 0;
}