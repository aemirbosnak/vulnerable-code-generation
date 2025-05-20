//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: rigorous
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
  char previous = '\0';
  int count = 1;
  char buffer[MAX_BUFFER_SIZE];

  while (current) {
    if (previous == current->data) {
      count++;
    } else {
      if (previous) {
        buffer[count - 1] = previous;
        buffer[count] = count;
      }
      previous = current->data;
      count = 1;
    }

    current = current->next;
  }

  if (previous) {
    buffer[count - 1] = previous;
    buffer[count] = count;
  }

  printf("Compressed data: ");
  for (int i = 0; buffer[i] != '\0'; i++) {
    printf("%c ", buffer[i]);
  }
  printf("\n");
}

int main() {
  Node* head = NULL;

  // Create a sample linked list
  head = malloc(sizeof(Node));
  head->data = 'a';
  head->next = malloc(sizeof(Node));
  head->next->data = 'a';
  head->next->next = malloc(sizeof(Node));
  head->next->next->data = 'b';
  head->next->next->next = malloc(sizeof(Node));
  head->next->next->next->data = 'b';
  head->next->next->next->next = NULL;

  compress(head);

  return 0;
}