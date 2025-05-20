//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

int main() {
  char input[MAX_BUFFER_SIZE];
  printf("Enter text: ");
  fgets(input, MAX_BUFFER_SIZE, stdin);

  Node* head = NULL;
  Node* tail = NULL;
  for (int i = 0; input[i] != '\0'; i++) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = input[i];
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  int compressedSize = 0;
  tail = head;
  while (tail) {
    int characterCount = 0;
    for (Node* current = head; current && current->data == tail->data; current = current->next) {
      characterCount++;
    }

    if (characterCount > 1) {
      compressedSize++;
      printf("%c: %d ", tail->data, characterCount);
    } else {
      compressedSize++;
      printf("%c ", tail->data);
    }

    tail = tail->next;
  }

  printf("\nTotal compressed size: %d", compressedSize);

  return 0;
}