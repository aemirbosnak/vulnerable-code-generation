//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define a binary search tree
struct bst {
  int data;
  struct bst *left;
  struct bst *right;
};

// Create a new binary search tree with a given value
struct bst *create_bst(int value) {
  struct bst *new_node = (struct bst *)malloc(sizeof(struct bst));
  new_node->data = value;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Insert a value into a binary search tree
void insert_bst(struct bst **root, int value) {
  if (*root == NULL) {
    *root = create_bst(value);
  } else if (value <= (*root)->data) {
    insert_bst(&(*root)->left, value);
  } else {
    insert_bst(&(*root)->right, value);
  }
}

// Search for a value in a binary search tree
int search_bst(struct bst *root, int value) {
  if (root == NULL) {
    return 0;
  } else if (root->data == value) {
    return 1;
  } else if (value <= root->data) {
    return search_bst(root->left, value);
  } else {
    return search_bst(root->right, value);
  }
}

// Print a binary search tree in order
void print_bst(struct bst *root) {
  if (root != NULL) {
    print_bst(root->left);
    printf("%d ", root->data);
    print_bst(root->right);
  }
}

// Free a binary search tree
void free_bst(struct bst *root) {
  if (root != NULL) {
    free_bst(root->left);
    free_bst(root->right);
    free(root);
  }
}

int main() {
  // Create a binary search tree
  struct bst *root = NULL;
  insert_bst(&root, 10);
  insert_bst(&root, 5);
  insert_bst(&root, 15);
  insert_bst(&root, 2);
  insert_bst(&root, 7);
  insert_bst(&root, 12);
  insert_bst(&root, 20);

  // Print the binary search tree in order
  printf("In-order traversal: ");
  print_bst(root);
  printf("\n");

  // Search for a value in the binary search tree
  int value = 12;
  if (search_bst(root, value)) {
    printf("%d found in the binary search tree.\n", value);
  } else {
    printf("%d not found in the binary search tree.\n", value);
  }

  // Free the binary search tree
  free_bst(root);

  return 0;
}