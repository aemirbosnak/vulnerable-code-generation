//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: modular
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
  Node* tail = NULL;
  int i = 0;

  for (; str[i] != '\0'; i++) {
    if (head == NULL) {
      head = tail = malloc(sizeof(Node));
      tail->data = str[i];
      tail->next = NULL;
    } else if (tail->data == str[i]) {
      tail->next = malloc(sizeof(Node));
      tail = tail->next;
      tail->data = str[i];
      tail->next = NULL;
    } else {
      tail = malloc(sizeof(Node));
      tail->data = str[i];
      tail->next = NULL;
      head = tail;
    }
  }

  char compressed_str[MAX_BUFFER_SIZE];
  int compressed_size = 0;

  for (tail = head; tail; tail = tail->next) {
    compressed_str[compressed_size++] = tail->data;
  }

  printf("Compressed string: %s\n", compressed_str);
  printf("Compressed size: %d\n", compressed_size);
}

int main() {
  char str[] = "aabbbbcccc";
  compress(str);

  return 0;
}