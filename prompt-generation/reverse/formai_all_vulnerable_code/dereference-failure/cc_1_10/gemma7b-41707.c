//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10
#define MAX_BALLS 20

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

void insertBall(Ball* head, int number) {
  Ball* newBall = createBall(number);
  if (head == NULL) {
    head = newBall;
  } else {
    head->next = newBall;
  }
}

void printBalls(Ball* head) {
  for (Ball* ball = head; ball; ball = ball->next) {
    printf("%d ", ball->number);
  }
  printf("\n");
}

int main() {
  srand(time(NULL));
  Ball* head = NULL;

  // Create a bunch of balls
  for (int i = 0; i < MAX_BALLS; i++) {
    insertBall(head, rand() % MAX_NUM + 1);
  }

  // Print the balls
  printBalls(head);

  // Bingo!
  printf("Bingo!\n");

  return 0;
}