//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct node {
  int data;
  struct node* next;
};

void insert(struct node** head, int data) {
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void schedule(struct node** head) {
  struct node* current = *head;
  struct node* next = NULL;

  while (current) {
    next = current->next;
    current->data = rand() % MAX;
    current = next;
  }

  printf("Data after scheduling:");
  insert(*head, 0);
  current = *head;
  while (current) {
    printf(" %d", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  struct node* head = NULL;

  insert(&head, 10);
  insert(&head, 20);
  insert(&head, 30);
  insert(&head, 40);
  insert(&head, 50);

  schedule(&head);

  return 0;
}