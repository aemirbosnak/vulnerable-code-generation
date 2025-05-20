//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: dynamic
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

typedef struct Node {
  struct Node* up;
  struct Node* right;
  struct Node* down;
  struct Node* left;
  int x;
  int y;
} Node;

Node* createNode(int x, int y) {
  struct Node* node = malloc(sizeof(struct Node));
  node->up = NULL;
  node->right = NULL;
  node->down = NULL;
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
    node->right = createNode(node->x + 1, node->y);
  }
  chance = rand() % 2;
  if (chance == 0) {
    node->down = createNode(node->x, node->y + 1);
  }
  chance = rand() % 2;
  if (chance == 0) {
    node->left = createNode(node->x - 1, node->y);
  }
}

int main() {
  Node* start = createNode(0, 0);
  generateMaze(start);

  // Print the maze
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if (start->up->x == x && start->up->y == y) {
        printf("%c", WALL_CHAR);
      } else if (start->right->x == x && start->right->y == y) {
        printf("%c", WALL_CHAR);
      } else if (start->down->x == x && start->down->y == y) {
        printf("%c", WALL_CHAR);
      } else if (start->left->x == x && start->left->y == y) {
        printf("%c", WALL_CHAR);
      } else {
        printf("%c", EMPTY_CHAR);
      }
    }
    printf("\n");
  }

  return 0;
}