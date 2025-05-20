//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* insert(Node* head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  head->next = insert(newNode, head->next);
  return head;
}

int search(Node* head, int target) {
  while (head) {
    if (head->data == target) {
      return 1;
    } else if (head->data < target) {
      head = head->next;
    } else {
      return 0;
    }
  }

  return 0;
}

int main() {
  Node* head = NULL;
  insert(head, 10);
  insert(head, 20);
  insert(head, 30);
  insert(head, 40);
  insert(head, 50);

  if (search(head, 30) == 1) {
    printf("Target found!\n");
  } else {
    printf("Target not found.\n");
  }

  return 0;
}