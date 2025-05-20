//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 20

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void generateMap(Node** head) {
  time_t t = time(NULL);
  srand(t);

  int x, y;
  for (x = 0; x < WIDTH; x++) {
    for (y = 0; y < HEIGHT; y++) {
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
  }

  // Connect nodes randomly
  for (x = 0; x < WIDTH; x++) {
    for (y = 0; y < HEIGHT; y++) {
      Node* current = (*head)->next;
      while (current) {
        if (current->x != x || current->y != y) {
          int r = rand() % 4;
          switch (r) {
            case 0:
              current->next = (*head)->next->next;
              break;
            case 1:
              current->next = (*head)->next->next->next;
              break;
            case 2:
              current->next = (*head)->next->next->next->next;
              break;
            case 3:
              current->next = (*head)->next->next->next->next->next;
              break;
          }
        }
      }
    }
  }
}

int main() {
  Node* head = NULL;
  generateMap(&head);

  // Do something with the map, such as printing it out
  for (Node* current = head; current; current = current->next) {
    printf("(%d, %d)\n", current->x, current->y);
  }

  return 0;
}