//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* insertAtTail(struct Node* head, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

struct Node* deleteAtTail(struct Node* head) {
  struct Node* prev = NULL;
  struct Node* current = head;

  if (head == NULL) {
    return NULL;
  }

  while (current->next) {
    prev = current;
    current = current->next;
  }

  if (prev) {
    prev->next = NULL;
  } else {
    head = NULL;
  }

  return head;
}

int main() {
  struct Node* head = NULL;

  insertAtTail(head, 10);
  insertAtTail(head, 20);
  insertAtTail(head, 30);
  insertAtTail(head, 40);

  deleteAtTail(head);

  struct Node* current = head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");

  return 0;
}