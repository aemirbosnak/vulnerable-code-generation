//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* newNode(int data) {
  Node* node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

void compress(Node* head) {
  Node* current = head;
  Node* previous = NULL;
  int count = 1;
  while (current) {
    if (previous && current->data == previous->data) {
      count++;
    } else {
      if (previous) {
        previous->next = newNode(count);
      }
      previous = current;
      count = 1;
    }
    current = current->next;
  }
  if (previous) {
    previous->next = newNode(count);
  }
}

int main() {
  Node* head = newNode(1);
  head->next = newNode(1);
  head->next->next = newNode(2);
  head->next->next->next = newNode(2);
  head->next->next->next->next = newNode(3);
  head->next->next->next->next->next = newNode(3);

  compress(head);

  Node* current = head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }

  return 0;
}