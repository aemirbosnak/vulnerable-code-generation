//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_BALLS 10

typedef struct Ball {
    int x, y;
    struct Ball* next;
} Ball;

Ball* createBall(int x, int y) {
    Ball* newBall = (Ball*)malloc(sizeof(Ball));
    newBall->x = x;
    newBall->y = y;
    newBall->next = NULL;
    return newBall;
}

void addBall(Ball* head, int x, int y) {
    Ball* newBall = createBall(x, y);
    if (head == NULL) {
        head = newBall;
    } else {
        newBall->next = head;
        head = newBall;
    }
}

void moveBalls(Ball* head) {
    Ball* currentBall = head;
    while (currentBall) {
        currentBall->x++;
        currentBall->y++;
        currentBall = currentBall->next;
    }
}

int main() {
    Ball* head = NULL;
    addBall(head, 0, 0);
    addBall(head, 1, 0);
    addBall(head, 2, 0);

    moveBalls(head);

    Ball* currentBall = head;
    while (currentBall) {
        printf("Ball at (%d, %d)\n", currentBall->x, currentBall->y);
        currentBall = currentBall->next;
    }

    return 0;
}