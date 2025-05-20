//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data;
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
        printf("%c", previous->data);
        printf("%d", count);
      }
      previous = current;
      count = 1;
    }
    current = current->next;
  }

  if (previous) {
    printf("%c", previous->data);
    printf("%d", count);
  }
}

int main() {
  Node* head = NULL;

  // Create a linked list
  head = malloc(sizeof(Node));
  head->data = 'a';
  head->next = malloc(sizeof(Node));
  head->next->data = 'a';
  head->next->next = malloc(sizeof(Node));
  head->next->next->data = 'b';
  head->next->next->next = malloc(sizeof(Node));
  head->next->next->next->data = 'b';

  // Compress the list
  compress(head);

  return 0;
}