//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char data;
  struct Node* next;
} Node;

void traverse(Node* node) {
  while (node) {
    printf("%c ", node->data);
    node = node->next;
  }
}

void compress(char* str) {
  Node* head = NULL;
  for (int i = 0; str[i] != '\0'; i++) {
    Node* node = malloc(sizeof(Node));
    node->data = str[i];
    node->next = head;
    head = node;
  }

  traverse(head);
  printf("\n");

  int count = 0;
  for (Node* node = head; node; node = node->next) {
    if (node->next) {
      if (node->data == node->next->data) {
        count++;
      } else {
        printf("%c ", node->data);
        if (count) {
          printf("%d ", count);
        }
        count = 0;
      }
    } else {
      printf("%c ", node->data);
      if (count) {
        printf("%d ", count);
      }
    }
  }

  printf("\n");
}

int main() {
  char str[] = "aabbbbcccc";
  compress(str);

  return 0;
}