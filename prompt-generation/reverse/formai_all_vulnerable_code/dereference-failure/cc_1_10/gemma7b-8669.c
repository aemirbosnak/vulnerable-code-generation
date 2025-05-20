//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BALLS 30

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

void addBall(Ball* head, int number) {
    Ball* newBall = createBall(number);
    if (head == NULL) {
        head = newBall;
    } else {
        head->next = newBall;
    }
}

void playBingo(Ball* head) {
    srand(time(NULL));
    int drawnBall = rand() % MAX_BALLS + 1;
    printf("Ball drawn: %d\n", drawnBall);

    Ball* currentBall = head;
    while (currentBall) {
        if (currentBall->number == drawnBall) {
            printf("Bingo! Ball: %d\n", currentBall->number);
            currentBall->next = NULL;
            break;
        }
        currentBall = currentBall->next;
    }

    if (currentBall == NULL) {
        printf("No bingo.\n");
    }
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