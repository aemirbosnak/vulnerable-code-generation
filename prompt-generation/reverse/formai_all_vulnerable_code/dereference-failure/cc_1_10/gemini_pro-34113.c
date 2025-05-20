//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The surrealist binary tree
struct surrealist_binary_tree {
  int value;
  struct surrealist_binary_tree *left;
  struct surrealist_binary_tree *right;
};

// Create a new surrealist binary tree
struct surrealist_binary_tree *new_surrealist_binary_tree(int value) {
  struct surrealist_binary_tree *tree = malloc(sizeof(struct surrealist_binary_tree));
  tree->value = value;
  tree->left = NULL;
  tree->right = NULL;
  return tree;
}

// Insert a new value into the surrealist binary tree
void insert_surrealist_binary_tree(struct surrealist_binary_tree *tree, int value) {
  if (value < tree->value) {
    if (tree->left == NULL) {
      tree->left = new_surrealist_binary_tree(value);
    } else {
      insert_surrealist_binary_tree(tree->left, value);
    }
  } else {
    if (tree->right == NULL) {
      tree->right = new_surrealist_binary_tree(value);
    } else {
      insert_surrealist_binary_tree(tree->right, value);
    }
  }
}

// Search for a value in the surrealist binary tree
int search_surrealist_binary_tree(struct surrealist_binary_tree *tree, int value) {
  if (tree == NULL) {
    return 0;
  } else if (tree->value == value) {
    return 1;
  } else if (value < tree->value) {
    return search_surrealist_binary_tree(tree->left, value);
  } else {
    return search_surrealist_binary_tree(tree->right, value);
  }
}

// Print the surrealist binary tree
void print_surrealist_binary_tree(struct surrealist_binary_tree *tree) {
  if (tree == NULL) {
    printf("()");
  } else {
    printf("(%d ", tree->value);
    print_surrealist_binary_tree(tree->left);
    print_surrealist_binary_tree(tree->right);
    printf(")");
  }
}

// Destroy the surrealist binary tree
void destroy_surrealist_binary_tree(struct surrealist_binary_tree *tree) {
  if (tree == NULL) {
    return;
  } else {
    destroy_surrealist_binary_tree(tree->left);
    destroy_surrealist_binary_tree(tree->right);
    free(tree);
  }
}

// The main function
int main() {
  // Create a new surrealist binary tree
  struct surrealist_binary_tree *tree = new_surrealist_binary_tree(10);

  // Insert some values into the surrealist binary tree
  insert_surrealist_binary_tree(tree, 5);
  insert_surrealist_binary_tree(tree, 15);
  insert_surrealist_binary_tree(tree, 2);
  insert_surrealist_binary_tree(tree, 7);
  insert_surrealist_binary_tree(tree, 12);
  insert_surrealist_binary_tree(tree, 20);

  // Print the surrealist binary tree
  print_surrealist_binary_tree(tree);

  // Search for a value in the surrealist binary tree
  int value = 15;
  if (search_surrealist_binary_tree(tree, value)) {
    printf("\nThe value %d was found in the surrealist binary tree.\n", value);
  } else {
    printf("\nThe value %d was not found in the surrealist binary tree.\n", value);
  }

  // Destroy the surrealist binary tree
  destroy_surrealist_binary_tree(tree);

  return 0;
}