//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_BALLS 10
#define MAX_NUM_ROWS 5
#define MAX_NUM_COLS 5

typedef struct Ball {
    int number;
    struct Ball* next;
} Ball;

typedef struct BingoCard {
    int numRows;
    int numCols;
    Ball** balls;
} BingoCard;

void initializeBingoCard(BingoCard* card) {
    card->numRows = MAX_NUM_ROWS;
    card->numCols = MAX_NUM_COLS;
    card->balls = (Ball**)malloc(sizeof(Ball*) * card->numRows * card->numCols);
    for (int i = 0; i < card->numRows * card->numCols; i++) {
        card->balls[i] = NULL;
    }
}

void addBallToCard(BingoCard* card, int number) {
    Ball* newBall = (Ball*)malloc(sizeof(Ball));
    newBall->number = number;
    newBall->next = NULL;

    if (card->balls[number] == NULL) {
        card->balls[number] = newBall;
    } else {
        card->balls[number]->next = newBall;
    }
}

void playBingo(BingoCard* card) {
    srand(time(NULL));
    for (int i = 0; i < MAX_NUM_BALLS; i++) {
        int number = rand() % MAX_NUM_BALLS + 1;
        addBallToCard(card, number);
    }

    for (int i = 0; i < card->numRows; i++) {
        for (int j = 0; j < card->numCols; j++) {
            if (card->balls[i * card->numCols + j] != NULL) {
                printf("Ball: %d, Row: %d, Column: %d\n", card->balls[i * card->numCols + j]->number, i, j);
            }
        }
    }
}

int main() {
    BingoCard* card = (BingoCard*)malloc(sizeof(BingoCard));
    initializeBingoCard(card);
    playBingo(card);

    return 0;
}