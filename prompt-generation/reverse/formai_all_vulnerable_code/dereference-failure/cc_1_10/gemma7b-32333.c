//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

void compress(char* str) {
  Node* head = NULL;
  char* ptr = str;
  int count = 1;

  while (*ptr) {
    char current = *ptr;
    ptr++;

    if (head == NULL || current != head->data) {
      head = malloc(sizeof(Node));
      head->data = current;
      head->next = NULL;
    } else {
      count++;
    }

    if (count == MAX_BUFFER_SIZE) {
      Node* tail = head;
      while (tail->next) {
        tail = tail->next;
      }
      tail->next = malloc(sizeof(Node));
      tail = tail->next;
      tail->data = current;
      tail->next = NULL;
      count = 1;
    }
  }

  int size = 0;
  for (Node* node = head; node; node = node->next) {
    size++;
  }

  printf("Compressed size: %d\n", size);

  // Print compressed data
  for (Node* node = head; node; node = node->next) {
    printf("%c ", node->data);
  }

  printf("\n");
}

int main() {
  char str[] = "aabbbbcccccaa";
  compress(str);

  return 0;
}