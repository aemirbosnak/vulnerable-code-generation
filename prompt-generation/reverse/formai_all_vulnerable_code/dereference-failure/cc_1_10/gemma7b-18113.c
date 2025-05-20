//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_BINGO_CARD_SIZE 5
#define MAX_BINGO_BALLS 10

typedef struct BingoCard {
    int **numbers;
    int size;
    int balls_drawn;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
    card->numbers = (int **)malloc(card->size * sizeof(int *));
    for (int i = 0; i < card->size; i++) {
        card->numbers[i] = (int *)malloc(card->size * sizeof(int));
    }
    card->balls_drawn = 0;
}

void drawBall(BingoCard *card) {
    int number = rand() % MAX_BINGO_BALLS + 1;
    card->balls_drawn++;

    for (int i = 0; i < card->size; i++) {
        for (int j = 0; j < card->size; j++) {
            if (card->numbers[i][j] == number) {
                card->numbers[i][j] = -1;
            }
        }
    }
}

void checkBingo(BingoCard *card) {
    for (int i = 0; i < card->size; i++) {
        if (card->numbers[i][0] == -1 && card->numbers[i][1] == -1 && card->numbers[i][2] == -1) {
            printf("Bingo! You win!\n");
            exit(0);
        }
    }
}

int main() {
    BingoCard card;
    initializeBingoCard(&card);

    for (int i = 0; i < MAX_BINGO_CARD_SIZE; i++) {
        for (int j = 0; j < MAX_BINGO_CARD_SIZE; j++) {
            card.numbers[i][j] = rand() % MAX_BINGO_BALLS + 1;
        }
    }

    drawBall(&card);
    drawBall(&card);
    drawBall(&card);
    drawBall(&card);
    drawBall(&card);
    checkBingo(&card);

    return 0;
}