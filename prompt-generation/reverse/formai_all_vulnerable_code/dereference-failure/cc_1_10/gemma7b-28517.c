//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  int data;
  struct Node* next;
} Node;

int compress(Node* head) {
  int count = 0;
  Node* current = head;
  while (current) {
    int runs = 1;
    Node* previous = NULL;
    while (current->next && current->data == previous->data) {
      runs++;
      previous = current;
      current = current->next;
    }
    if (runs > 1) {
      count++;
      previous->next = malloc(sizeof(Node));
      previous->next->data = runs;
      previous->next->next = current;
    } else {
      previous = current;
      current = current->next;
    }
  }
  return count;
}

int main() {
  Node* head = NULL;
  head = malloc(sizeof(Node));
  head->data = 1;
  head->next = malloc(sizeof(Node));
  head->next->data = 1;
  head->next->next = malloc(sizeof(Node));
  head->next->next->data = 2;
  head->next->next->next = malloc(sizeof(Node));
  head->next->next->next->data = 2;
  head->next->next->next->next = NULL;

  int count = compress(head);

  printf("Number of nodes reduced: %d\n", count);

  return 0;
}