//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct Node {
  char data;
  struct Node* next;
} Node;

Node* insert(Node* head, char data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

int search(Node* head, char target) {
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
  insert(head, 'a');
  insert(head, 'b');
  insert(head, 'c');
  insert(head, 'd');
  insert(head, 'e');

  if (search(head, 'c') == 1) {
    printf("Target found.\n");
  } else {
    printf("Target not found.\n");
  }

  return 0;
}