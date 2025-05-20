//FormAI DATASET v1.0 Category: Binary search trees ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Define a node struct for the binary tree
struct node {
  int data;
  struct node* left;
  struct node* right;
};

// Function to create a new node with a given value
struct node* newNode(int data) {
  struct node* node = (struct node*) malloc(sizeof(struct node));

  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

// Function to insert a new node with a given value into the binary tree
struct node* insert(struct node* node, int data) {
  // If the tree is empty, create a new node with the given value
  if (node == NULL) return newNode(data);

  // Otherwise, recursively insert the node into the appropriate subtree
  if (data < node->data)
    node->left = insert(node->left, data);
  else if (data > node->data)
    node->right = insert(node->right, data);

  // Return the updated root node of the tree
  return node;
}

// Function to perform an in-order traversal of the binary tree
void inorderTraversal(struct node* node) {
  if (node == NULL) return;
  inorderTraversal(node->left);
  printf("%d ", node->data);
  inorderTraversal(node->right);
}

// Function to perform a pre-order traversal of the binary tree
void preorderTraversal(struct node* node) {
  if (node == NULL) return;
  printf("%d ", node->data);
  preorderTraversal(node->left);
  preorderTraversal(node->right);
}

// Function to perform a post-order traversal of the binary tree
void postorderTraversal(struct node* node) {
  if (node == NULL) return;
  postorderTraversal(node->left);
  postorderTraversal(node->right);
  printf("%d ", node->data);
}

// Function to search for a value in the binary tree
struct node* search(struct node* node, int data) {
  // If the tree is empty or the node with the given value is found, return the node
  if (node == NULL || node->data == data) return node;

  // Otherwise, recursively search the appropriate subtree
  if (data < node->data)
    return search(node->left, data);
  else
    return search(node->right, data);
}

// Main function to test the binary tree implementation
int main() {
  // Create an empty binary tree
  struct node* root = NULL;

  // Insert some nodes into the binary tree
  root = insert(root, 10);
  insert(root, 7);
  insert(root, 20);
  insert(root, 5);
  insert(root, 9);
  insert(root, 15);
  insert(root, 25);

  // Print out the binary tree using in-order, pre-order, and post-order traversals
  printf("In-order traversal: ");
  inorderTraversal(root);
  printf("\n");

  printf("Pre-order traversal: ");
  preorderTraversal(root);
  printf("\n");

  printf("Post-order traversal: ");
  postorderTraversal(root);
  printf("\n");

  // Search for some values in the binary tree
  struct node* nodeToFind = search(root, 15);
  if (nodeToFind != NULL)
    printf("Found node with value %d\n", nodeToFind->data);
  else
    printf("Could not find node with value 15\n");

  nodeToFind = search(root, 30);
  if (nodeToFind != NULL)
    printf("Found node with value %d\n", nodeToFind->data);
  else
    printf("Could not find node with value 30\n");

  return 0;
}