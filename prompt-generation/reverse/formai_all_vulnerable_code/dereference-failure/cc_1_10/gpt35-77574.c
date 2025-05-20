//FormAI DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

struct Node {
  char data;
  struct Node* left;
  struct Node* right;
};

struct Node* createNode(char data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

void insert(struct Node* root, char data) {
  if (root->left == NULL) {
    root->left = createNode(data);
  }
  else if (root->right == NULL) {
    root->right = createNode(data);
  }
  else if (root->left->left == NULL || root->left->right == NULL) {
    insert(root->left, data);
  }
  else if (root->right->left == NULL || root->right->right == NULL) {
    insert(root->right, data);
  }
}

void visualize(struct Node* root, int space) {
  if (root == NULL) {
    return;
  }

  space += 5;

  visualize(root->right, space);
  printf("\n");
  
  for (int i = 5; i < space; i++) {
    printf(" ");
  }
  
  printf("%c\n", root->data);
  
  visualize(root->left, space);
}

int main() {
  struct Node* root;

  // Create root node
  root = createNode('A');

  // Insert child nodes
  insert(root, 'B');
  insert(root, 'C');
  insert(root, 'D');
  insert(root, 'E');
  insert(root, 'F');
  insert(root, 'G');

  // Visualize tree
  visualize(root, 0);

  return 0;
}