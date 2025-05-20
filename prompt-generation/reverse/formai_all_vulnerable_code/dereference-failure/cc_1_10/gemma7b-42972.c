//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node* next;
  int data;
} Node;

void insert(Node* head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  head = newNode;
}

void findRoute(Node* head) {
  int current = head->data;
  int target = 5;

  while (current != target) {
    switch (current) {
      case 1:
        current = 2;
        break;
      case 2:
        current = 3;
        break;
      case 3:
        current = 4;
        break;
      case 4:
        current = 5;
        break;
      default:
        current = current - 1;
        break;
    }
  }

  printf("The route is: %d, %d, %d, %d, %d", head->data, current, target, current - 1, target);
}

int main() {
  Node* head = NULL;
  insert(head, 1);
  insert(head, 2);
  insert(head, 3);
  insert(head, 4);
  insert(head, 5);

  findRoute(head);

  return 0;
}