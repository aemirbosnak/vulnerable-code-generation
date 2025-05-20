//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: mind-bending
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

struct Node* deleteMiddleNode(struct Node* head, int position) {
  struct Node* slowPtr = head;
  struct Node* fastPtr = head;

  for (int i = 0; i < position; i++) {
    fastPtr = fastPtr->next->next;
  }

  if (fastPtr == NULL) {
    return NULL;
  }

  slowPtr = fastPtr->next;
  fastPtr->next = slowPtr->next;
  free(slowPtr);

  return head;
}

int main() {
  struct Node* head = NULL;
  insertAtTail(&head, 10);
  insertAtTail(&head, 20);
  insertAtTail(&head, 30);
  insertAtTail(&head, 40);
  insertAtTail(&head, 50);

  deleteMiddleNode(head, 2);

  struct Node* current = head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");

  return 0;
}