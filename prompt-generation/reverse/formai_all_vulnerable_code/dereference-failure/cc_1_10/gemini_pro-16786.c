//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// A node in a binary tree
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

// Create a new node with the given data
struct Node *createNode(int data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Insert a new node into a binary tree
void insertNode(struct Node **root, int data) {
  if (*root == NULL) {
    *root = createNode(data);
  } else if (data <= (*root)->data) {
    insertNode(&(*root)->left, data);
  } else {
    insertNode(&(*root)->right, data);
  }
}

// Visualize a binary tree using ASCII art
void visualizeTree(struct Node *root, int space) {
  if (root == NULL) {
    return;
  }

  space += 10;

  // Process right child first
  visualizeTree(root->right, space);

  // Print current node value
  printf("\n");
  for (int i = 10; i < space; i++) {
    printf(" ");
  }
  printf("%d\n", root->data);

  // Process left child
  visualizeTree(root->left, space);
}

// Main function
int main() {
  // Create a binary tree
  struct Node *root = NULL;
  insertNode(&root, 50);
  insertNode(&root, 30);
  insertNode(&root, 20);
  insertNode(&root, 40);
  insertNode(&root, 70);
  insertNode(&root, 60);
  insertNode(&root, 80);

  // Visualize the binary tree
  visualizeTree(root, 0);

  return 0;
}