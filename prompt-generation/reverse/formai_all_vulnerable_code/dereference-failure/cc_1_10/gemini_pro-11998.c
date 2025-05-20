//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VAL 10000000  // Maximum value for random number generation
#define NODES 10000        // Number of nodes in the tree

// Node structure for the binary search tree
typedef struct node {
  int data;
  struct node *left, *right;
} Node;

// Function to create a new node with the given data
Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Function to insert a new node with the given data into the binary search tree
Node *insert_node(Node *root, int data) {
  if (root == NULL) {  // If the tree is empty, create a new node and make it the root
    return create_node(data);
  } else if (data < root->data) {  // If the data is less than the root's data, insert it into the left subtree
    root->left = insert_node(root->left, data);
  } else if (data > root->data) {  // If the data is greater than the root's data, insert it into the right subtree
    root->right = insert_node(root->right, data);
  }
  return root;
}

// Function to search for a node with the given data in the binary search tree
Node *search_node(Node *root, int data) {
  if (root == NULL) {  // If the tree is empty, return NULL
    return NULL;
  } else if (data < root->data) {  // If the data is less than the root's data, search for it in the left subtree
    return search_node(root->left, data);
  } else if (data > root->data) {  // If the data is greater than the root's data, search for it in the right subtree
    return search_node(root->right, data);
  } else {  // If the data is equal to the root's data, return the root
    return root;
  }
}

// Function to print the binary search tree in order
void print_tree(Node *root) {
  if (root == NULL) {  // If the tree is empty, return
    return;
  }

  print_tree(root->left);  // Print the left subtree
  printf("%d ", root->data);  // Print the root's data
  print_tree(root->right);  // Print the right subtree
}

// Function to free the memory allocated for the binary search tree
void free_tree(Node *root) {
  if (root == NULL) {  // If the tree is empty, return
    return;
  }

  free_tree(root->left);  // Free the left subtree
  free_tree(root->right);  // Free the right subtree
  free(root);        // Free the root
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create the root node with a random value
  Node *root = create_node(rand() % MAX_VAL);

  // Insert nodes with random values into the tree
  for (int i = 0; i < NODES; i++) {
    int data = rand() % MAX_VAL;
    insert_node(root, data);
  }

  // Print the binary search tree in order
  print_tree(root);

  // Search for a node with a random value in the tree
  int search_val = rand() % MAX_VAL;
  Node *found_node = search_node(root, search_val);
  if (found_node == NULL) {
    printf("\nValue %d not found in the tree.\n", search_val);
  } else {
    printf("\nValue %d found in the tree.\n", search_val);
  }

  // Free the memory allocated for the binary search tree
  free_tree(root);

  return 0;
}