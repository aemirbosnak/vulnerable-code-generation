//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Node {
  struct Node* next;
  char data;
} Node;

void insertAtTail(Node** head, char data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->next = newNode);
  }
}

void greedyAlgorithm(Node* head) {
  Node* current = head;
  Node* previous = NULL;
  char maxValue = 'a';

  while (current) {
    if (current->data > maxValue) {
      maxValue = current->data;
      previous = current;
    }
    current = current->next;
  }

  if (previous) {
    previous->data = maxValue;
  }
}

int main() {
  Node* head = NULL;

  insertAtTail(&head, 'f');
  insertAtTail(&head, 'b');
  insertAtTail(&head, 'a');
  insertAtTail(&head, 'g');
  insertAtTail(&head, 'h');

  greedyAlgorithm(head);

  printf("%c", head->data);
  printf("%c", (head->next)->data);
  printf("%c", (head->next->next)->data);

  return 0;
}