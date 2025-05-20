//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 9
#define MAX_BALLS 10

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
}

void playBingo(Ball* head) {
  int winningNumbers[MAX_NUM] = {0};
  int ballsDrawn = 0;

  while (ballsDrawn < MAX_BALLS) {
    int numberDrawn = rand() % MAX_NUM + 1;

    for (Ball* currentBall = head; currentBall; currentBall = currentBall->next) {
      if (currentBall->number == numberDrawn && winningNumbers[currentBall->number] == 0) {
        winningNumbers[currentBall->number] = 1;
        ballsDrawn++;
      }
    }
  }

  int hasWon = 0;
  for (int i = 1; i <= MAX_NUM; i++) {
    if (winningNumbers[i] == 1) {
      hasWon = 1;
    }
  }

  if (hasWon) {
    printf("Congratulations! You have won!\n");
  } else {
    printf("Sorry, you have not won.\n");
  }
}

int main() {
  srand(time(NULL));

  Ball* head = NULL;
  insertBall(head, 1);
  insertBall(head, 2);
  insertBall(head, 3);
  insertBall(head, 4);
  insertBall(head, 5);
  insertBall(head, 6);
  insertBall(head, 7);
  insertBall(head, 8);
  insertBall(head, 9);

  playBingo(head);

  return 0;
}