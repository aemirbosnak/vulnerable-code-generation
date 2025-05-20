//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// A node in our binary search tree
typedef struct Node {
  int value;
  struct Node *left;
  struct Node *right;
} Node;

// Our trusty binary search tree
Node *tree = NULL;

// Insert a new node into the tree
void insert(int value) {
  Node *new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;

  if (tree == NULL) {
    tree = new_node;
    return;
  }

  Node *current = tree;
  while (1) {
    if (value < current->value) {
      if (current->left == NULL) {
        current->left = new_node;
        return;
      } else {
        current = current->left;
      }
    } else {
      if (current->right == NULL) {
        current->right = new_node;
        return;
      } else {
        current = current->right;
      }
    }
  }
}

// Recursively search for a value in the tree
int search(int value) {
  if (tree == NULL) {
    return 0;
  }

  Node *current = tree;
  while (1) {
    if (value == current->value) {
      return 1;
    } else if (value < current->value) {
      if (current->left == NULL) {
        return 0;
      } else {
        current = current->left;
      }
    } else {
      if (current->right == NULL) {
        return 0;
      } else {
        current = current->right;
      }
    }
  }
}

int main() {
  // Insert some data into the tree
  insert(10);
  insert(5);
  insert(15);
  insert(2);
  insert(7);
  insert(12);
  insert(20);

  // Search for some values
  printf("Searching for 10: %s\n", search(10) ? "Found" : "Not found");
  printf("Searching for 17: %s\n", search(17) ? "Found" : "Not found");

  return 0;
}