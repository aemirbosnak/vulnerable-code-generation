//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

// Create a new node
node *create_node(int data) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Insert a node into the tree
node *insert_node(node *root, int data) {
  if (root == NULL) {
    return create_node(data);
  } else if (data < root->data) {
    root->left = insert_node(root->left, data);
  } else {
    root->right = insert_node(root->right, data);
  }
  return root;
}

// Search for a node in the tree
node *search_node(node *root, int data) {
  if (root == NULL) {
    return NULL;
  } else if (data == root->data) {
    return root;
  } else if (data < root->data) {
    return search_node(root->left, data);
  } else {
    return search_node(root->right, data);
  }
}

// Print the tree in order
void print_tree(node *root) {
  if (root != NULL) {
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
  }
}

// Free the tree
void free_tree(node *root) {
  if (root != NULL) {
    free_tree(root->left);
    free_tree(root->right);
    free(root);
  }
}

// Main function
int main() {
  // Create a root node
  node *root = create_node(10);

  // Insert some nodes into the tree
  insert_node(root, 5);
  insert_node(root, 15);
  insert_node(root, 2);
  insert_node(root, 7);
  insert_node(root, 12);
  insert_node(root, 20);

  // Print the tree in order
  print_tree(root);

  // Search for a node in the tree
  node *found_node = search_node(root, 15);
  if (found_node != NULL) {
    printf("\nFound node with data %d\n", found_node->data);
  } else {
    printf("\nNode with data 15 not found\n");
  }

  // Free the tree
  free_tree(root);

  return 0;
}