//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void createMaze(Node** head) {
  *head = NULL;
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      Node* newNode = (Node*)malloc(sizeof(Node));
      newNode->x = i;
      newNode->y = j;
      newNode->next = NULL;
      if (*head == NULL) {
        *head = newNode;
      } else {
        (*head)->next = newNode;
        *head = newNode;
      }
    }
  }
}

void findRoute(Node* head, int x, int y) {
  if (head == NULL) {
    return;
  }
  if (head->x == x && head->y == y) {
    printf("Path found!\n");
    return;
  }

  findRoute(head->next, x, y);
  if (head->x - 1 == x && head->y == y) {
    printf("Move left\n");
  } else if (head->x + 1 == x && head->y == y) {
    printf("Move right\n");
  } else if (head->x == x && head->y - 1 == y) {
    printf("Move down\n");
  } else if (head->x == x && head->y + 1 == y) {
    printf("Move up\n");
  }
}

int main() {
  Node* head = NULL;
  createMaze(&head);
  findRoute(head, 5, 5);

  return 0;
}