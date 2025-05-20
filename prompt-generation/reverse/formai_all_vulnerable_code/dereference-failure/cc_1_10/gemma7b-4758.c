//Gemma-7B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

typedef struct Map {
  int** grid;
  int w, h;
  Node** openList;
  Node** closedList;
} Map;

Map* createMap(int w, int h) {
  Map* m = malloc(sizeof(Map));
  m->grid = malloc(h * sizeof(int*));
  for (int i = 0; i < h; i++) {
    m->grid[i] = malloc(w * sizeof(int));
  }
  m->w = w;
  m->h = h;
  m->openList = NULL;
  m->closedList = NULL;
  return m;
}

void addNode(Map* m, int x, int y) {
  Node* newNode = malloc(sizeof(Node));
  newNode->x = x;
  newNode->y = y;
  newNode->next = NULL;
  m->openList = newNode;
}

void findPath(Map* m, int x, int y) {
  addNode(m, x, y);
  while (m->openList) {
    Node* current = m->openList;
    m->openList = current->next;
    if (current->x == x && current->y == y) {
      return;
    }
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        if (current->x + dx >= 0 && current->x + dx < m->w && current->y + dy >= 0 && current->y + dy < m->h && m->grid[current->y + dy][current->x + dx] != 1) {
          addNode(m, current->x + dx, current->y + dy);
        }
      }
    }
  }
  return;
}

int main() {
  Map* m = createMap(5, 5);
  m->grid[2][2] = 1;
  m->grid[2][3] = 1;
  m->grid[3][2] = 1;
  m->grid[3][3] = 1;
  findPath(m, 0, 0);
  return 0;
}