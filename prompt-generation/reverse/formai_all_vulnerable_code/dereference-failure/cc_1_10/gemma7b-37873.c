//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_BALLS 50

typedef struct Ball {
  char number;
  struct Ball* next;
} Ball;

Ball* createBall(char number) {
  Ball* newBall = malloc(sizeof(Ball));
  newBall->number = number;
  newBall->next = NULL;
  return newBall;
}

void addBall(Ball* head, char number) {
  Ball* newBall = createBall(number);
  if (head == NULL) {
    head = newBall;
  } else {
    head->next = newBall;
  }
  head = newBall;
}

void playBingo(Ball* head) {
  int i = 0;
  for (Ball* ball = head; ball; ball = ball->next) {
    if (ball->number == i) {
      printf("%c is called!\n", ball->number);
      ball->number = -1;
    }
    i++;
  }
}

int main() {
  Ball* head = NULL;
  addBall(head, 1);
  addBall(head, 2);
  addBall(head, 3);
  addBall(head, 4);
  addBall(head, 5);
  addBall(head, 6);
  addBall(head, 7);
  addBall(head, 8);
  addBall(head, 9);
  addBall(head, 10);

  playBingo(head);

  return 0;
}