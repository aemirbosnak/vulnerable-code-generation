//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void compress(Node* head) {
  Node* current = head;
  int count = 0;
  int previous = current->data;
  Node* previousNode = NULL;

  while (current) {
    if (previous == current->data) {
      count++;
    } else {
      if (previousNode) {
        previousNode->next = malloc(sizeof(Node));
        previousNode->next->data = count;
        previousNode = previousNode->next;
      }
      previous = current->data;
      count = 1;
    }
    current = current->next;
  }

  if (previousNode) {
    previousNode->next = malloc(sizeof(Node));
    previousNode->next->data = count;
  }
}

int main() {
  Node* head = malloc(sizeof(Node));
  head->data = 1;

  Node* second = malloc(sizeof(Node));
  second->data = 2;

  Node* third = malloc(sizeof(Node));
  third->data = 2;

  Node* fourth = malloc(sizeof(Node));
  fourth->data = 3;

  head->next = second;
  second->next = third;
  third->next = fourth;

  compress(head);

  Node* compressedHead = head;
  while (compressedHead) {
    printf("%d ", compressedHead->data);
    compressedHead = compressedHead->next;
  }

  return 0;
}