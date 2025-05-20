//Gemma-7B DATASET v1.0 Category: Pathfinding algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void draw_map(int **map) {
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      switch (map[y][x]) {
        case 0:
          printf(" ");
          break;
        case 1:
          printf("#");
          break;
        case 2:
          printf("P");
          break;
        default:
          printf("!");
          break;
      }
    }
    printf("\n");
  }
}

int main() {
  int** map = (int**)malloc(MAP_HEIGHT * sizeof(int*));
  for (int i = 0; i < MAP_HEIGHT; i++) {
    map[i] = (int*)malloc(MAP_WIDTH * sizeof(int));
  }

  // Generate a map
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      map[y][x] = rand() % 3;
    }
  }

  draw_map(map);

  // Create a list of nodes
  Node* head = NULL;
  Node* tail = NULL;
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->x = 0;
  newNode->y = 0;
  newNode->next = NULL;

  head = tail = newNode;

  // Pathfind
  while (tail->next) {
    int dx = rand() % 4 - 2;
    int dy = rand() % 4 - 2;

    if (dx == 0 && dy == 0) {
      continue;
    }

    if (map[tail->y + dy][tail->x + dx] == 0) {
      newNode = (Node*)malloc(sizeof(Node));
      newNode->x = tail->x + dx;
      newNode->y = tail->y + dy;
      newNode->next = NULL;

      tail->next = newNode;
      tail = newNode;
    }
  }

  draw_map(map);

  return 0;
}