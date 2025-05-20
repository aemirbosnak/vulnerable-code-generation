//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void insertNode(Node** head, int x, int y) {
  Node* newNode = malloc(sizeof(Node));
  newNode->x = x;
  newNode->y = y;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

int findPath(Node* head, int x, int y) {
  if (head == NULL) {
    return 0;
  }

  if (head->x == x && head->y == y) {
    return 1;
  }

  int found = findPath(head->next, x, y);

  if (found) {
    return 1;
  }

  return 0;
}

int main() {
  Node* head = NULL;
  insertNode(&head, 0, 0);
  insertNode(&head, 1, 0);
  insertNode(&head, 2, 0);
  insertNode(&head, 2, 1);
  insertNode(&head, 2, 2);

  if (findPath(head, 2, 2) == 1) {
    printf("Path found!");
  } else {
    printf("Path not found!");
  }

  return 0;
}