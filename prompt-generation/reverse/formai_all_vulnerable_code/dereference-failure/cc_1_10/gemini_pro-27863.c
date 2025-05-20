//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: light-weight
#include <stdlib.h>
#include <stdio.h>

// A node in the binary search tree
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

// Insert a new node into the binary search tree
node* insert(node *root, int data) {
  if (root == NULL) {
    root = malloc(sizeof(node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
  } else if (data < root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }
  return root;
}

// Search for a node in the binary search tree
node* search(node *root, int data) {
  if (root == NULL || root->data == data) {
    return root;
  } else if (data < root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}

// Print the binary search tree in order
void print_inorder(node *root) {
  if (root != NULL) {
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
  }
}

// Free the binary search tree
void free_tree(node *root) {
  if (root != NULL) {
    free_tree(root->left);
    free_tree(root->right);
    free(root);
  }
}

// Main function
int main() {
  // Create a binary search tree
  node *root = NULL;
  root = insert(root, 10);
  root = insert(root, 5);
  root = insert(root, 15);
  root = insert(root, 2);
  root = insert(root, 7);
  root = insert(root, 12);
  root = insert(root, 20);

  // Search for a node in the binary search tree
  node *result = search(root, 15);
  if (result == NULL) {
    printf("Node not found\n");
  } else {
    printf("Node found: %d\n", result->data);
  }

  // Print the binary search tree in order
  print_inorder(root);
  printf("\n");

  // Free the binary search tree
  free_tree(root);

  return 0;
}