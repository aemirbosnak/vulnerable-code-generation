//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_BALLS 20

typedef struct Ball {
    int number;
    struct Ball* next;
} Ball;

Ball* createBall(int number) {
    Ball* ball = (Ball*)malloc(sizeof(Ball));
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

int drawBall(Ball* head) {
    if (head == NULL) {
        return -1;
    }
    int number = head->number;
    head = head->next;
    return number;
}

int main() {
    Ball* head = NULL;
    for (int i = 0; i < MAX_BALLS; i++) {
        addBall(head, rand() % 40 + 1);
    }

    int bingoNumbers[5] = {1, 2, 3, 4, 5};
    int bingoNumberIndex = 0;

    for (int round = 0; round < 10; round++) {
        int drawnNumber = drawBall(head);
        for (int i = 0; i < 5; i++) {
            if (drawnNumber == bingoNumbers[i]) {
                bingoNumberIndex++;
            }
        }

        if (bingoNumberIndex == 5) {
            printf("Bingo! Round %d\n", round);
            break;
        }
    }

    return 0;
}