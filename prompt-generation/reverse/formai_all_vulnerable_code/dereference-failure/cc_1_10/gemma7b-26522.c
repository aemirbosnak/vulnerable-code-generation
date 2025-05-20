//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void createMaze(Node** head) {
  *head = NULL;
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      Node* newNode = (Node*)malloc(sizeof(Node));
      newNode->x = i;
      newNode->y = j;
      newNode->next = NULL;
      if (*head == NULL) {
        *head = newNode;
      } else {
        (*head)->next = newNode;
        *head = newNode;
      }
    }
  }
}

int main() {
  Node* head = NULL;
  createMaze(&head);

  // Find the route from (0, 0) to (MAX - 1, MAX - 1)
  Node* current = head;
  current->x = 0;
  current->y = 0;
  while (current->x != MAX - 1 || current->y != MAX - 1) {
    int dx = rand() % 2 - 1;
    int dy = rand() % 2 - 1;
    current->x += dx;
    current->y += dy;
    current = current->next;
  }

  // Print the route
  current = head;
  while (current) {
    printf("(%d, %d) ", current->x, current->y);
    current = current->next;
  }

  return 0;
}