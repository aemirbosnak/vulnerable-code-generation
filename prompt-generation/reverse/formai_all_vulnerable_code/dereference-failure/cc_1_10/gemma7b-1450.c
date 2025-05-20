//Gemma-7B DATASET v1.0 Category: Pac-Man Game Clone ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 20
#define PACMAN_SIZE 5

typedef struct Pacman {
  int x, y;
  int direction;
} Pacman;

void draw_map(int **map, Pacman pac) {
  for (int r = 0; r < MAP_SIZE; r++) {
    for (int c = 0; c < MAP_SIZE; c++) {
      if (map[r][c] == 1) {
        printf("#");
      } else if (pac.x == r && pac.y == c) {
        printf("P");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

void move_pacman(Pacman *pac) {
  switch (pac->direction) {
    case 0:
      pac->y--;
      break;
    case 1:
      pac->x++;
      break;
    case 2:
      pac->y++;
      break;
    case 3:
      pac->x--;
      break;
  }
}

int main() {
  int map[MAP_SIZE][MAP_SIZE] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
  };

  Pacman pac = {0, 0, 0};

  while (1) {
    draw_map(map, pac);
    move_pacman(&pac);

    if (map[pac.x][pac.y] == 0) {
      printf("You win!");
      break;
    } else if (pac.x == -1 || pac.x == MAP_SIZE - 1 || pac.y == -1 || pac.y == MAP_SIZE - 1) {
      printf("Game over!");
      break;
    }
  }

  return 0;
}