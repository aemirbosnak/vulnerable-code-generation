//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BINGO_CARDS 5
#define MAX_NUM_BALLS 20

typedef struct BingoCard {
    int **numbers;
    int rows;
    int cols;
    int wins;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
    card->numbers = (int **)malloc(card->rows * sizeof(int *));
    for (int r = 0; r < card->rows; r++) {
        card->numbers[r] = (int *)malloc(card->cols * sizeof(int));
    }

    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->cols; c++) {
            card->numbers[r][c] = 0;
        }
    }

    card->wins = 0;
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

    return 0;
}

int main() {
    BingoCard cards[MAX_BINGO_CARDS];

    for (int i = 0; i < MAX_BINGO_CARDS; i++) {
        initializeBingoCard(&cards[i]);
    }

    // Draw balls
    int balls[MAX_NUM_BALLS];
    for (int i = 0; i < MAX_NUM_BALLS; i++) {
        balls[i] = rand() % MAX_NUM_BALLS + 1;
    }

    // Mark cards
    for (int i = 0; i < MAX_NUM_BALLS; i++) {
        for (int j = 0; j < MAX_BINGO_CARDS; j++) {
            markBingoCard(&cards[j], balls[i]);
        }
    }

    // Check for wins
    for (int i = 0; i < MAX_BINGO_CARDS; i++) {
        if (checkBingoCard(&cards[i])) {
            printf("Card %d won!", i);
        }
    }

    return 0;
}