//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

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

int convertBinary(char* binary) {
  int decimal = 0;
  int i = 0;
  Node* head = NULL;

  for (i = strlen(binary) - 1; i >= 0; i--) {
    int digit = binary[i] - '0';
    insertAtTail(head, digit);
  }

  while (head) {
    decimal = decimal * 2 + head->data;
    head = head->next;
  }

  return decimal;
}

int main() {
  char* binary = "1010";
  int decimal = convertBinary(binary);

  printf("Decimal: %d\n", decimal);

  return 0;
}