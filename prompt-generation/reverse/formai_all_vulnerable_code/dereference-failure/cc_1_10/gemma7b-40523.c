//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COLUMNS 5
#define NUM_ROWS 5

typedef struct BingoCard {
    int **numbers;
    int wins;
} BingoCard;

BingoCard *createBingoCard() {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->numbers = malloc(NUM_ROWS * sizeof(int *));
    for (int r = 0; r < NUM_ROWS; r++) {
        card->numbers[r] = malloc(NUM_COLUMNS * sizeof(int));
    }
    card->wins = 0;
    return card;
}

void generateBingoNumbers(BingoCard *card) {
    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLUMNS; c++) {
            card->numbers[r][c] = rand() % 90 + 1;
        }
    }
}

void markBingoCard(BingoCard *card, int number) {
    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLUMNS; c++) {
            if (card->numbers[r][c] == number) {
                card->numbers[r][c] = -1;
            }
        }
    }
}

int checkBingo(BingoCard *card) {
    // Check rows
    for (int r = 0; r < NUM_ROWS; r++) {
        if (card->numbers[r][0] == -1 && card->numbers[r][1] == -1 && card->numbers[r][2] == -1 && card->numbers[r][3] == -1 && card->numbers[r][4] == -1) {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < NUM_COLUMNS; c++) {
        if (card->numbers[0][c] == -1 && card->numbers[1][c] == -1 && card->numbers[2][c] == -1 && card->numbers[3][c] == -1 && card->numbers[4][c] == -1) {
            return 1;
        }
    }

    // Check diagonals
    if (card->numbers[0][0] == -1 && card->numbers[1][1] == -1 && card->numbers[2][2] == -1 && card->numbers[3][3] == -1 && card->numbers[4][4] == -1) {
        return 1;
    }

    // No bingo
    return 0;
}

int main() {
    BingoCard *card = createBingoCard();
    generateBingoNumbers(card);

    // Simulate drawing numbers
    for (int i = 0; i < 10; i++) {
        int number = rand() % 90 + 1;
        markBingoCard(card, number);

        if (checkBingo(card)) {
            printf("Bingo! You won!\n");
            card->wins++;
        } else {
            printf("Number drawn: %d\n", number);
        }
    }

    printf("Number of wins: %d\n", card->wins);

    return 0;
}