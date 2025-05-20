//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node in the binary search tree
struct node {
  int value;
  struct node *left;
  struct node *right;
};

// Create a new node with the given value
struct node *create_node(int value) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Insert a new node with the given value into the binary search tree
struct node *insert_node(struct node *root, int value) {
  if (root == NULL) {
    return create_node(value);
  } else if (value < root->value) {
    root->left = insert_node(root->left, value);
  } else {
    root->right = insert_node(root->right, value);
  }
  return root;
}

// Search for the given value in the binary search tree
struct node *search_node(struct node *root, int value) {
  if (root == NULL) {
    return NULL;
  } else if (value == root->value) {
    return root;
  } else if (value < root->value) {
    return search_node(root->left, value);
  } else {
    return search_node(root->right, value);
  }
}

// Print the binary search tree in order
void print_tree(struct node *root) {
  if (root != NULL) {
    print_tree(root->left);
    printf("%d ", root->value);
    print_tree(root->right);
  }
}

// Free the memory allocated for the binary search tree
void free_tree(struct node *root) {
  if (root != NULL) {
    free_tree(root->left);
    free_tree(root->right);
    free(root);
  }
}

int main() {
  // Create a binary search tree
  struct node *root = NULL;
  root = insert_node(root, 10);
  root = insert_node(root, 5);
  root = insert_node(root, 15);
  root = insert_node(root, 2);
  root = insert_node(root, 7);
  root = insert_node(root, 12);
  root = insert_node(root, 20);

  // Print the binary search tree
  printf("Binary search tree: ");
  print_tree(root);
  printf("\n");

  // Search for a value in the binary search tree
  int value = 12;
  struct node *found_node = search_node(root, value);
  if (found_node != NULL) {
    printf("Found the value %d in the binary search tree.\n", value);
  } else {
    printf("Did not find the value %d in the binary search tree.\n", value);
  }

  // Free the memory allocated for the binary search tree
  free_tree(root);

  return 0;
}