//Gemma-7B DATASET v1.0 Category: Pathfinding algorithms ; Style: Linus Torvalds
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void print_path(Node* node) {
  while (node) {
    printf("(%d, %d) ", node->x, node->y);
    node = node->next;
  }
}

Node* find_path(int x, int y) {
  Node* head = malloc(sizeof(Node));
  head->x = x;
  head->y = y;
  head->next = NULL;

  Node* current = head;
  Node* next = NULL;

  // Traverse the grid
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      if (x + dx >= 0 && x + dx < MAX_SIZE && y + dy >= 0 && y + dy < MAX_SIZE) {
        next = malloc(sizeof(Node));
        next->x = x + dx;
        next->y = y + dy;
        next->next = NULL;

        current->next = next;
        current = next;
      }
    }
  }

  return head;
}

int main() {
  Node* path = find_path(10, 10);
  print_path(path);

  return 0;
}