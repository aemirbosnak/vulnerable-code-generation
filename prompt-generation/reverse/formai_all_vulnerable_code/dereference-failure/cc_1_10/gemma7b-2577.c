//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void paranoid_insert(Node** head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void paranoid_delete(Node** head, int data) {
  Node* prev = NULL;
  Node* current = *head;

  while (current) {
    if (current->data == data) {
      if (prev) {
        prev->next = current->next;
      } else {
        *head = current->next;
      }
      free(current);
      return;
    }
    prev = current;
    current = current->next;
  }

  return;
}

int main() {
  Node* head = NULL;
  paranoid_insert(&head, 10);
  paranoid_insert(&head, 20);
  paranoid_insert(&head, 30);
  paranoid_insert(&head, 40);

  paranoid_delete(&head, 20);

  for (Node* current = head; current; current = current->next) {
    printf("%d ", current->data);
  }

  return 0;
}