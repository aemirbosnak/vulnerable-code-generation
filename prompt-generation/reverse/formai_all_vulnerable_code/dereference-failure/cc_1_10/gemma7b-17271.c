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
    struct Node* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  return head;
}

struct Node* insertAtHead(struct Node* head, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }

  return head;
}

int main() {
  struct Node* head = NULL;

  insertAtTail(head, 10);
  insertAtTail(head, 20);
  insertAtTail(head, 30);
  insertAtHead(head, 40);
  insertAtHead(head, 50);

  struct Node* temp = head;
  while (temp) {
    printf("%d ", temp->data);
    temp = temp->next;
  }

  return 0;
}