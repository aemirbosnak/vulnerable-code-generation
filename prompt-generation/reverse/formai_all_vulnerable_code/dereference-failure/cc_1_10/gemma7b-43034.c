//Gemma-7B DATASET v1.0 Category: Sorting ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->next = newNode);
  }
}

void sortByData(Node** head) {
  int i = 0;
  Node* current = *head;
  Node* previous = NULL;

  while (current) {
    int currentData = current->data;
    int j = i + 1;

    for (Node* comparison = current->next; comparison; comparison) {
      if (currentData > comparison->data) {
        int temp = currentData;
        currentData = comparison->data;
        comparison->data = temp;

        if (previous) {
          previous->next = comparison;
        } else {
          *head = comparison;
        }
      }
    }

    i++;
    previous = current;
  }

  *head = current;
}

int main() {
  Node* head = NULL;
  insertAtTail(&head, 5);
  insertAtTail(&head, 3);
  insertAtTail(&head, 8);
  insertAtTail(&head, 2);
  insertAtTail(&head, 4);

  sortByData(&head);

  printf("Sorted list:");
  while (head) {
    printf(" %d", head->data);
    head = head->next;
  }

  printf("\n");

  return 0;
}