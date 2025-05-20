//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10
#define MAX_PATH_LENGTH 20

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* createNode(int x, int y) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->next = NULL;
  return node;
}

void generateMaze(Node* head) {
  srand(time(NULL));
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      if (rand() % 2 == 0) {
        head->next = createNode(i, j);
        head = head->next;
      }
    }
  }
}

int main() {
  Node* head = createNode(0, 0);
  generateMaze(head);

  // Print the maze
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      if (head->x == i && head->y == j) {
        printf("O ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }

  return 0;
}