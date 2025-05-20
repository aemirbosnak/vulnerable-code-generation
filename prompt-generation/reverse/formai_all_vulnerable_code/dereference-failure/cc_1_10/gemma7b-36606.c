//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int data;
  struct node* next;
} node;

node* insert(node* head, int data) {
  node* newNode = malloc(sizeof(node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void recover(node* head) {
  node* current = head;
  node* previous = NULL;

  while (current) {
    int data = current->data;
    free(current);
    current = previous;

    if (previous) {
      previous->next = insert(previous->next, data);
    } else {
      head = insert(head, data);
    }
  }

  head = NULL;
}

int main() {
  node* head = NULL;

  insert(head, 10);
  insert(head, 20);
  insert(head, 30);
  insert(head, 40);

  recover(head);

  head = head->next;

  while (head) {
    printf("%d ", head->data);
    head = head->next;
  }

  printf("\n");

  return 0;
}