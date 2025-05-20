//Gemma-7B DATASET v1.0 Category: Chess engine ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOARD_SIZE 64

typedef struct Node {
  int x, y;
  struct Node* up, *down, *left, *right;
} Node;

Node* createNode(int x, int y) {
  Node* node = malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->up = NULL;
  node->down = NULL;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void connectNodes(Node* a, Node* b) {
  a->up = b;
  b->down = a;
  a->left = b;
  b->right = a;
}

void traverseBoard(Node* node) {
  printf("(%d, %d) ", node->x, node->y);
  if (node->up) {
    printf("U ");
  }
  if (node->down) {
    printf("D ");
  }
  if (node->left) {
    printf("L ");
  }
  if (node->right) {
    printf("R ");
  }
  printf("\n");
}

int main() {
  Node* board = createNode(0, 0);
  connectNodes(board, createNode(1, 0));
  connectNodes(board, createNode(0, 1));
  connectNodes(board, createNode(1, 1));
  traverseBoard(board);
  return 0;
}