//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: future-proof
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

typedef struct Node {
  struct Node* up;
  struct Node* down;
  struct Node* right;
  struct Node* left;
  int x;
  int y;
} Node;

Node* createNode(int x, int y) {
  Node* node = malloc(sizeof(struct Node));
  node->up = NULL;
  node->down = NULL;
  node->right = NULL;
  node->left = NULL;
  node->x = x;
  node->y = y;
  return node;
}

void generateMaze(Node* node) {
  srand(time(NULL));
  int chance = rand() % 2;
  if (chance == 0) {
    node->up = createNode(node->x, node->y - 1);
  }
  chance = rand() % 2;
  if (chance == 0) {
    node->down = createNode(node->x, node->y + 1);
  }
  chance = rand() % 2;
  if (chance == 0) {
    node->right = createNode(node->x + 1, node->y);
  }
  chance = rand() % 2;
  if (chance == 0) {
    node->left = createNode(node->x - 1, node->y);
  }
}

int main() {
  Node* start = createNode(0, 0);
  generateMaze(start);
  return 0;
}