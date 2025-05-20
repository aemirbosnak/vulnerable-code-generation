//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

#define EMPTY 0
#define WALL 1
#define PLAYER 2

void generateMaze(int **map) {
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      map[y][x] = EMPTY;
    }
  }

  int num_walls = rand() % (MAP_WIDTH * MAP_HEIGHT) / 2;

  for (int i = 0; i < num_walls; i++) {
    int x = rand() % MAP_WIDTH;
    int y = rand() % MAP_HEIGHT;

    if (map[y][x] == EMPTY) {
      map[y][x] = WALL;
    }
  }

  map[0][0] = PLAYER;
}

int main() {
  int **map = (int **)malloc(MAP_HEIGHT * sizeof(int *));
  for (int i = 0; i < MAP_HEIGHT; i++) {
    map[i] = (int *)malloc(MAP_WIDTH * sizeof(int));
  }

  generateMaze(map);

  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      switch (map[y][x]) {
        case EMPTY:
          printf(" ");
          break;
        case WALL:
          printf("#");
          break;
        case PLAYER:
          printf("P");
          break;
      }
    }
    printf("\n");
  }

  free(map);

  return 0;
}