//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BALLS 10
#define MAX_BINGO_CARD 5

typedef struct Ball {
    int number;
    struct Ball* next;
} Ball;

typedef struct BingoCard {
    int** numbers;
    int rows;
    int columns;
    struct BingoCard* next;
} BingoCard;

void initializeBingoCard(BingoCard* card) {
    card->numbers = (int**)malloc(card->rows * sizeof(int*));
    for (int r = 0; r < card->rows; r++) {
        card->numbers[r] = (int*)malloc(card->columns * sizeof(int));
    }
    card->rows = card->columns = 0;
}

void addBallToBingoCard(BingoCard* card, int number) {
    Ball* newBall = (Ball*)malloc(sizeof(Ball));
    newBall->number = number;
    newBall->next = NULL;

    if (card->numbers[0] == NULL) {
        initializeBingoCard(card);
    }

    Ball* tail = card->numbers[card->rows]++;
    tail->next = newBall;
}

int main() {
    srand(time(NULL));

    BingoCard* head = (BingoCard*)malloc(sizeof(BingoCard));
    initializeBingoCard(head);

    // Generate MAX_BALLS random numbers
    for (int i = 0; i < MAX_BALLS; i++) {
        addBallToBingoCard(head, rand() % MAX_BALLS + 1);
    }

    // Print the bingo card
    for (BingoCard* card = head; card; card = card->next) {
        for (int r = 0; r < card->rows; r++) {
            for (int c = 0; c < card->columns; c++) {
                printf("%d ", card->numbers[r][c]);
            }
            printf("\n");
        }
    }

    return 0;
}