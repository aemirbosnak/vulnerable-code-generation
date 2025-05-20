//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x;
  int y;
  struct Node* next;
} Node;

Node* createNode(int x, int y) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->next = NULL;
  return node;
}

void printBoard(Node* board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      Node* current = board;
      while (current) {
        if (current->x == i && current->y == j) {
          printf("%c ", current->x + 1 + 'a' - 'a');
        } else {
          printf(".");
        }
      }
    }
    printf("\n");
  }
}

int main() {
  Node* board = createNode(0, 0);
  board = createNode(1, 0);
  board = createNode(2, 0);
  board = createNode(0, 1);
  board = createNode(1, 1);
  board = createNode(2, 1);
  board = createNode(0, 2);
  board = createNode(1, 2);
  board = createNode(2, 2);

  printBoard(board);

  return 0;
}