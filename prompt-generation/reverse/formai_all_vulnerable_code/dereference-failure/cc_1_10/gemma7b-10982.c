//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGIT 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insertNode(Node* head, int data) {
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

void convertBinary(Node* head) {
  int i = 0;
  int number = 0;
  int digit = MAX_DIGIT - 1;

  while (head) {
    int digitValue = head->data;
    int power = pow(2, i);
    number += digitValue * power;
    i++;
    head = head->next;
  }

  printf("%d", number);
}

int main() {
  Node* head = NULL;
  insertNode(head, 1);
  insertNode(head, 0);
  insertNode(head, 1);
  insertNode(head, 0);

  convertBinary(head);

  return 0;
}