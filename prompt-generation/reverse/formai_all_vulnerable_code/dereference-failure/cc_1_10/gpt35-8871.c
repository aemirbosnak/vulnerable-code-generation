//FormAI DATASET v1.0 Category: Binary search trees ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Define the node struct for the binary search tree
typedef struct Node {
  int value;
  struct Node* left;
  struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int val) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->value = val;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Function to insert a new node into the binary search tree
Node* insertNode(Node* root, int val) {
  if (root == NULL) {
    root = createNode(val);
  } else if (val < root->value) {
    root->left = insertNode(root->left, val);
  } else if (val > root->value) {
    root->right = insertNode(root->right, val);
  } else {
    printf("Value already exists in the tree!\n");
  }
  return root;
}

// Function to search for a value in the binary search tree
Node* searchNode(Node* root, int val) {
  if (root == NULL || root->value == val) {
    return root;
  } else if (val < root->value) {
    return searchNode(root->left, val);
  } else {
    return searchNode(root->right, val);
  }
}

// Function to print out the values of the binary search tree in order
void printTree(Node* root) {
  if (root != NULL) {
    printTree(root->left);
    printf("%d ", root->value);
    printTree(root->right);
  }
}

// Driver function to test the binary search tree implementation
int main() {
  Node* root = NULL;

  // Insert some nodes into the tree
  root = insertNode(root, 5);
  root = insertNode(root, 2);
  root = insertNode(root, 7);
  root = insertNode(root, 1);
  root = insertNode(root, 9);

  // Print out the values of the tree
  printf("Values in the tree: ");
  printTree(root);
  printf("\n");

  // Search for a value in the tree and print out the result
  int searchVal = 7;
  Node* result = searchNode(root, searchVal);
  if (result != NULL) {
    printf("Found value %d in the tree!\n", searchVal);
  } else {
    printf("Value %d not found in the tree.\n", searchVal);
  }

  // Free the memory used by the tree nodes
  free(root->left->left);
  free(root->left);
  free(root->right);
  free(root->right->right);
  free(root);

  return 0;
}