//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_CARD_SIZE 5
#define MAX_NUMBER_OF_BALLS 10

typedef struct BingoCard {
    int **numbers;
    int rows;
    int columns;
} BingoCard;

void initializeBingoCard(BingoCard *card, int rows, int columns) {
    card->rows = rows;
    card->columns = columns;
    card->numbers = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        card->numbers[i] = (int *)malloc(sizeof(int) * columns);
    }
}

void generateBingoBall(BingoCard *card) {
    int number;
    do {
        number = rand() % MAX_NUMBER_OF_BALLS + 1;
    } while (card->numbers[number - 1][0] == 0);
    card->numbers[number - 1][0] = 1;
}

void checkBingo(BingoCard *card) {
    for (int i = 0; i < card->rows; i++) {
        for (int j = 0; j < card->columns; j++) {
            if (card->numbers[i][j] == 0) {
                return;
            }
        }
    }
    printf("Bingo!");
}

int main() {
    BingoCard *card = NULL;
    initializeBingoCard(&card, MAX_BINGO_CARD_SIZE, MAX_BINGO_CARD_SIZE);
    for (int i = 0; i < 5; i++) {
        generateBingoBall(card);
    }
    checkBingo(card);
    return 0;
}