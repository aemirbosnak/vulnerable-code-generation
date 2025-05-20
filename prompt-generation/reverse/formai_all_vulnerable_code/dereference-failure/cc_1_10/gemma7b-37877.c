//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BALLS 75

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

void insertBall(Ball* head, int number) {
    Ball* newBall = createBall(number);
    if (head == NULL) {
        head = newBall;
    } else {
        head->next = newBall;
        head = newBall;
    }
}

int drawBall(Ball* head) {
    srand(time(NULL));
    int randomIndex = rand() % MAX_BALLS;
    Ball* currentBall = head;
    for (int i = 0; i < randomIndex; i++) {
        currentBall = currentBall->next;
    }
    return currentBall->number;
}

int main() {
    Ball* head = NULL;
    for (int i = 0; i < MAX_BALLS; i++) {
        insertBall(head, i + 1);
    }

    // Play the game
    int ballNumber = drawBall(head);
    printf("The drawn ball number is: %d\n", ballNumber);

    return 0;
}