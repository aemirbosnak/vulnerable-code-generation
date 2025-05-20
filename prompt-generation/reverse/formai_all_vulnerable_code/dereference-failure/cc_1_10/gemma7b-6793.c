//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>

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

void addBall(Ball* head, int number) {
    Ball* newBall = createBall(number);
    if (head == NULL) {
        head = newBall;
    } else {
        head->next = newBall;
        head = newBall;
    }
}

int main() {
    Ball* head = NULL;
    int balls = 0;

    // Generate balls
    while (balls < MAX_BALLS) {
        addBall(head, rand() % MAX_BALLS + 1);
        balls++;
    }

    // Bingo time
    printf("Let's play Bingo!\n");

    // Get the user's number
    int userNumber = 0;
    printf("Enter your number: ");
    scanf("%d", &userNumber);

    // Check if the user's number is in the balls
    Ball* currentBall = head;
    while (currentBall) {
        if (currentBall->number == userNumber) {
            printf("Bingo! You won!\n");
            break;
        }
        currentBall = currentBall->next;
    }

    // If the user did not win, print an error message
    if (currentBall == NULL) {
        printf("Sorry, you lose.\n");
    }

    return 0;
}