//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* InsertAtTail(Node* head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void Search(Node* head, int target) {
  Node* current = head;

  while (current) {
    if (current->data == target) {
      printf("Target found!\n");
      return;
    } else if (current->data < target) {
      current = current->next;
    } else {
      printf("Target not found.\n");
      return;
    }
  }

  printf("Target not found.\n");
}

int main() {
  Node* head = NULL;

  InsertAtTail(head, 10);
  InsertAtTail(head, 20);
  InsertAtTail(head, 30);
  InsertAtTail(head, 40);
  InsertAtTail(head, 50);

  Search(head, 40);

  return 0;
}