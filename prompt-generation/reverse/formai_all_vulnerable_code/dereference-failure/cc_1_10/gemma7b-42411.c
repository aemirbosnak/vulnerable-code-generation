//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_WINDOW_SIZE 128

typedef struct Node {
  char data;
  struct Node* next;
} Node;

void compress(Node* head) {
  Node* current = head;
  int windowSize = MAX_WINDOW_SIZE;
  int count = 0;
  char previous = '\0';

  while (current) {
    if (previous == current->data) {
      count++;
    } else {
      if (count > 0) {
        printf("%c%d ", previous, count);
      }
      previous = current->data;
      count = 1;
    }

    if (count == windowSize) {
      windowSize *= 2;
    }
  }

  if (count > 0) {
    printf("%c%d ", previous, count);
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
  head->next->next->next->next = malloc(sizeof(Node));
  head->next->next->next->next->data = 'c';

  compress(head);

  return 0;
}