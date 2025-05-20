//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void compress(Node* head) {
  Node* current = head;
  Node* previous = NULL;
  int count = 1;

  while (current) {
    if (previous && current->data == previous->data) {
      count++;
    } else {
      if (previous) {
        previous->next = malloc(sizeof(Node));
        previous = previous->next;
        previous->data = current->data;
        previous->next = NULL;
      } else {
        previous = current;
      }
      count = 1;
    }
    current = current->next;
  }

  free(head);
  head = previous;
}

int main() {
  Node* head = malloc(sizeof(Node));
  head->data = 1;

  Node* second = malloc(sizeof(Node));
  second->data = 1;

  Node* third = malloc(sizeof(Node));
  third->data = 2;

  Node* fourth = malloc(sizeof(Node));
  fourth->data = 2;

  head->next = second;
  second->next = third;
  third->next = fourth;

  compress(head);

  return 0;
}