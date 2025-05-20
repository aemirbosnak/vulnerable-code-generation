//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insert(Node* head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
  head = newNode;
}

int main() {
  Node* head = NULL;
  insert(head, 1);
  insert(head, 2);
  insert(head, 3);
  insert(head, 4);
  insert(head, 5);

  int current = head->data;
  int target = 3;

  while (current != target) {
    switch (current) {
      case 1:
        current = head->next->data;
        break;
      case 2:
        current = head->next->next->data;
        break;
      case 3:
        current = head->next->next->next->data;
        break;
      case 4:
        current = head->next->next->next->next->data;
        break;
      case 5:
        current = head->next->next->next->next->next->data;
        break;
    }
  }

  printf("Current: %d, Target: %d\n", current, target);

  return 0;
}