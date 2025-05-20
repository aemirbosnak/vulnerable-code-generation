//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void insert(Node** head, int x, int y) {
  Node* newNode = malloc(sizeof(Node));
  newNode->x = x;
  newNode->y = y;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void findPath(Node** head, int x, int y) {
  if (*head == NULL) {
    return;
  }

  Node* current = *head;

  while (current) {
    if (current->x == x && current->y == y) {
      printf("Path found!\n");
      return;
    } else if (current->x > x || current->y > y) {
      current = current->next;
    } else {
      insert(&current, current->x - 1, current->y);
      insert(&current, current->x + 1, current->y);
      insert(&current, current->x, current->y - 1);
      insert(&current, current->x, current->y + 1);
      current = current->next;
    }
  }

  printf("No path found.\n");
}

int main() {
  Node* head = NULL;
  insert(&head, 0, 0);
  insert(&head, 1, 0);
  insert(&head, 2, 0);
  insert(&head, 3, 0);
  insert(&head, 0, 1);
  insert(&head, 1, 1);
  insert(&head, 2, 1);
  insert(&head, 3, 1);

  findPath(&head, 2, 1);

  return 0;
}