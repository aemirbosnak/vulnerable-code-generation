//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Create a node for a binary tree
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

// Create a new node with the given data
node *create_node(int data) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Insert a new node into a binary tree
void insert_node(node **root, int data) {
  if (*root == NULL) {
    *root = create_node(data);
  } else if (data <= (*root)->data) {
    insert_node(&(*root)->left, data);
  } else {
    insert_node(&(*root)->right, data);
  }
}

// Print a binary tree in a visual format
void print_tree(node *root, int level) {
  if (root == NULL) {
    return;
  }

  // Print the current node
  printf("%d ", root->data);

  // Print the left subtree
  if (root->left != NULL) {
    printf("(");
    print_tree(root->left, level + 1);
    printf(")");
  }

  // Print the right subtree
  if (root->right != NULL) {
    printf("(");
    print_tree(root->right, level + 1);
    printf(")");
  }
}

// Free the memory allocated for a binary tree
void free_tree(node *root) {
  if (root == NULL) {
    return;
  }

  free_tree(root->left);
  free_tree(root->right);
  free(root);
}

int main() {
  // Create a binary tree
  node *root = NULL;
  insert_node(&root, 10);
  insert_node(&root, 5);
  insert_node(&root, 15);
  insert_node(&root, 2);
  insert_node(&root, 7);
  insert_node(&root, 12);
  insert_node(&root, 20);

  // Print the binary tree in a visual format
  print_tree(root, 0);

  // Free the memory allocated for the binary tree
  free_tree(root);

  return 0;
}