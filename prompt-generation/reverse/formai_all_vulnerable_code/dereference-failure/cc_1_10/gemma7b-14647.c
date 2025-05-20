//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: brave
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void createPercolation(Node** head) {
  *head = malloc(sizeof(Node));
  (*head)->x = 0;
  (*head)->y = 0;
  (*head)->next = NULL;

  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++) {
      Node* newNode = malloc(sizeof(Node));
      newNode->x = x;
      newNode->y = y;
      newNode->next = NULL;

      ((*head)->next) = newNode;
      (*head) = newNode;
    }
  }
}

int main() {
  Node* head = NULL;
  createPercolation(&head);

  // Simulate Percolation
  for (int i = 0; i < 100; i++) {
    int x = rand() % WIDTH;
    int y = rand() % HEIGHT;

    if (head->x == x && head->y == y) {
      head->next = malloc(sizeof(Node));
      head = head->next;
      head->x = x;
      head->y = y;
    }
  }

  // Print Percolation
  for (Node* node = head; node; node = node->next) {
    printf("%d %d\n", node->x, node->y);
  }

  return 0;
}