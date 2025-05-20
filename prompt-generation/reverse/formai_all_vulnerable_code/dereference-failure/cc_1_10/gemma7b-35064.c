//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BINGO_COLUMNS 5
#define NUM_BINGO_ROWS 5

typedef struct BingoCard {
    int **numbers;
    int **marks;
    int wins;
    time_t timestamp;
} BingoCard;

BingoCard *createBingoCard() {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->numbers = malloc(NUM_BINGO_ROWS * sizeof(int *));
    card->marks = malloc(NUM_BINGO_ROWS * sizeof(int *));
    card->wins = 0;
    card->timestamp = time(NULL);

    for (int r = 0; r < NUM_BINGO_ROWS; r++) {
        card->numbers[r] = malloc(NUM_BINGO_COLUMNS * sizeof(int));
        card->marks[r] = malloc(NUM_BINGO_COLUMNS * sizeof(int));
    }

    return card;
}

void drawBingoNumber(BingoCard *card) {
    int number = rand() % 90 + 1;
    for (int r = 0; r < NUM_BINGO_ROWS; r++) {
        for (int c = 0; c < NUM_BINGO_COLUMNS; c++) {
            if (card->numbers[r][c] == number && card->marks[r][c] == 0) {
                card->marks[r][c] = 1;
            }
        }
    }
}

int checkBingo(BingoCard *card) {
    for (int r = 0; r < NUM_BINGO_ROWS; r++) {
        if (card->marks[r][0] == 1 && card->marks[r][1] == 1 && card->marks[r][2] == 1 && card->marks[r][3] == 1 && card->marks[r][4] == 1) {
            return 1;
        }
    }

    for (int c = 0; c < NUM_BINGO_COLUMNS; c++) {
        if (card->marks[0][c] == 1 && card->marks[1][c] == 1 && card->marks[2][c] == 1 && card->marks[3][c] == 1 && card->marks[4][c] == 1) {
            return 1;
        }
    }

    if (card->marks[0][0] == 1 && card->marks[1][1] == 1 && card->marks[2][2] == 1 && card->marks[3][3] == 1 && card->marks[4][4] == 1) {
        return 1;
    }

    return 0;
}

int main() {
    BingoCard *card = createBingoCard();

    for (int i = 0; i < 10; i++) {
        drawBingoNumber(card);
        if (checkBingo(card)) {
            card->wins++;
            printf("Bingo! You won %d times!\n", card->wins);
            break;
        }
    }

    free(card->numbers);
    free(card->marks);
    free(card);

    return 0;
}