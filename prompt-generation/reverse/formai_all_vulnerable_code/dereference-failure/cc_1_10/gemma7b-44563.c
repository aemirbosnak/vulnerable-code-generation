//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: dynamic
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
  head = newBall;
}

void playBingo(Ball* head) {
  int bingoNumbers[MAX_BALLS] = {0};
  srand(time(NULL));
  for (int i = 0; i < MAX_BALLS; i++) {
    int number = rand() % MAX_BALLS + 1;
    if (bingoNumbers[number] == 0) {
      bingoNumbers[number] = 1;
    }
  }

  for (Ball* ball = head; ball; ball = ball->next) {
    if (bingoNumbers[ball->number] == 1) {
      printf("Bingo! Ball number: %d\n", ball->number);
    }
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