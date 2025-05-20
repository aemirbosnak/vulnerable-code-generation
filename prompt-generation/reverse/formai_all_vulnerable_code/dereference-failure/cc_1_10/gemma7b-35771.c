//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 20
#define MAX_BALLS 10

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

void addBall(Ball* head, int number) {
    Ball* newBall = createBall(number);
    if (head == NULL) {
        head = newBall;
    } else {
        head->next = newBall;
        head = newBall;
    }
}

void playBingo(Ball* head) {
    srand(time(NULL));
    int ballNumber;
    for (int i = 0; i < MAX_BALLS; i++) {
        ballNumber = rand() % MAX_NUM + 1;
        addBall(head, ballNumber);
    }

    // Bingo card creation and marking
    int cards[MAX_NUM][MAX_NUM] = {{0}};
    for (int r = 0; r < MAX_NUM; r++) {
        for (int c = 0; c < MAX_NUM; c++) {
            cards[r][c] = -1;
        }
    }

    // Drawing balls and marking cards
    for (int i = 0; i < MAX_BALLS; i++) {
        ballNumber = rand() % MAX_NUM + 1;
        for (int r = 0; r < MAX_NUM; r++) {
            for (int c = 0; c < MAX_NUM; c++) {
                if (cards[r][c] == ballNumber) {
                    cards[r][c] = 0;
                }
            }
        }
    }

    // Checking for bingo
    int bingo = 0;
    for (int r = 0; r < MAX_NUM; r++) {
        if (cards[r][0] == 0 && cards[r][1] == 0 && cards[r][2] == 0) {
            bingo = 1;
        }
    }

    // If bingo, announce winner
    if (bingo) {
        printf("Winner!\n");
    }
}

int main() {
    playBingo(NULL);
    return 0;
}