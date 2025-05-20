//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: shape shifting
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

struct Node* deleteNode(struct Node* head, int data) {
  struct Node* prev = NULL;
  struct Node* current = head;

  while (current) {
    if (current->data == data) {
      if (prev) {
        prev->next = current->next;
      } else {
        head = current->next;
      }
      free(current);
      current = NULL;
    } else {
      prev = current;
      current = current->next;
    }
  }

  return head;
}

int main() {
  struct Node* head = NULL;

  insertAtTail(head, 10);
  insertAtTail(head, 20);
  insertAtTail(head, 30);

  deleteNode(head, 20);

  struct Node* current = head;

  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }

  return 0;
}