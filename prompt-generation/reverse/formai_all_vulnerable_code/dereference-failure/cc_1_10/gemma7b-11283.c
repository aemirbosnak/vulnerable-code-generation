//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void dfs(Node* current, Node* goal) {
  if (current == NULL) {
    return;
  }

  if (current->x == goal->x && current->y == goal->y) {
    printf("Path found!\n");
    return;
  }

  dfs(current->next, goal);

  if (current->x - 1 >= 0) {
    Node* next = malloc(sizeof(Node));
    next->x = current->x - 1;
    next->y = current->y;
    next->next = current->next;
    current->next = next;
  }

  if (current->y - 1 >= 0) {
    Node* next = malloc(sizeof(Node));
    next->x = current->x;
    next->y = current->y - 1;
    next->next = current->next;
    current->next = next;
  }
}

int main() {
  Node* start = malloc(sizeof(Node));
  start->x = 0;
  start->y = 0;
  start->next = NULL;

  Node* goal = malloc(sizeof(Node));
  goal->x = 2;
  goal->y = 2;
  goal->next = NULL;

  dfs(start, goal);

  return 0;
}