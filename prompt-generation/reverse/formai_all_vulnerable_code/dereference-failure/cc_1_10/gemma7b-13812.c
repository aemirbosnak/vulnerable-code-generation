//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define MAX_Turns 5

typedef struct Node {
  int x;
  int y;
  struct Node* next;
} Node;

void createMaze(Node** head) {
  int i, j;
  *head = NULL;
  for (i = 0; i < MAX_SIZE; i++) {
    for (j = 0; j < MAX_SIZE; j++) {
      Node* newNode = malloc(sizeof(Node));
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

  // Generate a random route
  int turns = 0;
  srand(time(NULL));
  for (int i = 0; i < MAX_Turns; i++) {
    int x = rand() % MAX_SIZE;
    int y = rand() % MAX_SIZE;
    Node* current = head;
    while (current) {
      if (current->x == x && current->y == y) {
        printf("Turn %d: (%d, %d)\n", turns, x, y);
        current = current->next;
        turns++;
      }
    }
  }

  return 0;
}