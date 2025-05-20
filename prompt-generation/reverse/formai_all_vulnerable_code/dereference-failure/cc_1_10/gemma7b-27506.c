//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_BALLS 10

typedef struct Ball {
    int number;
    struct Ball* next;
} Ball;

Ball* insertBall(Ball* head, int number) {
    Ball* newBall = malloc(sizeof(Ball));
    newBall->number = number;
    newBall->next = NULL;

    if (head == NULL) {
        head = newBall;
    } else {
        head->next = newBall;
    }

    return head;
}

void playBingo(Ball* head) {
    int numbersCalled = 0;
    int bingo = 0;

    while (numbersCalled < MAX_NUM_BALLS) {
        int number = rand() % MAX_NUM_BALLS + 1;

        if (head->number == number) {
            numbersCalled++;

            if (bingo == 0) {
                bingo = 1;
                printf("Bingo! You won!\n");
            }
        }

        head = head->next;
    }

    if (bingo == 0) {
        printf("Sorry, you lose.\n");
    }
}

int main() {
    Ball* head = insertBall(NULL, 1);
    insertBall(head, 2);
    insertBall(head, 3);
    insertBall(head, 4);
    insertBall(head, 5);

    playBingo(head);

    return 0;
}