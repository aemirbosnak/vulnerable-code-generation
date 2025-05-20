//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  int value;
  struct Node* next;
} Node;

int compress(Node* head) {
  Node* current = head;
  int count = 0;
  int previousValue = -1;
  int runLength = 1;

  while (current) {
    if (previousValue == current->value) {
      runLength++;
    } else {
      if (runLength > 1) {
        printf("%c", previousValue - 1);
        printf("%c", runLength - 1);
      }
      previousValue = current->value;
      runLength = 1;
    }
    current = current->next;
  }

  if (runLength > 1) {
    printf("%c", previousValue - 1);
    printf("%c", runLength - 1);
  }

  return 0;
}

int main() {
  Node* head = NULL;
  head = malloc(sizeof(Node));
  head->value = 10;
  head->next = malloc(sizeof(Node));
  head->next->value = 10;
  head->next->next = malloc(sizeof(Node));
  head->next->next->value = 12;
  head->next->next->next = malloc(sizeof(Node));
  head->next->next->next->value = 12;

  compress(head);

  return 0;
}