//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

// Insert a node into a binary search tree
node *insert(node *root, int data) {
  if (root == NULL) {
    root = (node *)malloc(sizeof(node));
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

// Search for a node in a binary search tree
node *search(node *root, int data) {
  if (root == NULL) {
    return NULL;
  } else if (data == root->data) {
    return root;
  } else if (data < root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}

// Print a binary search tree in preorder
void preorder(node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

// Print a binary search tree in inorder
void inorder(node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

// Print a binary search tree in postorder
void postorder(node *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

// Free the memory allocated for a binary search tree
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
  node *found = search(root, 15);
  if (found != NULL) {
    printf("Node found: %d\n", found->data);
  } else {
    printf("Node not found.\n");
  }

  // Print the binary search tree in preorder
  printf("Preorder: ");
  preorder(root);
  printf("\n");

  // Print the binary search tree in inorder
  printf("Inorder: ");
  inorder(root);
  printf("\n");

  // Print the binary search tree in postorder
  printf("Postorder: ");
  postorder(root);
  printf("\n");

  // Free the memory allocated for the binary search tree
  free_tree(root);

  return 0;
}