//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define a custom data type for a node in the binary search tree
typedef struct node {
  int value;
  struct node *left;
  struct node *right;
} node_t;

// Create a new node with the given value
node_t *create_node(int value) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Insert a new node into the binary search tree
void insert_node(node_t **root, int value) {
  if (*root == NULL) {
    *root = create_node(value);
    return;
  }

  if (value < (*root)->value) {
    insert_node(&(*root)->left, value);
  } else {
    insert_node(&(*root)->right, value);
  }
}

// Search for a node with the given value in the binary search tree
node_t *search_node(node_t *root, int value) {
  if (root == NULL) {
    return NULL;
  }

  if (root->value == value) {
    return root;
  }

  if (value < root->value) {
    return search_node(root->left, value);
  } else {
    return search_node(root->right, value);
  }
}

// Print the binary search tree in order (left, root, right)
void print_tree(node_t *root) {
  if (root == NULL) {
    return;
  }

  print_tree(root->left);
  printf("%d ", root->value);
  print_tree(root->right);
}

// Free the memory allocated for the binary search tree
void free_tree(node_t *root) {
  if (root == NULL) {
    return;
  }

  free_tree(root->left);
  free_tree(root->right);
  free(root);
}

int main() {
  // Create a binary search tree
  node_t *root = NULL;

  // Insert some values into the binary search tree
  insert_node(&root, 10);
  insert_node(&root, 5);
  insert_node(&root, 15);
  insert_node(&root, 2);
  insert_node(&root, 7);
  insert_node(&root, 12);
  insert_node(&root, 20);

  // Print the binary search tree in order
  printf("Binary search tree: ");
  print_tree(root);
  printf("\n");

  // Search for a node with the value 7 in the binary search tree
  node_t *node = search_node(root, 7);
  if (node != NULL) {
    printf("Node with value 7 found: %d\n", node->value);
  } else {
    printf("Node with value 7 not found.\n");
  }

  // Free the memory allocated for the binary search tree
  free_tree(root);

  return 0;
}