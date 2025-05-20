//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BALLS 50

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
  }
}

void playBingo(Ball* head) {
  time_t t = time(NULL);
  srand(t);
  int drawnBallNumber;
  int bingo = 0;
  int i = 0;

  for (i = 0; i < MAX_BALLS && !bingo; i++) {
    drawnBallNumber = rand() % MAX_BALLS + 1;
    printf("Ball drawn: %d\n", drawnBallNumber);

    if (head->number == drawnBallNumber) {
      bingo = 1;
      printf("Bingo! You won!\n");
    } else {
      addBall(head, drawnBallNumber);
    }
  }

  if (!bingo) {
    printf("Sorry, you lose.\n");
  }
}

int main() {
  Ball* head = NULL;
  playBingo(head);
  return 0;
}