//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

node *head = NULL;

void insert(int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  if (head == NULL) {
    head = new_node;
  } else {
    node *curr = head;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = new_node;
  }
}

void print() {
  node *curr = head;
  while (curr != NULL) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

int search(int data) {
  node *curr = head;
  int index = 0;
  while (curr != NULL) {
    if (curr->data == data) {
      return index;
    }
    curr = curr->next;
    index++;
  }
  return -1;
}

int main() {
  insert(1);
  insert(2);
  insert(3);
  insert(4);
  insert(5);
  print();
  int index = search(3);
  if (index == -1) {
    printf("Element not found\n");
  } else {
    printf("Element found at index %d\n", index);
  }
  return 0;
}