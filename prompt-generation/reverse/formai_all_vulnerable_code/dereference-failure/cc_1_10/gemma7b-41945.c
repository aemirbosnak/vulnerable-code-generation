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
    struct Node* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  return head;
}

struct Node* deleteAtTail(struct Node* head) {
  if (head == NULL) {
    return NULL;
  }

  struct Node* temp = head;
  struct Node* prev = NULL;

  while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }

  if (prev != NULL) {
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
  insertAtTail(head, 50);

  deleteAtTail(head);
  deleteAtTail(head);

  struct Node* temp = head;
  while (temp) {
    printf("%d ", temp->data);
    temp = temp->next;
  }

  return 0;
}