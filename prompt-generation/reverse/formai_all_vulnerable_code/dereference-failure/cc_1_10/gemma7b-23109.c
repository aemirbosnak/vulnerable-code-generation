//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10
#define MAX_BALLS 20

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

  head = newBall;
}

void playBingo(Ball* head) {
  srand(time(NULL));
  int winningNumber = rand() % MAX_NUM + 1;

  while (head) {
    if (head->number == winningNumber) {
      printf("Bingo! Number: %d\n", winningNumber);
      break;
    }

    head = head->next;
  }

  if (head == NULL) {
    printf("No winner.\n");
  }
}

int main() {
  Ball* head = NULL;

  // Insert some balls
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

  playBingo(head);

  return 0;
}