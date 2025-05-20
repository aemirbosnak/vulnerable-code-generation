//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

int main() {
  time_t t = time(NULL);
  srand(t);

  Node* head = NULL;
  insertAtTail(&head, 1);
  insertAtTail(&head, 2);
  insertAtTail(&head, 3);
  insertAtTail(&head, 4);
  insertAtTail(&head, 5);

  int target = rand() % MAX_SIZE + 1;

  // Find target in the list
  Node* current = head;
  while (current) {
    if (current->data == target) {
      printf("Target found: %d\n", target);
      break;
    } else {
      current = current->next;
    }
  }

  if (current == NULL) {
    printf("Target not found\n");
  }

  return 0;
}