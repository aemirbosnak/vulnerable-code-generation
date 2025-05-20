//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
  int x;
  int y;
  struct Node* next;
} Node;

void createMaze(Node** head) {
  *head = malloc(sizeof(Node));
  (*head)->x = 0;
  (*head)->y = 0;
  (*head)->next = NULL;

  for (int x = 0; x < MAX_SIZE; x++) {
    for (int y = 0; y < MAX_SIZE; y++) {
      Node* newNode = malloc(sizeof(Node));
      newNode->x = x;
      newNode->y = y;
      newNode->next = NULL;

      ((*head)->next) = newNode;
      head = &newNode;
    }
  }
}

void findRoute(Node* head, int targetX, int targetY) {
  if (head == NULL) {
    return;
  }

  if (head->x == targetX && head->y == targetY) {
    printf("Path found!\n");
    return;
  }

  findRoute(head->next, targetX, targetY);

  if (head->x + 1 == targetX && head->y == targetY) {
    printf("Moving right...\n");
  } else if (head->x - 1 == targetX && head->y == targetY) {
    printf("Moving left...\n");
  } else if (head->x == targetX && head->y + 1 == targetY) {
    printf("Moving forward...\n");
  } else if (head->x == targetX && head->y - 1 == targetY) {
    printf("Moving backward...\n");
  }
}

int main() {
  Node* head = NULL;
  createMaze(&head);

  findRoute(head, 5, 5);

  return 0;
}