//Gemma-7B DATASET v1.0 Category: Pathfinding algorithms ; Style: detailed
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

int search(Node* head, int x, int y) {
  while (head) {
    if (head->x == x && head->y == y) {
      return 1;
    }
    head = head->next;
  }

  return 0;
}

int main() {
  Node* head = NULL;
  initialize(&head);

  insert(head, 0, 0);
  insert(head, 1, 0);
  insert(head, 2, 0);
  insert(head, 0, 1);
  insert(head, 1, 1);
  insert(head, 2, 1);

  if (search(head, 2, 1) == 1) {
    printf("Found!\n");
  } else {
    printf("Not found.\n");
  }

  return 0;
}