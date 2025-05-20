//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: innovative
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 256

typedef struct Node {
  struct Node* up, *right, *down, *left;
  int water;
} Node;

Node* newNode(void) {
  Node* node = malloc(sizeof(Node));
  node->up = NULL;
  node->right = NULL;
  node->down = NULL;
  node->left = NULL;
  node->water = 0;
  return node;
}

void percolate(Node* node) {
  if (node->water) {
    node->water = 0;
    if (node->up) {
      node->up->water++;
    }
    if (node->right) {
      node->right->water++;
    }
    if (node->down) {
      node->down->water++;
    }
    if (node->left) {
      node->left->water++;
    }
  }
}

int main() {
  srand(time(NULL));
  Node* grid = newNode();
  for (int i = 0; i < DIM; i++) {
    newNode();
  }
  for (int i = 0; i < DIM; i++) {
    grid->down = newNode();
    grid = grid->down;
  }
  grid->water = 1;
  percolate(grid);
  printf("Water distribution:");
  for (int i = 0; i < DIM; i++) {
    printf(" %d", grid->water);
    grid = grid->right;
  }
  printf("\n");
  return 0;
}