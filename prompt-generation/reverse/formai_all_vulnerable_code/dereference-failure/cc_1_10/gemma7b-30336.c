//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void traverse(Node* head) {
  while (head) {
    printf("%d ", head->data);
    head = head->next;
  }
}

int main() {
  Node* head = NULL;

  char input[1024];
  printf("Enter a binary number: ");
  scanf("%s", input);

  // Convert input to linked list
  for (int i = 0; input[i] != '\0'; i++) {
    int digit = input[i] - '0';
    insertAtTail(head, digit);
  }

  // Traverse the linked list
  traverse(head);

  printf("\n");

  return 0;
}