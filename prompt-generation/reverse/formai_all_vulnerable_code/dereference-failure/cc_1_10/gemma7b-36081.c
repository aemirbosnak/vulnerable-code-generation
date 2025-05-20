//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGIT 256

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insertAtTail(Node* head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
  head = newNode;
}

int convertDecimalToBinary(Node* head) {
  int binary = 0;
  int i = 0;
  int remainder;

  while (head) {
    remainder = head->data % 2;
    head->data /= 2;
    binary += remainder * pow(2, i);
    i++;
  }

  return binary;
}

int main() {
  Node* head = NULL;
  insertAtTail(head, 10);
  insertAtTail(head, 12);
  insertAtTail(head, 14);

  int binary = convertDecimalToBinary(head);

  printf("Binary: %d", binary);

  return 0;
}