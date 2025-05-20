//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void addBall(Ball* head, int num) {
  Ball* newBall = createBall(num);
  if (head == NULL) {
    head = newBall;
  } else {
    head->next = newBall;
  }
}

void playBingo(Ball* head) {
  srand(time(NULL));
  int ballNum = rand() % MAX_NUM_BALLS + 1;
  while (head && head->number != ballNum) {
    head = head->next;
  }
  if (head) {
    printf("Bingo! Number: %d\n", ballNum);
  } else {
    printf("Sorry, no match.\n");
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