//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

void insertAtTail(struct Node** head, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

struct Node* findNode(struct Node* head, int data) {
  struct Node* current = head;

  while (current) {
    if (current->data == data) {
      return current;
    } else {
      current = current->next;
    }
  }

  return NULL;
}

int main() {
  struct Node* head = NULL;

  insertAtTail(&head, 10);
  insertAtTail(&head, 20);
  insertAtTail(&head, 30);

  struct Node* foundNode = findNode(head, 20);

  if (foundNode) {
    printf("Found node with data: %d\n", foundNode->data);
  } else {
    printf("Node not found\n");
  }

  return 0;
}