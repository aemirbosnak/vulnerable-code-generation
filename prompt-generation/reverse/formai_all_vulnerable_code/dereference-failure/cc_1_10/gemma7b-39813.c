//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_BALLS 20

typedef struct Ball {
    int number;
    struct Ball* next;
} Ball;

Ball* createBall(int num) {
    Ball* newBall = malloc(sizeof(Ball));
    newBall->number = num;
    newBall->next = NULL;
    return newBall;
}

void playBingo(Ball* balls) {
    int i, num, bingo = 0;
    printf("Let's play bingo!\n");

    for (i = 0; i < MAX_NUM_BALLS && !bingo; i++) {
        num = rand() % MAX_NUM_BALLS + 1;
        printf("Ball drawn: %d\n", num);

        for (Ball* ball = balls; ball; ball = ball->next) {
            if (ball->number == num) {
                bingo = 1;
                printf("Bingo! You won!\n");
                break;
            }
        }
    }

    if (!bingo) {
        printf("Sorry, no bingo. Better luck next time.\n");
    }
}

int main() {
    Ball* balls = createBall(1);
    createBall(2);
    createBall(3);
    createBall(4);
    createBall(5);

    playBingo(balls);

    return 0;
}