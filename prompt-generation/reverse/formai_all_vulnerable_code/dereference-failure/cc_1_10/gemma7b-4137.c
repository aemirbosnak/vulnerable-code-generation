//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 20
#define MAX_BALLS 10

typedef struct Ball {
  int number;
  struct Ball* next;
} Ball;

Ball* create_ball(int num) {
  Ball* ball = malloc(sizeof(Ball));
  ball->number = num;
  ball->next = NULL;
  return ball;
}

void play_bingo(Ball* balls) {
  int i, num, bingo = 0;
  time_t t;
  srand(time(NULL));

  for (i = 0; i < MAX_BALLS; i++) {
    num = rand() % MAX_NUM + 1;
    printf("Ball drawn: %d\n", num);
    for (balls = balls; balls; balls = balls->next) {
      if (balls->number == num) {
        balls->number = -1;
        bingo = 1;
      }
    }
  }

  if (bingo) {
    printf("Bingo!\n");
  } else {
    printf("No bingo.\n");
  }
}

int main() {
  Ball* balls = create_ball(1);
  create_ball(2);
  create_ball(3);
  create_ball(4);
  create_ball(5);
  play_bingo(balls);

  return 0;
}