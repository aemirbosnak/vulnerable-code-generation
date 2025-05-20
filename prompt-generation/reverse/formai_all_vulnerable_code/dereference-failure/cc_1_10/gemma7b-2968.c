//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: futuristic
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
  int count = 0;
  char previousChar = '\0';

  while (current) {
    if (previousChar == current->data) {
      count++;
    } else {
      if (previous) {
        previous->next = malloc(sizeof(Node));
        previous->next->data = count + 'a';
        previous->next->next = NULL;
      }
      previousChar = current->data;
      count = 1;
    }
    current = current->next;
  }

  if (previous) {
    previous->next = malloc(sizeof(Node));
    previous->next->data = count + 'a';
    previous->next->next = NULL;
  }
}

int main() {
  Node* head = malloc(sizeof(Node));
  head->data = 'a';

  Node* second = malloc(sizeof(Node));
  second->data = 'a';

  Node* third = malloc(sizeof(Node));
  third->data = 'b';

  head->next = second;
  second->next = third;

  compress(head);

  return 0;
}