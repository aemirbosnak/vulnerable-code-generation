//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BALLS 10
#define MAX_COLUMNS 5
#define MAX_ROWS 5

typedef struct Ball {
    int number;
    struct Ball* next;
} Ball;

Ball* createBall(int number) {
    Ball* ball = malloc(sizeof(Ball));
    ball->number = number;
    ball->next = NULL;
    return ball;
}

void addBall(Ball* head, int number) {
    Ball* newBall = createBall(number);
    if (head == NULL) {
        head = newBall;
    } else {
        head->next = newBall;
        head = newBall;
    }
}

void printBingoCard(Ball* head) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            Ball* currentBall = head;
            while (currentBall) {
                if (currentBall->number == i * MAX_COLUMNS + j) {
                    printf("%d ", currentBall->number);
                } else {
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
}

int main() {
    srand(time(NULL));
    Ball* head = NULL;
    for (int i = 0; i < MAX_BALLS; i++) {
        addBall(head, rand() % MAX_BALLS + 1);
    }
    printBingoCard(head);
    return 0;
}