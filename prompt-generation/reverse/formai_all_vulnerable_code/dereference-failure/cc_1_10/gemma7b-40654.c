//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct BingoCard {
    int **numbers;
    int rows;
    int cols;
    int wins;
} BingoCard;

BingoCard *createBingoCard(int r, int c) {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->rows = r;
    card->cols = c;
    card->numbers = (int **)malloc(r * sizeof(int *) + c * sizeof(int));
    for (int i = 0; i < r; i++) {
        card->numbers[i] = (int *)malloc(c * sizeof(int));
    }
    card->wins = 0;
    return card;
}

void generateBingoNumbers(BingoCard *card) {
    srand(time(NULL));
    for (int i = 0; i < card->rows; i++) {
        for (int j = 0; j < card->cols; j++) {
            card->numbers[i][j] = rand() % 90 + 1;
        }
    }
}

int checkBingo(BingoCard *card) {
    for (int i = 0; i < card->rows; i++) {
        if (card->numbers[i][0] == card->numbers[i][1] && card->numbers[i][0] == card->numbers[i][2]) {
            return 1;
        }
    }
    for (int j = 0; j < card->cols; j++) {
        if (card->numbers[0][j] == card->numbers[1][j] && card->numbers[0][j] == card->numbers[2][j]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    BingoCard *card = createBingoCard(5, 5);
    generateBingoNumbers(card);
    if (checkBingo(card)) {
        printf("Bingo!\n");
        card->wins++;
    } else {
        printf("Try again.\n");
    }
    return 0;
}