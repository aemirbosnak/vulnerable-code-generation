//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// A node in a binary tree
struct node {
  int data;
  struct node *left;
  struct node *right;
};

// Create a new node with the given data
struct node *create_node(int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Insert a new node into a binary tree
struct node *insert_node(struct node *root, int data) {
  if (root == NULL) {
    return create_node(data);
  } else if (data < root->data) {
    root->left = insert_node(root->left, data);
  } else {
    root->right = insert_node(root->right, data);
  }
  return root;
}

// Print a binary tree in a visual format
void print_tree(struct node *root) {
  if (root == NULL) {
    return;
  }

  // Print the left subtree
  print_tree(root->left);

  // Print the root
  printf("%d\n", root->data);

  // Print the right subtree
  print_tree(root->right);
}

int main() {
  // Create a binary tree
  struct node *root = NULL;
  root = insert_node(root, 10);
  root = insert_node(root, 5);
  root = insert_node(root, 15);
  root = insert_node(root, 2);
  root = insert_node(root, 7);
  root = insert_node(root, 12);
  root = insert_node(root, 20);

  // Print the binary tree
  print_tree(root);

  return 0;
}