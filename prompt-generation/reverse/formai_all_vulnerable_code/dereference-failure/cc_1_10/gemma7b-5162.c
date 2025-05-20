//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void createMaze(Node** head, int n, int m) {
  time_t t = time(NULL);
  srand(t);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      Node* newNode = malloc(sizeof(Node));
      newNode->x = i;
      newNode->y = j;
      newNode->next = NULL;

      if (*head == NULL) {
        *head = newNode;
      } else {
        ((*head)->next = newNode);
        head = &((*head)->next);
      }
    }
  }
}

void findRoute(Node* head, int x, int y) {
  while (head) {
    if (head->x == x && head->y == y) {
      printf("Found the route!");
      return;
    } else if (head->x == x && head->y != y) {
      printf("Moving horizontally...");
      head = head->next;
    } else if (head->x != x && head->y == y) {
      printf("Moving vertically...");
      head = head->next;
    } else {
      printf("Exploring...");
      head = head->next;
    }
  }

  printf("No route found!");
}

int main() {
  Node* head = NULL;
  createMaze(&head, 5, 5);
  findRoute(head, 2, 2);

  return 0;
}