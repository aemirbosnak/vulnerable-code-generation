//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

typedef struct Map {
  int w, h;
  Node** data;
} Map;

Map* generateMap(int w, int h) {
  Map* map = malloc(sizeof(Map));
  map->w = w;
  map->h = h;
  map->data = malloc(w * h * sizeof(Node));

  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      map->data[y * w + x] = NULL;
    }
  }

  return map;
}

void placeObstacles(Map* map) {
  for (int i = 0; i < map->w * map->h; i++) {
    if (rand() % 5 == 0) {
      map->data[i] = malloc(sizeof(Node));
      map->data[i]->x = i % map->w;
      map->data[i]->y = i / map->h;
    }
  }
}

void traverseMap(Map* map) {
  for (Node* node = map->data[0]; node; node = node->next) {
    printf("(%d, %d)\n", node->x, node->y);
  }
}

int main() {
  srand(time(NULL));

  Map* map = generateMap(10, 10);
  placeObstacles(map);
  traverseMap(map);

  return 0;
}