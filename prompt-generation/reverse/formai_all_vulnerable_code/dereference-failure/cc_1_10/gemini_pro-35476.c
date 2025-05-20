//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: Sherlock Holmes
// The game is afoot, Watson!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A binary search tree (BST) is a data structure that stores data in a hierarchical manner.
// Each node in the BST contains a value and pointers to the left and right child nodes.
typedef struct node {
  int value;
  struct node *left;
  struct node *right;
} node_t;

// Create a new BST node with the given value.
node_t *create_node(int value) {
  node_t *node = malloc(sizeof(node_t));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Insert a new value into the BST.
void insert_value(node_t **root, int value) {
  if (*root == NULL) {
    *root = create_node(value);
  } else if (value < (*root)->value) {
    insert_value(&(*root)->left, value);
  } else {
    insert_value(&(*root)->right, value);
  }
}

// Search for a value in the BST.
node_t *search_value(node_t *root, int value) {
  if (root == NULL) {
    return NULL;
  } else if (root->value == value) {
    return root;
  } else if (value < root->value) {
    return search_value(root->left, value);
  } else {
    return search_value(root->right, value);
  }
}

// Print the BST in order.
void print_in_order(node_t *root) {
  if (root != NULL) {
    print_in_order(root->left);
    printf("%d ", root->value);
    print_in_order(root->right);
  }
}

// Free the BST.
void free_tree(node_t *root) {
  if (root != NULL) {
    free_tree(root->left);
    free_tree(root->right);
    free(root);
  }
}

// The main function.
int main() {
  // Create a new BST.
  node_t *root = NULL;

  // Insert some values into the BST.
  insert_value(&root, 10);
  insert_value(&root, 5);
  insert_value(&root, 15);
  insert_value(&root, 3);
  insert_value(&root, 7);
  insert_value(&root, 12);
  insert_value(&root, 18);

  // Search for a value in the BST.
  node_t *found_node = search_value(root, 12);
  if (found_node != NULL) {
    printf("Found the value %d in the BST.\n", found_node->value);
  } else {
    printf("Could not find the value 12 in the BST.\n");
  }

  // Print the BST in order.
  printf("The BST in order is: ");
  print_in_order(root);
  printf("\n");

  // Free the BST.
  free_tree(root);

  return 0;
}