//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define PLAYER_SIZE 5

typedef struct Player {
  int x;
  int y;
  char direction;
} Player;

typedef struct Map {
  int **data;
  int width;
  int height;
} Map;

void initializeMap(Map *map) {
  map->data = (int **)malloc(map->height * sizeof(int *));
  for (int i = 0; i < map->height; i++) {
    map->data[i] = (int *)malloc(map->width * sizeof(int));
  }
  map->width = MAP_SIZE;
  map->height = MAP_SIZE;
}

void generateMap(Map *map) {
  for (int i = 0; i < map->height; i++) {
    for (int j = 0; j < map->width; j++) {
      map->data[i][j] = rand() % 2;
    }
  }
}

void drawMap(Map *map) {
  for (int i = 0; i < map->height; i++) {
    for (int j = 0; j < map->width; j++) {
      printf("%d ", map->data[i][j]);
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));

  Map map;
  initializeMap(&map);
  generateMap(&map);

  Player player;
  player.x = 0;
  player.y = 0;
  player.direction = 'S';

  drawMap(&map);

  while (1) {
    switch (player.direction) {
      case 'S':
        player.y++;
        break;
      case 'N':
        player.y--;
        break;
      case 'E':
        player.x++;
        break;
      case 'W':
        player.x--;
        break;
    }

    if (map.data[player.y][player.x] == 1) {
      printf("Game Over!");
      break;
    }

    drawMap(&map);
  }

  return 0;
}