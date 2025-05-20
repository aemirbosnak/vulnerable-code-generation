//FormAI DATASET v1.0 Category: Linked list operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

typedef struct Node Node;

void insert(Node** head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}

void delete(Node** head, int data) {
  Node* currentNode = *head;
  Node* previousNode = NULL;

  while (currentNode != NULL) {
    if (currentNode->data == data) {
      if (previousNode == NULL) {
        *head = currentNode->next;
      } else {
        previousNode->next = currentNode->next;
      }

      free(currentNode);
      return;
    }

    previousNode = currentNode;
    currentNode = currentNode->next;
  }
}

void print(Node* head) {
  Node* currentNode = head;

  while (currentNode != NULL) {
    printf("%d ", currentNode->data);
    currentNode = currentNode->next;
  }

  printf("\n");
}

void reverse(Node** head) {
  Node* previousNode = NULL;
  Node* currentNode = *head;
  Node* nextNode;

  while (currentNode != NULL) {
    nextNode = currentNode->next;
    currentNode->next = previousNode;
    previousNode = currentNode;
    currentNode = nextNode;
  }

  *head = previousNode;
}

int main() {
  Node* head = NULL;

  insert(&head, 1);
  insert(&head, 2);
  insert(&head, 3);
  insert(&head, 4);
  insert(&head, 5);

  printf("Initial list: ");
  print(head);

  delete(&head, 3);

  printf("After deleting 3: ");
  print(head);

  reverse(&head);

  printf("After reversing: ");
  print(head);

  return 0;
}