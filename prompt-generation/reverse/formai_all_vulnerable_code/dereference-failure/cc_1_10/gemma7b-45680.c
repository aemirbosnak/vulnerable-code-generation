//Gemma-7B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void insert(Node** head, int x, int y) {
  Node* newNode = malloc(sizeof(struct Node));
  newNode->x = x;
  newNode->y = y;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

int distance(int x1, int y1, int x2, int y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}

int main() {
  Node* head = NULL;
  insert(&head, 0, 0);
  insert(&head, 1, 1);
  insert(&head, 2, 2);
  insert(&head, 3, 3);

  int targetX = 2;
  int targetY = 2;

  Node* current = head;
  while (current) {
    int currentX = current->x;
    int currentY = current->y;

    if (distance(currentX, currentY, targetX, targetY) == 3) {
      printf("Path found!\n");
      return 0;
    }

    current = current->next;
  }

  printf("No path found.\n");
  return 1;
}