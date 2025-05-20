//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ada Lovelace
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

typedef struct Node {
  struct Node* north;
  struct Node* south;
  struct Node* east;
  struct Node* west;
  int x;
  int y;
} Node;

Node* createNode(int x, int y) {
  Node* node = malloc(sizeof(Node));
  node->north = NULL;
  node->south = NULL;
  node->east = NULL;
  node->west = NULL;
  node->x = x;
  node->y = y;
  return node;
}

void generateMaze(Node* start) {
  srand(time(NULL));
  for (int i = 0; i < MAZE_WIDTH * MAZE_HEIGHT; i++) {
    Node* current = start;
    int direction = rand() % 4;
    switch (direction) {
      case 0:
        current->south = createNode(current->x, current->y + 1);
        break;
      case 1:
        current->north = createNode(current->x, current->y - 1);
        break;
      case 2:
        current->east = createNode(current->x + 1, current->y);
        break;
      case 3:
        current->west = createNode(current->x - 1, current->y);
        break;
    }
  }
}

int main() {
  Node* start = createNode(0, 0);
  generateMaze(start);
  return 0;
}