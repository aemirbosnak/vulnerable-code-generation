//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BALLS 50

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
  }
}

void playBingo(Ball* head) {
  int ballsDrawn = 0;
  while (ballsDrawn < MAX_BALLS) {
    int number = rand() % MAX_BALLS + 1;
    Ball* ball = head;
    while (ball) {
      if (ball->number == number) {
        printf("Ball drawn: %d\n", number);
        ballsDrawn++;
        break;
      }
      ball = ball->next;
    }
  }
}

int main() {
  srand(time(NULL));
  Ball* head = NULL;
  addBall(head, 1);
  addBall(head, 2);
  addBall(head, 3);
  addBall(head, 4);
  addBall(head, 5);
  playBingo(head);
  return 0;
}