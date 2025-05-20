//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: random
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The creators of this code are not responsible for any damages due to improper use of this software.
// This code is provided "as is" without warranty of any kind.

/*
** Node struct
*/
typedef struct node {
  int value;
  struct node *left;
  struct node *right;
} node;

/*
** Insert a value into a binary search tree
*/
void insert(node **root, int value) {
  if (*root == NULL) {
    *root = (node *)malloc(sizeof(node));
    (*root)->value = value;
    (*root)->left = NULL;
    (*root)->right = NULL;
  } else if (value < (*root)->value) {
    insert(&(*root)->left, value);
  } else if (value > (*root)->value) {
    insert(&(*root)->right, value);
  }
}

/*
** Search for a value in a binary search tree
*/
bool search(node *root, int value) {
  if (root == NULL) {
    return false;
  } else if (root->value == value) {
    return true;
  } else if (value < root->value) {
    return search(root->left, value);
  } else if (value > root->value) {
    return search(root->right, value);
  }
  return false;
}

/*
** Print a binary search tree in order
*/
void print_tree(node *root) {
  if (root == NULL) {
    return;
  }
  print_tree(root->left);
  printf("%d ", root->value);
  print_tree(root->right);
}

/*
** Free the memory allocated for a binary search tree
*/
void free_tree(node *root) {
  if (root == NULL) {
    return;
  }
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}

/*
** Main function
*/
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create a binary search tree
  node *root = NULL;

  // Insert 100 random values into the tree
  for (int i = 0; i < 100; i++) {
    insert(&root, rand() % 100);
  }

  // Print the tree in order
  print_tree(root);
  printf("\n");

  // Search for a value in the tree
  int value = rand() % 100;
  bool found = search(root, value);
  if (found) {
    printf("Found %d in the tree\n", value);
  } else {
    printf("Did not find %d in the tree\n", value);
  }

  // Free the memory allocated for the tree
  free_tree(root);

  return 0;
}