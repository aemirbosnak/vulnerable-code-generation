//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

#define MAP_SIZE 11
#define BALL_SIZE 5

typedef struct Ball {
  int x;
  int y;
  int dir;
} Ball;

void initialize_ball(Ball *ball) {
  ball->x = MAP_SIZE / 2;
  ball->y = MAP_SIZE - 1;
  ball->dir = RIGHT;
}

void move_ball(Ball *ball) {
  switch (ball->dir) {
    case LEFT:
      ball->x--;
      break;
    case RIGHT:
      ball->x++;
      break;
    case UP:
      ball->y--;
      break;
    case DOWN:
      ball->y++;
      break;
  }
}

void draw_map(int **map, Ball *ball) {
  for (int y = 0; y < MAP_SIZE; y++) {
    for (int x = 0; x < MAP_SIZE; x++) {
      if (x == ball->x && y == ball->y) {
        printf("O ");
      } else if (map[x][y] == 1) {
        printf("# ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
}

int main() {
  int map[MAP_SIZE][MAP_SIZE] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
  };

  Ball ball;
  initialize_ball(&ball);

  while (1) {
    move_ball(&ball);
    draw_map(map, &ball);

    if (ball.x < 0 || ball.x >= MAP_SIZE - 1) {
      ball.dir = (ball.dir == LEFT) ? RIGHT : LEFT;
    }
    if (ball.y < 0) {
      ball.dir = UP;
    }
    if (ball.y >= MAP_SIZE - 1) {
      ball.dir = DOWN;
    }

    if (map[ball.x][ball.y] == 1) {
      printf("Game Over!");
      break;
    }

    sleep(0.1);
  }

  return 0;
}