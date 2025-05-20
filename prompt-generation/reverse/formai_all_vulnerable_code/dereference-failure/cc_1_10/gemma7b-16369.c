//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct BingoCard {
    int **numbers;
    int wins;
} BingoCard;

void generateBingoCard(BingoCard *card) {
    card->numbers = (int **)malloc(NUM_ROWS * sizeof(int *));
    for (int r = 0; r < NUM_ROWS; r++) {
        card->numbers[r] = (int *)malloc(NUM_COLS * sizeof(int));
        for (int c = 0; c < NUM_COLS; c++) {
            card->numbers[r][c] = rand() % 90 + 1;
        }
    }
    card->wins = 0;
}

void markBingoCard(BingoCard *card, int number) {
    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLS; c++) {
            if (card->numbers[r][c] == number) {
                card->numbers[r][c] = -1;
            }
        }
    }
}

int checkBingoCard(BingoCard *card) {
    for (int r = 0; r < NUM_ROWS; r++) {
        if (card->numbers[r][0] == -1 && card->numbers[r][1] == -1 && card->numbers[r][2] == -1 && card->numbers[r][3] == -1 && card->numbers[r][4] == -1) {
            return 1;
        }
    }
    return 0;
}

int main() {
    BingoCard *card = malloc(sizeof(BingoCard));
    generateBingoCard(card);

    // Simulate drawing numbers
    for (int i = 0; i < 20; i++) {
        int number = rand() % 90 + 1;
        markBingoCard(card, number);

        if (checkBingoCard(card)) {
            card->wins++;
            printf("Bingo! You won %d times!\n", card->wins);
        }
    }

    free(card);

    return 0;
}