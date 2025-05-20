//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

int main() {
  Node* head = NULL;
  head = insertAtTail(head, 1);
  head = insertAtTail(head, 2);
  head = insertAtTail(head, 3);
  head = insertAtTail(head, 4);
  head = insertAtTail(head, 5);

  int size = 0;
  for (Node* current = head; current; current = current->next) {
    size++;
  }

  printf("Original list size: %d\n", size);

  // Compression algorithm
  Node* compressedHead = NULL;
  Node* previous = NULL;
  int compressedSize = 0;

  for (Node* current = head; current; current = current->next) {
    if (previous) {
      if (current->data == previous->data) {
        continue;
      }
    }

    insertAtTail(compressedHead, current->data);
    previous = current;
    compressedSize++;
  }

  printf("Compressed list size: %d\n", compressedSize);

  return 0;
}