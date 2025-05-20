//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: interoperable
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
  char currentChar = str[0];
  int count = 1;

  for (i = 1; str[i] != '\0'; i++) {
    if (str[i] == currentChar) {
      count++;
    } else {
      if (head == NULL) {
        head = tail = malloc(sizeof(Node));
        head->data = currentChar;
        head->next = NULL;
      } else {
        tail->next = malloc(sizeof(Node));
        tail = tail->next;
        tail->data = currentChar;
        tail->next = NULL;
      }
      currentChar = str[i];
      count = 1;
    }
  }

  if (tail) {
    tail->next = NULL;
  }

  int compressedSize = 0;
  for (Node* node = head; node; node = node->next) {
    compressedSize++;
  }

  printf("Compressed size: %d\n", compressedSize);

  // Print the compressed string
  for (Node* node = head; node; node = node->next) {
    printf("%c", node->data);
  }

  printf("\n");
}

int main() {
  char str[] = "aabbbbcccccaa";
  compress(str);

  return 0;
}