//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 10

typedef struct Cell {
  int x, y;
  char state;
} Cell;

void draw_map(Cell **map) {
  for (int y = 0; y < MAP_SIZE; y++) {
    for (int x = 0; x < MAP_SIZE; x++) {
      printf("%c ", map[x][y].state);
    }
    printf("\n");
  }
}

void move_ball(Cell **map, Cell *ball) {
  switch (ball->state) {
    case 'w':
      ball->y--;
      break;
    case 'a':
      ball->x--;
      break;
    case 's':
      ball->y++;
      break;
    case 'd':
      ball->x++;
      break;
  }

  if (ball->x < 0 || ball->x >= MAP_SIZE) {
    ball->state = 'a';
  }
  if (ball->y < 0 || ball->y >= MAP_SIZE) {
    ball->state = 'w';
  }
}

int main() {
  Cell **map = (Cell **)malloc(MAP_SIZE * MAP_SIZE * sizeof(Cell));
  for (int y = 0; y < MAP_SIZE; y++) {
    for (int x = 0; x < MAP_SIZE; x++) {
      map[x][y].state = '#';
    }
  }

  Cell ball = {0, 0, '.'};

  map[ball.x][ball.y].state = 'o';

  draw_map(map);

  while (1) {
    move_ball(map, &ball);
    draw_map(map);

    if (ball.state == 'o') {
      printf("You won!");
      break;
    }
  }

  return 0;
}