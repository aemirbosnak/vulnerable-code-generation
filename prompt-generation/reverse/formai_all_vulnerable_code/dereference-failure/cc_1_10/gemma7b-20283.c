//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

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
    ((*head)->next = newNode);
  }
}

int main() {
  Node* head = NULL;
  insertAtTail(&head, 1);
  insertAtTail(&head, 2);
  insertAtTail(&head, 3);
  insertAtTail(&head, 4);
  insertAtTail(&head, 5);

  // Traverse the linked list
  Node* current = head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }

  // Find the route from node 1 to node 5
  current = head;
  int routeFound = 0;
  while (current) {
    if (current->data == 1) {
      // Start from node 1
      routeFound = 1;
    } else if (routeFound && current->data == 5) {
      // End at node 5
      printf("Route found!\n");
      return 0;
    } else if (routeFound) {
      // Continue the journey
      current = current->next;
    }
  }

  // No route found
  printf("No route found.\n");
  return 0;
}