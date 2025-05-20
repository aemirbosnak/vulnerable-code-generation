//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_BALLS 10

typedef struct Ball {
    int x, y;
    struct Ball* next;
} Ball;

Ball* createBall(int x, int y) {
    Ball* ball = malloc(sizeof(Ball));
    ball->x = x;
    ball->y = y;
    ball->next = NULL;
    return ball;
}

void addBall(Ball* ball) {
    Ball* head = NULL;
    if (head == NULL) {
        head = ball;
    } else {
        head->next = ball;
        head = ball;
    }
}

void moveBall(Ball* ball, int dx, int dy) {
    ball->x += dx;
    ball->y += dy;
}

void drawBall(Ball* ball) {
    printf("(");
    printf("%d, %d)", ball->x, ball->y);
    printf(")\n");
}

int main() {
    Ball* head = NULL;
    for (int i = 0; i < MAX_BALLS; i++) {
        addBall(createBall(i, i));
    }

    for (Ball* ball = head; ball; ball = ball->next) {
        drawBall(ball);
        moveBall(ball, 1, 1);
    }

    return 0;
}