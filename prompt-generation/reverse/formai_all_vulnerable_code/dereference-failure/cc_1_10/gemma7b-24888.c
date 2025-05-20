//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 10

typedef struct Node {
  int digit;
  struct Node* next;
} Node;

void insertNode(Node** head, int digit) {
  Node* newNode = malloc(sizeof(Node));
  newNode->digit = digit;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

int convertBinary(Node* head) {
  int result = 0;
  int i = 0;

  while (head) {
    int digit = head->digit;
    int power = pow(2, i);
    int contribution = digit * power;
    result += contribution;
    head = head->next;
    i++;
  }

  return result;
}

int main() {
  Node* head = NULL;
  insertNode(&head, 1);
  insertNode(&head, 0);
  insertNode(&head, 1);

  int decimal = convertBinary(head);

  printf("Decimal: %d", decimal);

  return 0;
}