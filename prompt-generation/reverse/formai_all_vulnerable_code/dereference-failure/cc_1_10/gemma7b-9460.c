//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void generateMaze(Node* head, int x, int y) {
  if (x >= MAZE_WIDTH || y >= MAZE_HEIGHT) {
    return;
  }

  if (head == NULL) {
    head = malloc(sizeof(Node));
    head->x = x;
    head->y = y;
    head->next = NULL;
  }

  int rand_dir = rand() % 4;

  switch (rand_dir) {
    case 0:
      generateMaze(head, x - 1, y);
      break;
    case 1:
      generateMaze(head, x, y - 1);
      break;
    case 2:
      generateMaze(head, x + 1, y);
      break;
    case 3:
      generateMaze(head, x, y + 1);
      break;
  }

  return;
}

int main() {
  srand(time(NULL));

  Node* head = NULL;
  generateMaze(head, 0, 0);

  // Traverse the maze and print the nodes
  for (Node* node = head; node; node = node->next) {
    printf("(%d, %d)\n", node->x, node->y);
  }

  return 0;
}