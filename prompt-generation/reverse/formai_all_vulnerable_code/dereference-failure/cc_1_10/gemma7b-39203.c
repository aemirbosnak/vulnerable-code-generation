//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insert(Node** head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void greedy_algorithm(Node* head) {
  Node* current = head;
  Node* previous = NULL;
  int sum = 0;

  while (current) {
    int current_data = current->data;
    current->data = sum + current_data;
    sum += current_data;
    previous = current;
    current = current->next;
  }

  previous->next = head;
}

int main() {
  Node* head = NULL;
  insert(&head, 10);
  insert(&head, 20);
  insert(&head, 30);
  insert(&head, 40);
  insert(&head, 50);

  greedy_algorithm(head);

  Node* current = head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }

  return 0;
}