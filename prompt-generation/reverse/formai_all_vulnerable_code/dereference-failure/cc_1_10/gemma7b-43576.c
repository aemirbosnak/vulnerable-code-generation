//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insert(Node** head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void findPath(Node* head, int target) {
  if (head == NULL) {
    return;
  }

  if (head->data == target) {
    printf("Path found!\n");
    return;
  }

  findPath(head->next, target);

  if (head->next != NULL) {
    findPath(head->next, target);
  }

  return;
}

int main() {
  Node* head = NULL;

  insert(&head, 1);
  insert(&head, 2);
  insert(&head, 3);
  insert(&head, 4);
  insert(&head, 5);

  findPath(head, 4);

  return 0;
}