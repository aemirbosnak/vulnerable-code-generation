//Gemma-7B DATASET v1.0 Category: Memory management ; Style: sophisticated
#include <stdlib.h>

typedef struct Node {
  struct Node* next;
  void* data;
} Node;

#define MAX_SIZE 10

Node* head = NULL;
Node* tail = NULL;

void addToTail(void* data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;

  if (head == NULL) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

void freeNode(void* data) {
  Node* temp = head;
  Node* prev = NULL;

  while (temp) {
    if (temp->data == data) {
      if (prev) {
        prev->next = temp->next;
      } else {
        head = temp->next;
      }
      free(temp);
      return;
    }
    prev = temp;
    temp = temp->next;
  }

  return;
}

int main() {
  addToTail(10);
  addToTail(20);
  addToTail(30);
  addToTail(40);

  freeNode(20);

  return 0;
}