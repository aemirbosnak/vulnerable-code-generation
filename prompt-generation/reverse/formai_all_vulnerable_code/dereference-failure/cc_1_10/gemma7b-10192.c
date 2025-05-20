//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10
#define MAX_BALLS 20

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

void insertBall(Ball* head, int number) {
    Ball* newBall = createBall(number);
    if (head == NULL) {
        head = newBall;
    } else {
        head->next = newBall;
    }
}

void playBingo(Ball* head) {
    int bingoNumbers[MAX_NUM] = {0};
    for (int i = 0; i < MAX_NUM; i++) {
        bingoNumbers[i] = rand() % MAX_BALLS + 1;
    }

    for (Ball* ball = head; ball; ball = ball->next) {
        if (bingoNumbers[ball->number - 1] == 1) {
            printf("Bingo! Ball number: %d\n", ball->number);
            bingoNumbers[ball->number - 1] = 2;
        }
    }
}

int main() {
    Ball* head = NULL;
    insertBall(head, 1);
    insertBall(head, 3);
    insertBall(head, 5);
    insertBall(head, 7);
    insertBall(head, 9);
    insertBall(head, 11);

    playBingo(head);

    return 0;
}