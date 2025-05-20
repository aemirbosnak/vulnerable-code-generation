//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_BINGO_CARD_SIZE 5
#define MAX_NUM_BALLS 10

typedef struct BingoCard {
    int **numbers;
    int rows;
    int cols;
    int balls_won;
} BingoCard;

BingoCard *createBingoCard(int rows, int cols) {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->rows = rows;
    card->cols = cols;
    card->numbers = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++) {
        card->numbers[r] = (int *)malloc(cols * sizeof(int));
    }
    card->balls_won = 0;
    return card;
}

void generateBingoBall(BingoCard *card) {
    int num = rand() % MAX_NUM_BALLS + 1;
    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->cols; c++) {
            if (card->numbers[r][c] == num) {
                card->numbers[r][c] = -1;
                card->balls_won++;
            }
        }
    }
}

void printBingoCard(BingoCard *card) {
    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->cols; c++) {
            printf("%d ", card->numbers[r][c]);
        }
        printf("\n");
    }
}

int main() {
    BingoCard *card = createBingoCard(5, 5);
    generateBingoBall(card);
    printBingoCard(card);
    printf("Number of balls won: %d\n", card->balls_won);
    free(card);
    return 0;
}