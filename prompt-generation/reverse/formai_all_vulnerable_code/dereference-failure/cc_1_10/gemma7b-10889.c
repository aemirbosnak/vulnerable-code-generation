//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void insert(Node** head, int x, int y) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->x = x;
  newNode->y = y;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void findPath(Node* head) {
  int x, y, i, j;
  printf("Path: ");

  for (x = 0; x < MAX; x++) {
    for (y = 0; y < MAX; y++) {
      if (head->x == x && head->y == y) {
        printf("(%d, %d) ", x, y);
      }
    }
  }

  printf("\n");
}

int main() {
  Node* head = NULL;

  insert(&head, 2, 3);
  insert(&head, 3, 4);
  insert(&head, 4, 5);
  insert(&head, 5, 6);

  findPath(head);

  return 0;
}