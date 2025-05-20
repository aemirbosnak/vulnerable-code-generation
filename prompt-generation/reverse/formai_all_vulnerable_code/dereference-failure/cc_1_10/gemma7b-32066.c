//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void initializeMaze(Node* head) {
  for (int i = 0; i < MAX_SIZE; i++) {
    head->next = (Node*)malloc(sizeof(Node));
    head = head->next;
  }
  head->next = NULL;
}

void findRoute(Node* head) {
  char route[MAX_SIZE] = "";
  int currentPosition = 0;
  int targetPosition = MAX_SIZE - 1;
  route[currentPosition] = 'S';

  while (currentPosition != targetPosition) {
    int direction = rand() % 4;
    switch (direction) {
      case 0:
        route[++currentPosition] = 'N';
        break;
      case 1:
        route[++currentPosition] = 'E';
        break;
      case 2:
        route[++currentPosition] = 'S';
        break;
      case 3:
        route[++currentPosition] = 'W';
        break;
    }
  }

  printf("Route: %s\n", route);
}

int main() {
  Node* head = (Node*)malloc(sizeof(Node));
  initializeMaze(head);
  findRoute(head);

  return 0;
}