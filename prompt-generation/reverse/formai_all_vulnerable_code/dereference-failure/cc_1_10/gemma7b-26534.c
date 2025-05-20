//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_BALLS 10

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

void insertBall(Ball* head, int number) {
  Ball* newBall = createBall(number);
  if (head == NULL) {
    head = newBall;
  } else {
    newBall->next = head;
    head = newBall;
  }
}

void playBingo(Ball* head) {
  int drawnNumbers[MAX_NUM_BALLS];
  int i = 0;

  // Draw balls
  for (i = 0; i < MAX_NUM_BALLS; i++) {
    drawnNumbers[i] = rand() % MAX_NUM_BALLS + 1;
  }

  // Check if the player has won
  for (Ball* ball = head; ball; ball = ball->next) {
    for (i = 0; i < MAX_NUM_BALLS; i++) {
      if (ball->number == drawnNumbers[i]) {
        printf("You have won!\n");
        exit(0);
      }
    }
  }

  // If the player has not won, print a message
  printf("Sorry, you have not won.\n");
}

int main() {
  Ball* head = NULL;
  insertBall(head, 1);
  insertBall(head, 2);
  insertBall(head, 3);
  insertBall(head, 4);
  insertBall(head, 5);

  playBingo(head);

  return 0;
}