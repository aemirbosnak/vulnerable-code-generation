//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void initialize(Node** head) {
  *head = NULL;
}

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

void findPath(Node* head, int x, int y) {
  if (head == NULL) {
    return;
  }

  if (head->x == x && head->y == y) {
    printf("Path found!\n");
    return;
  }

  findPath(head->next, x, y);

  if (head->x - 1 >= 0) {
    insert(head, head->x - 1, head->y);
  }

  if (head->y - 1 >= 0) {
    insert(head, head->x, head->y - 1);
  }

  if (head->x + 1 < MAX_SIZE) {
    insert(head, head->x + 1, head->y);
  }

  if (head->y + 1 < MAX_SIZE) {
    insert(head, head->x, head->y + 1);
  }
}

int main() {
  Node* head = NULL;
  initialize(&head);

  insert(head, 0, 0);
  insert(head, 1, 0);
  insert(head, 2, 0);
  insert(head, 3, 0);
  insert(head, 4, 0);
  insert(head, 5, 0);

  insert(head, 0, 1);
  insert(head, 1, 1);
  insert(head, 2, 1);
  insert(head, 3, 1);
  insert(head, 4, 1);

  insert(head, 0, 2);
  insert(head, 1, 2);
  insert(head, 2, 2);
  insert(head, 3, 2);
  insert(head, 4, 2);

  findPath(head, 4, 2);

  return 0;
}