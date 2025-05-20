//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

Node* newNode(char data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

void compress(Node* head) {
  Node* current = head;
  Node* previous = NULL;
  int count = 1;
  char previousChar = current->data;

  while (current) {
    if (previousChar == current->data) {
      count++;
    } else {
      if (previous) {
        previous->next = newNode(count);
      }
      previousChar = current->data;
      count = 1;
    }

    current = current->next;
  }

  if (previous) {
    previous->next = newNode(count);
  }
}

int main() {
  char buffer[MAX_BUFFER_SIZE];
  printf("Enter a string: ");
  fgets(buffer, MAX_BUFFER_SIZE, stdin);

  Node* head = newNode(buffer[0]);
  for (int i = 1; buffer[i] != '\0'; i++) {
    newNode(buffer[i])->next = head;
    head = newNode(buffer[i])->next;
  }

  compress(head);

  printf("Compressed string: ");
  for (Node* current = head; current; current = current->next) {
    printf("%c ", current->data);
  }

  printf("\n");

  return 0;
}