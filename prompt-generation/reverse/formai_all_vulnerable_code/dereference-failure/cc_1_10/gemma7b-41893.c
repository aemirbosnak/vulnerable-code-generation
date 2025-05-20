//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void createMaze(Node* head, int size) {
  head = (Node*)malloc(size * sizeof(Node));
  for (int i = 0; i < size; i++) {
    head[i].x = -1;
    head[i].y = -1;
    head[i].next = NULL;
  }
  return;
}

void solveMaze(Node* head) {
  head->x = 0;
  head->y = 0;
  head->next = NULL;

  while (head->next) {
    int dx = rand() % 2 - 1;
    int dy = rand() % 2 - 1;

    if (dx == 0 && dy == 0) {
      break;
    }

    if (head->x + dx < 0 || head->x + dx >= MAX_SIZE - 1) {
      dx = -dx;
    }
    if (head->y + dy < 0 || head->y + dy >= MAX_SIZE - 1) {
      dy = -dy;
    }

    head->next = (Node*)malloc(sizeof(Node));
    head->next->x = head->x + dx;
    head->next->y = head->y + dy;
    head->next->next = NULL;
    head = head->next;
  }

  return;
}

int main() {
  Node* head = NULL;
  createMaze(head, MAX_SIZE);
  solveMaze(head);

  return 0;
}