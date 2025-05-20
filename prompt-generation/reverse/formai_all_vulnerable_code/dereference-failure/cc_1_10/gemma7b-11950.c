//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_BALLS 10

typedef struct Ball {
    int number;
    struct Ball* next;
} Ball;

Ball* CreateBall(int num) {
    Ball* newBall = malloc(sizeof(Ball));
    newBall->number = num;
    newBall->next = NULL;
    return newBall;
}

void InsertBall(Ball* head, int num) {
    Ball* newBall = CreateBall(num);
    if (head == NULL) {
        head = newBall;
    } else {
        head->next = newBall;
    }
}

void PlayBingo(Ball* head) {
    srand(time(NULL));
    int drawNumber = rand() % MAX_NUM_BALLS + 1;
    printf("The drawn number is: %d\n", drawNumber);

    Ball* currentBall = head;
    while (currentBall) {
        if (currentBall->number == drawNumber) {
            printf("Congratulations! You have won!\n");
            break;
        }
        currentBall = currentBall->next;
    }

    if (currentBall == NULL) {
        printf("Sorry, you have not won.\n");
    }
}

int main() {
    Ball* head = NULL;

    // Insert some balls into the bingo cage
    InsertBall(head, 1);
    InsertBall(head, 2);
    InsertBall(head, 3);
    InsertBall(head, 4);
    InsertBall(head, 5);
    InsertBall(head, 6);
    InsertBall(head, 7);
    InsertBall(head, 8);
    InsertBall(head, 9);
    InsertBall(head, 10);

    PlayBingo(head);

    return 0;
}