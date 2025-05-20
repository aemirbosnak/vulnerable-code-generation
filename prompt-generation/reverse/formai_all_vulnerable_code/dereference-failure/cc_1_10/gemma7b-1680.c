//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insert(Node** head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->next = newNode);
    *head = newNode;
  }
}

void traverse(Node* head) {
  while (head) {
    printf("%d ", head->data);
    head = head->next;
  }
}

void compress(char* str) {
  Node* head = NULL;
  for (int i = 0; str[i] != '\0'; i++) {
    insert(&head, str[i]);
  }

  char* compressedStr = malloc(MAX);
  int i = 0;
  traverse(head);
  for (Node* node = head; node; node = node->next) {
    compressedStr[i++] = node->data;
  }

  printf("Compressed string: %s\n", compressedStr);
  free(compressedStr);
  free(head);
}

int main() {
  char str[] = "abcddd";
  compress(str);

  return 0;
}