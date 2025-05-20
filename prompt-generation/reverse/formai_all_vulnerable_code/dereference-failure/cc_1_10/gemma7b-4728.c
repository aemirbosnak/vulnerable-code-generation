//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

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
    ((*head)->next) = newNode;
  }
}

void findMazeRoute(Node* head) {
  int visited[MAX] = {0};
  visited[head->data] = 1;

  for (Node* current = head; current; current = current->next) {
    if (visited[current->data] == 0) {
      findMazeRoute(current);
    }
  }

  // Print the route
  for (Node* current = head; current; current = current->next) {
    if (visited[current->data] == 1) {
      printf("%d ", current->data);
    }
  }
}

int main() {
  Node* head = NULL;
  insertAtTail(&head, 1);
  insertAtTail(&head, 2);
  insertAtTail(&head, 3);
  insertAtTail(&head, 4);
  insertAtTail(&head, 5);

  findMazeRoute(head);

  return 0;
}