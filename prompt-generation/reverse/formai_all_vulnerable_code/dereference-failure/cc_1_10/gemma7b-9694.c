//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void findRoute(Node* head, int target) {
  printf("Route found: ");

  while (head) {
    if (head->data == target) {
      printf("%d ", head->data);
      return;
    } else if (head->data < target) {
      printf("%d ", head->data);
      findRoute(head->next, target);
    }
  }

  printf("Target not found");
}

int main() {
  Node* head = NULL;
  insertAtTail(&head, 10);
  insertAtTail(&head, 20);
  insertAtTail(&head, 30);
  insertAtTail(&head, 40);
  insertAtTail(&head, 50);

  findRoute(head, 40);

  return 0;
}