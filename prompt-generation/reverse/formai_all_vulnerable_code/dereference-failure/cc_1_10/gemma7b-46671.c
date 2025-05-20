//Gemma-7B DATASET v1.0 Category: Pac-Man Game Clone ; Style: Linus Torvalds
#include <stdlib.h>
#include <stdio.h>

#define MAP_SIZE 20
#define PACMAN_SIZE 5

struct Pacman {
  int x;
  int y;
  int direction;
};

void draw_map(int **map, struct Pacman pacman)
{
  for (int y = 0; y < MAP_SIZE; y++) {
    for (int x = 0; x < MAP_SIZE; x++) {
      if (map[y][x] == 1) {
        printf("#");
      } else if (pacman.x == x && pacman.y == y) {
        printf("o");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

int main()
{
  int **map = malloc(MAP_SIZE * sizeof(int *));
  for (int i = 0; i < MAP_SIZE; i++) {
    map[i] = malloc(MAP_SIZE * sizeof(int));
  }

  struct Pacman pacman;
  pacman.x = 5;
  pacman.y = 5;
  pacman.direction = 1;

  map[pacman.y][pacman.x] = 0;

  while (1) {
    draw_map(map, pacman);

    switch (pacman.direction) {
      case 1:
        pacman.x++;
        break;
      case 2:
        pacman.x--;
        break;
      case 3:
        pacman.y++;
        break;
      case 4:
        pacman.y--;
        break;
    }

    if (map[pacman.y][pacman.x] == 1) {
      printf("Game Over!\n");
      break;
    }

    map[pacman.y][pacman.x] = 0;
  }

  free(map);

  return 0;
}