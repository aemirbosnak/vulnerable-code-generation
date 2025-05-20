//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10
#define MAX_ROWS 5
#define MAX_COLS 5

typedef struct BingoCard {
    int **numbers;
    int rows;
    int cols;
    int wins;
} BingoCard;

void generateBingoCard(BingoCard *card) {
    card->numbers = (int **)malloc(card->rows * sizeof(int *));
    for (int r = 0; r < card->rows; r++) {
        card->numbers[r] = (int *)malloc(card->cols * sizeof(int));
        for (int c = 0; c < card->cols; c++) {
            card->numbers[r][c] = rand() % MAX_NUM + 1;
        }
    }
}

void markBingoCard(BingoCard *card, int number) {
    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->cols; c++) {
            if (card->numbers[r][c] == number) {
                card->numbers[r][c] = -1;
            }
        }
    }
}

int checkBingoCard(BingoCard *card) {
    for (int r = 0; r < card->rows; r++) {
        if (card->numbers[r][0] == -1 && card->numbers[r][1] == -1 && card->numbers[r][2] == -1) {
            return 1;
        }
    }

    for (int c = 0; c < card->cols; c++) {
        if (card->numbers[0][c] == -1 && card->numbers[1][c] == -1 && card->numbers[2][c] == -1) {
            return 1;
        }
    }

    if (card->numbers[0][0] == -1 && card->numbers[1][1] == -1 && card->numbers[2][2] == -1) {
        return 1;
    }

    return 0;
}

int main() {
    BingoCard card;
    card.rows = MAX_ROWS;
    card.cols = MAX_COLS;
    card.wins = 0;

    generateBingoCard(&card);

    // Simulate drawing numbers
    for (int i = 0; i < 10; i++) {
        int number = rand() % MAX_NUM + 1;
        markBingoCard(&card, number);

        if (checkBingoCard(&card)) {
            card.wins++;
            printf("Bingo! You won %d times!\n", card.wins);
        }
    }

    return 0;
}