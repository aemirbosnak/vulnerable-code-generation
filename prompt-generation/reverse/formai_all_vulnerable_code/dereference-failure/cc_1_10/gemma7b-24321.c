//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct node {
  int data;
  struct node* next;
} node;

void insert(node** head, int data) {
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->next = newNode);
    *head = newNode;
  }
}

void schedule(node* head) {
  int i = 0;
  node* current = head;

  while (current) {
    printf("Process %d is running...\n", current->data);
    sleep(rand() % MAX);
    i++;
    current = current->next;
  }

  printf("Total processes scheduled: %d\n", i);
}

int main() {
  node* head = NULL;
  insert(&head, 1);
  insert(&head, 2);
  insert(&head, 3);
  insert(&head, 4);
  insert(&head, 5);

  schedule(head);

  return 0;
}