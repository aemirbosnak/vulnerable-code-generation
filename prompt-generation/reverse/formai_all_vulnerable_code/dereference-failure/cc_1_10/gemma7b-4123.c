//Gemma-7B DATASET v1.0 Category: Pac-Man Game Clone ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define PACMAN_SIZE 5

typedef struct Pacman {
  int x;
  int y;
  int direction;
  int speed;
} Pacman;

void draw_map(int **map, Pacman pac) {
  for (int y = 0; y < MAP_SIZE; y++) {
    for (int x = 0; x < MAP_SIZE; x++) {
      if (map[y][x] == 1) {
        printf("%c ", '#');
      } else if (pac.x == x && pac.y == y) {
        printf("%c ", 'P');
      } else {
        printf("%c ", '.');
      }
    }
    printf("\n");
  }
}

int main() {
  int **map = (int **)malloc(MAP_SIZE * sizeof(int *));
  for (int i = 0; i < MAP_SIZE; i++) {
    map[i] = (int *)malloc(MAP_SIZE * sizeof(int));
  }

  Pacman pac;
  pac.x = 5;
  pac.y = 5;
  pac.direction = 0;
  pac.speed = 2;

  int score = 0;

  while (1) {
    draw_map(map, pac);
    printf("Score: %d\n", score);

    switch (pac.direction) {
      case 0:
        pac.x++;
        break;
      case 1:
        pac.y++;
        break;
      case 2:
        pac.x--;
        break;
      case 3:
        pac.y--;
        break;
    }

    if (map[pac.y][pac.x] == 1) {
      score++;
      map[pac.y][pac.x] = 0;
    }

    if (pac.x == MAP_SIZE - 1 || pac.x == 0) {
      pac.direction = (pac.direction + 1) % 4;
    }

    if (pac.y == MAP_SIZE - 1 || pac.y == 0) {
      pac.direction = (pac.direction + 1) % 4;
    }

    if (score == MAP_SIZE * MAP_SIZE) {
      draw_map(map, pac);
      printf("You won!");
      break;
    }

    sleep(0.1);
  }

  return 0;
}