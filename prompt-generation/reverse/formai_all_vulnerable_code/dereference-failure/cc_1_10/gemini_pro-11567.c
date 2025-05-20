//GEMINI-pro DATASET v1.0 Category: Educational ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

void insert(int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = head;
  head = new_node;
}

void print() {
  struct node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

void reverse() {
  struct node *current = head;
  struct node *prev = NULL;
  struct node *next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}

int main() {
  insert(10);
  insert(20);
  insert(30);
  insert(40);
  insert(50);
  print();
  reverse();
  print();
  return 0;
}