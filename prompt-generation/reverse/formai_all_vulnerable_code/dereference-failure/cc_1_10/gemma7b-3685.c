//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
  int x;
  int y;
  struct Node* next;
} Node;

struct Node* createNode(int x, int y) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->x = x;
  node->y = y;
  node->next = NULL;
  return node;
}

void insertAfter(struct Node* node, struct Node* newNode) {
  newNode->next = node->next;
  node->next = newNode;
}

void findMazeRoute(char** maze, int x, int y) {
  struct Node* head = createNode(x, y);
  struct Node* current = head;
  struct Node* next = NULL;

  maze[x][y] = 'S';

  while (current) {
    next = NULL;
    if (x - 1 >= 0 && maze[x - 1][y] != '#') {
      next = createNode(x - 1, y);
      insertAfter(current, next);
    }
    if (x + 1 < MAX_SIZE && maze[x + 1][y] != '#') {
      next = createNode(x + 1, y);
      insertAfter(current, next);
    }
    if (y - 1 >= 0 && maze[x][y - 1] != '#') {
      next = createNode(x, y - 1);
      insertAfter(current, next);
    }
    if (y + 1 < MAX_SIZE && maze[x][y + 1] != '#') {
      next = createNode(x, y + 1);
      insertAfter(current, next);
    }

    current = current->next;
  }

  free(head);
}

int main() {
  char** maze = (char**)malloc(MAX_SIZE * sizeof(char*));
  for (int i = 0; i < MAX_SIZE; i++) {
    maze[i] = (char*)malloc(MAX_SIZE * sizeof(char));
  }

  // Create a sample maze
  maze[0][0] = 'S';
  maze[0][1] = '#';
  maze[1][0] = '#';
  maze[1][1] = '#';
  maze[1][2] = 'T';

  findMazeRoute(maze, 0, 0);

  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      printf("%c ", maze[i][j]);
    }
    printf("\n");
  }

  return 0;
}