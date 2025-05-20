//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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

void printList(Node* head) {
  while (head) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  Node* head = NULL;

  insert(&head, 10);
  insert(&head, 20);
  insert(&head, 30);
  insert(&head, 40);
  insert(&head, 50);

  printList(head);

  // Greedy Algorithm - Sort the list in descending order

  Node* current = head;
  Node* previous = NULL;
  while (current) {
    Node* next = current->next;
    if (previous && current->data < previous->data) {
      int temp = current->data;
      current->data = previous->data;
      previous->data = temp;
    }
    previous = current;
    current = next;
  }

  printList(head);

  return 0;
}