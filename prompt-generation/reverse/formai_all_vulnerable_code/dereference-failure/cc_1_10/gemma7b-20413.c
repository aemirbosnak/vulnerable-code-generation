//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  int data;
  struct Node* next;
};

typedef struct Node Node;

void insertAtTail(Node** head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void traverseList(Node* head) {
  while (head) {
    printf("%d ", head->data);
    head = head->next;
  }
}

int main() {
  Node* head = NULL;

  // Convert binary number 1010 to decimal
  insertAtTail(&head, 1);
  insertAtTail(&head, 0);
  insertAtTail(&head, 1);
  insertAtTail(&head, 0);

  traverseList(head);

  printf("\nDecimal: ");

  // Convert decimal number 12 to binary
  insertAtTail(&head, 1);
  insertAtTail(&head, 2);

  traverseList(head);

  printf("\nBinary: ");

  return 0;
}