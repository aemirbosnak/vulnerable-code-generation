//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* createNode(int x, int y) {
  Node* node = malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->next = NULL;
  return node;
}

void insertNode(Node* head, int x, int y) {
  Node* newNode = createNode(x, y);
  if (head == NULL) {
    head = newNode;
  } else {
    Node* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

int main() {
  Node* head = NULL;
  insertNode(head, 0, 0);
  insertNode(head, 1, 0);
  insertNode(head, 2, 0);
  insertNode(head, 3, 0);
  insertNode(head, 4, 0);
  insertNode(head, 0, 1);
  insertNode(head, 1, 1);
  insertNode(head, 2, 1);
  insertNode(head, 3, 1);
  insertNode(head, 4, 1);

  // Find the shortest path from (0, 0) to (4, 1)
  Node* current = head;
  while (current) {
    if (current->x == 4 && current->y == 1) {
      printf("Path found!\n");
      break;
    }
    current = current->next;
  }

  if (current == NULL) {
    printf("No path found.\n");
  }

  return 0;
}