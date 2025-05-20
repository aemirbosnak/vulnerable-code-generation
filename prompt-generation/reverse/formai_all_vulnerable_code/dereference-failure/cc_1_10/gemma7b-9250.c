//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BALLS 10
#define MAX_ROWS 5
#define MAX_COLS 5

typedef struct Ball {
    int number;
    struct Ball* next;
} Ball;

typedef struct BingoCard {
    int** numbers;
    int rows;
    int cols;
    struct BingoCard* next;
} BingoCard;

void initializeBingoCard(BingoCard* card) {
    card->numbers = (int**)malloc(card->rows * sizeof(int*));
    for (int r = 0; r < card->rows; r++) {
        card->numbers[r] = (int*)malloc(card->cols * sizeof(int));
    }
    card->rows = card->rows;
    card->cols = card->cols;
}

void fillBingoCard(BingoCard* card) {
    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->cols; c++) {
            card->numbers[r][c] = rand() % MAX_BALLS + 1;
        }
    }
}

void markBingoCard(BingoCard* card, int number) {
    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->cols; c++) {
            if (card->numbers[r][c] == number) {
                card->numbers[r][c] = -1;
            }
        }
    }
}

int checkBingo(BingoCard* card) {
    // Check rows
    for (int r = 0; r < card->rows; r++) {
        if (card->numbers[r][0] == -1 && card->numbers[r][1] == -1 && card->numbers[r][2] == -1 && card->numbers[r][3] == -1 && card->numbers[r][4] == -1) {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < card->cols; c++) {
        if (card->numbers[0][c] == -1 && card->numbers[1][c] == -1 && card->numbers[2][c] == -1 && card->numbers[3][c] == -1 && card->numbers[4][c] == -1) {
            return 1;
        }
    }

    // Check diagonals
    if (card->numbers[0][0] == -1 && card->numbers[1][1] == -1 && card->numbers[2][2] == -1 && card->numbers[3][3] == -1 && card->numbers[4][4] == -1) {
        return 1;
    }

    return 0;
}

int main() {
    BingoCard* card = (BingoCard*)malloc(sizeof(BingoCard));
    initializeBingoCard(card);
    fillBingoCard(card);

    // Simulate drawing balls
    for (int i = 0; i < MAX_BALLS; i++) {
        int number = rand() % MAX_BALLS + 1;
        markBingoCard(card, number);

        if (checkBingo(card)) {
            printf("Bingo!\n");
            break;
        }
    }

    return 0;
}