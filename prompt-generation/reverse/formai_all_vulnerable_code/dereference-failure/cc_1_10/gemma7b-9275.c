//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_BALLS 10

typedef struct Ball {
    int number;
    struct Ball* next;
} Ball;

Ball* createBall(int number) {
    Ball* newBall = malloc(sizeof(Ball));
    newBall->number = number;
    newBall->next = NULL;
    return newBall;
}

void playBingo(Ball* balls) {
    int numBalls = 0;
    for (Ball* currentBall = balls; currentBall; currentBall = currentBall->next) {
        numBalls++;
    }
    printf("Number of balls: %d\n", numBalls);

    int drawnNumbers[MAX_NUM_BALLS];
    for (int i = 0; i < MAX_NUM_BALLS; i++) {
        drawnNumbers[i] = -1;
    }

    int drawnNumber = 0;
    while (numBalls > 0) {
        drawnNumber = rand() % MAX_NUM_BALLS;
        if (drawnNumbers[drawnNumber] == -1) {
            drawnNumbers[drawnNumber] = 0;
            numBalls--;
            printf("Drawn number: %d\n", drawnNumber);
        }
    }

    printf("Bingo!\n");
}

int main() {
    Ball* balls = createBall(1);
    balls = createBall(2);
    balls = createBall(3);
    balls = createBall(4);
    balls = createBall(5);

    playBingo(balls);

    return 0;
}