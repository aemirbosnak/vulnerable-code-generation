//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void initialize(Node** head, int size) {
  *head = NULL;
  for (int i = 0; i < size; i++) {
    *head = malloc(sizeof(Node));
    (*head)->x = i;
    (*head)->y = -1;
    (*head)->next = NULL;
    head = &((*head)->next);
  }
}

void findRoute(Node* head) {
  time_t start = time(NULL);
  int x, y, target_x, target_y;
  scanf("Enter target x: ", &target_x);
  scanf("Enter target y: ", &target_y);
  x = head->x;
  y = head->y;

  while (x != target_x || y != target_y) {
    if (x < target_x) {
      x++;
    } else if (x > target_x) {
      x--;
    }
    if (y < target_y) {
      y++;
    } else if (y > target_y) {
      y--;
    }

    for (Node* node = head; node; node = node->next) {
      if (node->x == x && node->y == y) {
        printf("Found route: (%d, %d) - (%d, %d)\n", x, y, target_x, target_y);
        break;
      }
    }
  }

  time_t end = time(NULL);
  printf("Time taken: %ld seconds\n", end - start);
}

int main() {
  Node* head;
  initialize(&head, MAX_SIZE);
  findRoute(head);
  return 0;
}