//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insert(Node** head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->next = newNode);
    *head = newNode;
  }
}

void greedy_algorithm(Node** head) {
  Node* current = *head;
  Node* previous = NULL;
  int total = 0;

  while (current) {
    int data = current->data;
    insert(previous, data);
    previous = current;
    current = current->next;
    total += data;
  }

  printf("Total: %d\n", total);
}

int main() {
  Node* head = NULL;
  insert(&head, 5);
  insert(&head, 3);
  insert(&head, 8);
  insert(&head, 2);
  insert(&head, 4);

  greedy_algorithm(&head);

  return 0;
}