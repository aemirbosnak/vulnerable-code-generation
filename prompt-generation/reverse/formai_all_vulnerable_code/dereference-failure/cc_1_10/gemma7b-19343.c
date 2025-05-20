//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
  char data;
  struct Node* next;
} Node;

struct Node* insertAtTail(struct Node* head, char data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

struct Node* search(struct Node* head, char data) {
  struct Node* current = head;

  while (current) {
    if (current->data == data) {
      return current;
    }

    current = current->next;
  }

  return NULL;
}

int main() {
  struct Node* head = NULL;

  insertAtTail(head, 'a');
  insertAtTail(head, 'b');
  insertAtTail(head, 'c');
  insertAtTail(head, 'd');
  insertAtTail(head, 'e');

  struct Node* result = search(head, 'c');

  if (result) {
    printf("Node found: %c\n", result->data);
  } else {
    printf("Node not found\n");
  }

  return 0;
}