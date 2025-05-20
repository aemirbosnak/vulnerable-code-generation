//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BALLS 30

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

void printBalls(Ball* ball) {
    while (ball) {
        printf("%d ", ball->number);
        ball = ball->next;
    }
    printf("\n");
}

void playBingo(Ball* balls) {
    srand(time(NULL));
    int drawnBalls = 0;
    while (drawnBalls < MAX_BALLS) {
        int number = rand() % MAX_BALLS + 1;
        Ball* ball = balls;
        while (ball) {
            if (ball->number == number) {
                ball->number = -1;
                drawnBalls++;
                break;
            }
            ball = ball->next;
        }
    }

    Ball* winner = balls;
    while (winner) {
        if (winner->number != -1) {
            winner = NULL;
        } else {
            winner = winner->next;
        }
    }

    if (winner) {
        printf("Winner: %d\n", winner->number);
    } else {
        printf("No winner\n");
    }
}

int main() {
    Ball* balls = createBall(1);
    balls = createBall(2);
    balls = createBall(3);
    balls = createBall(4);
    balls = createBall(5);
    balls = createBall(6);
    balls = createBall(7);
    balls = createBall(8);
    balls = createBall(9);
    balls = createBall(10);

    playBingo(balls);

    return 0;
}