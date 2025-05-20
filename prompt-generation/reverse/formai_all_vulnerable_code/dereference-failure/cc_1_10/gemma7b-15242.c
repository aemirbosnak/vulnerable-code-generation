//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 25
#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct BingoCard {
    int **numbers;
    int **markedNumbers;
    int wins;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
    card->numbers = (int **)malloc(NUM_ROWS * sizeof(int *));
    card->markedNumbers = (int **)malloc(NUM_ROWS * sizeof(int *));
    for (int r = 0; r < NUM_ROWS; r++) {
        card->numbers[r] = (int *)malloc(NUM_COLS * sizeof(int));
        card->markedNumbers[r] = (int *)malloc(NUM_COLS * sizeof(int));
    }
    card->wins = 0;
}

void generateBingoNumbers(BingoCard *card) {
    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLS; c++) {
            card->numbers[r][c] = rand() % MAX_NUM + 1;
        }
    }
}

void markBingoNumber(BingoCard *card, int number) {
    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLS; c++) {
            if (card->numbers[r][c] == number) {
                card->markedNumbers[r][c] = 1;
            }
        }
    }
}

int checkBingo(BingoCard *card) {
    // Check rows
    for (int r = 0; r < NUM_ROWS; r++) {
        if (card->markedNumbers[r][0] && card->markedNumbers[r][1] && card->markedNumbers[r][2] && card->markedNumbers[r][3] && card->markedNumbers[r][4] == 1) {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < NUM_COLS; c++) {
        if (card->markedNumbers[0][c] && card->markedNumbers[1][c] && card->markedNumbers[2][c] && card->markedNumbers[3][c] && card->markedNumbers[4][c] == 1) {
            return 1;
        }
    }

    // Check diagonals
    if (card->markedNumbers[0][0] && card->markedNumbers[1][1] && card->markedNumbers[2][2] && card->markedNumbers[3][3] && card->markedNumbers[4][4] == 1) {
        return 1;
    }

    return 0;
}

int main() {
    BingoCard card;
    initializeBingoCard(&card);
    generateBingoNumbers(&card);

    // Play the game
    for (int i = 0; i < 10; i++) {
        markBingoNumber(&card, rand() % MAX_NUM + 1);
        if (checkBingo(&card)) {
            card.wins++;
            printf("Bingo! You won %d times!\n", card.wins);
            break;
        }
    }

    return 0;
}