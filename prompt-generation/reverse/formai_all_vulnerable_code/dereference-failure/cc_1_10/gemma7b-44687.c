//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BALLS 20
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
    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->cols; c++) {
            card->numbers[r][c] = 0;
        }
    }
}

void generateBingoBalls(Ball* head) {
    srand(time(NULL));
    for (int i = 0; i < MAX_BALLS; i++) {
        int number = rand() % MAX_BALLS + 1;
        Ball* newBall = (Ball*)malloc(sizeof(Ball));
        newBall->number = number;
        newBall->next = head;
        head = newBall;
    }
}

void playBingo(BingoCard* card) {
    Ball* balls = card->numbers[0];
    while (balls) {
        for (int r = 0; r < card->rows; r++) {
            for (int c = 0; c < card->cols; c++) {
                if (balls->number == card->numbers[r][c]) {
                    card->numbers[r][c] = -1;
                }
            }
        }
        balls = balls->next;
    }
    if (card->numbers[0][0] == -1) {
        printf("Congratulations! You won!");
    } else {
        printf("Sorry, you lose.");
    }
}

int main() {
    BingoCard* card = (BingoCard*)malloc(sizeof(BingoCard));
    initializeBingoCard(card);
    generateBingoBalls(card->numbers[0]);
    playBingo(card);
    return 0;
}