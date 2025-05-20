//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Knuth's Bingo Simulator
// A Donald Knuth-style C program

#define NUM_BALLS 75
#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct Ball {
    int number;
    struct Ball* next;
} Ball;

typedef struct BingoCard {
    int** cards;
    Ball* head;
} BingoCard;

void initializeBingoCard(BingoCard* card) {
    card->cards = malloc(NUM_ROWS * sizeof(int*));
    for (int r = 0; r < NUM_ROWS; r++) {
        card->cards[r] = malloc(NUM_COLS * sizeof(int));
        for (int c = 0; c < NUM_COLS; c++) {
            card->cards[r][c] = 0;
        }
    }

    card->head = NULL;
}

void addBallToCard(BingoCard* card, int number) {
    Ball* newBall = malloc(sizeof(Ball));
    newBall->number = number;
    newBall->next = card->head;
    card->head = newBall;
}

void playBingo(BingoCard* card) {
    srand(time(NULL));
    for (int i = 0; i < NUM_BALLS; i++) {
        int number = rand() % NUM_BALLS + 1;
        addBallToCard(card, number);
    }

    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLS; c++) {
            if (card->cards[r][c] == 1) {
                printf("Bingo! Row: %d, Column: %d\n", r, c);
            }
        }
    }
}

int main() {
    BingoCard* card = malloc(sizeof(BingoCard));
    initializeBingoCard(card);

    playBingo(card);

    return 0;
}