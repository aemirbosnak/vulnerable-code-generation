//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: standalone
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

  if (previous) {
    previous->next = NULL;
  }
}

int main() {
  Node* head = malloc(sizeof(Node));
  head->data = 'a';

  Node* second = malloc(sizeof(Node));
  second->data = 'a';

  Node* third = malloc(sizeof(Node));
  third->data = 'b';

  Node* fourth = malloc(sizeof(Node));
  fourth->data = 'a';

  head->next = second;
  second->next = third;
  third->next = fourth;

  compress(head);

  return 0;
}