//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  struct Node* next;
  int data;
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
      }
      previous = current;
      current->next = NULL;
      previous->data = count;
      count = 1;
    }
  }

  if (previous) {
    previous->next = NULL;
  }
}

int main() {
  Node* head = malloc(sizeof(Node));
  head->data = 1;

  head->next = malloc(sizeof(Node));
  head->next->data = 1;

  head->next->next = malloc(sizeof(Node));
  head->next->next->data = 2;

  head->next->next->next = malloc(sizeof(Node));
  head->next->next->next->data = 2;

  compress(head);

  Node* compressed = head;
  while (compressed) {
    printf("%d ", compressed->data);
    compressed = compressed->next;
  }

  return 0;
}