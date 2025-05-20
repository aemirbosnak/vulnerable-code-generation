//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 20
#define MAX_BALLS 10

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
  time_t t = time(NULL);
  srand(t);
  int drawNumber = rand() % MAX_NUM + 1;

  for (Ball* ball = balls; ball; ball = ball->next) {
    if (ball->number == drawNumber) {
      printf("Bingo! Ball number %d has been drawn!\n", drawNumber);
      break;
    }
  }

  if (!balls) {
    printf("No balls have been drawn.\n");
  }
}

int main() {
  Ball* balls = createBall(1);
  balls = createBall(2);
  balls = createBall(3);
  balls = createBall(4);
  balls = createBall(5);
  balls = createBall(6);
  balls = createBall(7);
  balls = createBall(8);
  balls = createBall(9);
  balls = createBall(10);

  playBingo(balls);

  return 0;
}