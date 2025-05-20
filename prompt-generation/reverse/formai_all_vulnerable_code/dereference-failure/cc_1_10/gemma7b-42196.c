//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5
#define MAX_MOVES 9

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* newNode(int x, int y) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->next = NULL;
  return node;
}

void printBoard(Node* head) {
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      Node* current = head;
      while (current) {
        if (current->x == r && current->y == c) {
          printf("%c ", current->x + 1 + current->y);
        } else {
          printf(". ");
        }
      }
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));
  Node* head = newNode(0, 0);
  head->next = newNode(1, 0);
  head->next->next = newNode(2, 0);
  head->next->next->next = newNode(3, 0);
  head->next->next->next->next = newNode(4, 0);
  head->next->next->next->next->next = newNode(2, 1);
  head->next->next->next->next->next->next = newNode(3, 1);

  printBoard(head);

  return 0;
}