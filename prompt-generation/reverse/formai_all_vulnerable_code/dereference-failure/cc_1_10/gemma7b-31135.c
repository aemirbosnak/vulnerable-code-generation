//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_BALLS 10

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

void playBingo(Ball* head) {
    srand(time(NULL));
    int numBallsDrawn = 0;
    while (numBallsDrawn < MAX_NUM_BALLS) {
        int numberDrawn = rand() % MAX_NUM_BALLS + 1;
        for (Ball* ball = head; ball; ball = ball->next) {
            if (ball->number == numberDrawn) {
                printf("Ball number %d has been drawn!\n", ball->number);
                numBallsDrawn++;
                break;
            }
        }
    }
    printf("Congratulations, you have won!");
}

int main() {
    Ball* head = NULL;
    addBall(head, 1);
    addBall(head, 2);
    addBall(head, 3);
    addBall(head, 4);
    addBall(head, 5);
    playBingo(head);
    return 0;
}