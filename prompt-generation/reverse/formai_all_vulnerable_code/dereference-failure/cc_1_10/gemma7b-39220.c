//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_BALLS 20
#define MAX_ROWS 5
#define MAX_COLS 5

typedef struct Ball {
  char number;
  struct Ball* next;
} Ball;

void initializeBall(Ball* ball, int number) {
  ball->number = number;
  ball->next = NULL;
}

void insertBall(Ball* head, Ball* newBall) {
  if (head == NULL) {
    head = newBall;
  } else {
    head->next = newBall;
    head = newBall;
  }
}

void playBingo(Ball* balls) {
  int i, j, k;
  int bingo[MAX_ROWS][MAX_COLS] = {{0}};

  for (i = 0; i < MAX_ROWS; i++) {
    for (j = 0; j < MAX_COLS; j++) {
      bingo[i][j] = 0;
    }
  }

  // Draw balls
  for (k = 0; k < MAX_BALLS; k++) {
    int number = rand() % MAX_BALLS + 1;
    Ball* newBall = malloc(sizeof(Ball));
    initializeBall(newBall, number);
    insertBall(balls, newBall);
  }

  // Mark numbers on bingo card
  for (k = 0; k < MAX_BALLS; k++) {
    Ball* currentBall = balls;
    while (currentBall) {
      if (currentBall->number == k + 1) {
        bingo[currentBall->number / MAX_COLS][currentBall->number % MAX_COLS] = 1;
      }
      currentBall = currentBall->next;
    }
  }

  // Check for bingo
  for (i = 0; i < MAX_ROWS; i++) {
    for (j = 0; j < MAX_COLS; j++) {
      if (bingo[i][j] == 5) {
        printf("Bingo! Number: %d\n", i * MAX_COLS + j + 1);
        exit(0);
      }
    }
  }

  printf("No bingo.\n");
  exit(0);
}

int main() {
  Ball* balls = NULL;
  playBingo(balls);
  return 0;
}