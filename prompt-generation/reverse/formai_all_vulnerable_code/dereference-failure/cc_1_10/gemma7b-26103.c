//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void createMaze(Node** head) {
  *head = malloc(sizeof(Node));
  (*head)->x = 0;
  (*head)->y = 0;
  (*head)->next = NULL;

  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      Node* newNode = malloc(sizeof(Node));
      newNode->x = i;
      newNode->y = j;
      newNode->next = NULL;

      ((*head)->next = newNode)->next = NULL;
      head = &newNode;
    }
  }
}

void findRoute(Node* head, int x, int y) {
  if (head->x == x && head->y == y) {
    printf("Path found!\n");
  } else {
    findRoute(head->next, x, y);

    if (head->x - 1 >= 0) {
      findRoute(head->next, head->x - 1, head->y);
    }
    if (head->y - 1 >= 0) {
      findRoute(head->next, head->x, head->y - 1);
    }
    if (head->x + 1 < MAX_SIZE) {
      findRoute(head->next, head->x + 1, head->y);
    }
    if (head->y + 1 < MAX_SIZE) {
      findRoute(head->next, head->x, head->y + 1);
    }
  }
}

int main() {
  Node* head = NULL;
  createMaze(&head);

  findRoute(head, 5, 5);

  return 0;
}