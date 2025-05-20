//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_BALLS 10

typedef struct Ball {
    int number;
    struct Ball* next;
} Ball;

void insertBall(Ball* head, int number) {
    Ball* newBall = malloc(sizeof(Ball));
    newBall->number = number;
    newBall->next = NULL;

    if (head == NULL) {
        head = newBall;
    } else {
        head->next = newBall;
    }
}

void playBingo(Ball* head) {
    int bingoNumbers[MAX_NUM_BALLS] = {0};
    int i = 0;

    while (head) {
        int number = head->number;
        bingoNumbers[number]++;

        if (bingoNumbers[number] == 2) {
            printf("Bingo! Ball number %d\n", number);
            i++;
        }

        head = head->next;
    }

    if (i == MAX_NUM_BALLS) {
        printf("No winner!\n");
    }
}

int main() {
    Ball* head = NULL;

    // Insert some balls into the bingo cage
    insertBall(head, 1);
    insertBall(head, 2);
    insertBall(head, 3);
    insertBall(head, 4);
    insertBall(head, 5);
    insertBall(head, 6);
    insertBall(head, 7);
    insertBall(head, 8);
    insertBall(head, 9);
    insertBall(head, 10);

    // Play bingo
    playBingo(head);

    return 0;
}