//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: funny
// A Binary Search Trees extravaganza!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A tree node, the basic building block of our forest
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

// Insert a new node into the tree, keeping it sorted
node *insert(node *root, int data) {
  if (root == NULL) {
    root = malloc(sizeof(node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
  } else if (data <= root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }
  return root;
}

// Search for a value in the tree, like a treasure hunt!
int search(node *root, int data) {
  if (root == NULL) {
    return 0;  // Treasure not found!
  } else if (root->data == data) {
    return 1;  // A-ha! We found it!
  } else if (data <= root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}

// Print the tree in all its glory
void print_tree(node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    print_tree(root->left);
    print_tree(root->right);
  }
}

// Free the tree, because we don't want to leave our forest cluttered
void free_tree(node *root) {
  if (root != NULL) {
    free_tree(root->left);
    free_tree(root->right);
    free(root);
  }
}

// The main event, where the magic happens!
int main() {
  // Create a brand new, shiny tree
  node *root = NULL;

  // Insert some fun numbers into our tree
  insert(root, 10);
  insert(root, 5);
  insert(root, 15);
  insert(root, 3);
  insert(root, 7);
  insert(root, 12);
  insert(root, 18);

  // Let's go on a treasure hunt and search for a value
  int value_to_find = 12;
  if (search(root, value_to_find)) {
    printf("Eureka! We found %d in the tree!\n", value_to_find);
  } else {
    printf("D'oh! %d is not in this tree.\n", value_to_find);
  }

  // Time to admire our masterpiece
  printf("Our beautiful tree: ");
  print_tree(root);
  printf("\n");

  // And finally, let's clean up our forest
  free_tree(root);

  return 0;
}