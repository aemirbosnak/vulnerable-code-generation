//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10

typedef struct Node {
  struct Node* up;
  struct Node* left;
  struct Node* right;
  int state;
} Node;

void percolat(Node* node) {
  if (node->state == 1) {
    return;
  }
  node->state = 1;

  if (node->left) {
    percolat(node->left);
  }
  if (node->right) {
    percolat(node->right);
  }
}

int main() {
  srand(time(NULL));

  Node* root = NULL;
  root = malloc(sizeof(Node));
  root->up = NULL;
  root->left = NULL;
  root->right = NULL;
  root->state = 0;

  int n = DIM;
  for (int i = 0; i < n; i++) {
    Node* newNode = malloc(sizeof(Node));
    newNode->up = root;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->state = 0;

    root->left = newNode;
    root = newNode;
  }

  percolat(root);

  printf("Percolation complete!\n");

  return 0;
}