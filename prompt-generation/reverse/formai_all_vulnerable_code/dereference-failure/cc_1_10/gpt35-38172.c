//FormAI DATASET v1.0 Category: Binary search trees ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the BST node
struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

// Function to create a new BST node
struct Node* newNode(int data) {
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Function to insert a new data into the BST
struct Node* insert(struct Node* node, int data) {
  // If the BST is empty, return a new node
  if (node == NULL) return newNode(data);

  // Otherwise, recur down the tree
  if (data < node->data) node->left = insert(node->left, data);
  else node->right = insert(node->right, data);

  // Return the (unchanged) node pointer
  return node;
}

// Function to search for a data in the BST
struct Node* search(struct Node* root, int data) {
  // Base Cases: root is null or data is present at root
  if (root == NULL || root->data == data)
    return root;

  // data is greater than root's data
  if (root->data < data)
    return search(root->right, data);

  // data is smaller than root's data
  return search(root->left, data);
}

// Function to print the inorder traversal of the BST
void inorder(struct Node* node) {
  if (node == NULL) return;

  inorder(node->left);
  printf("%d ", node->data);
  inorder(node->right);
}

// The main function
int main() {
  printf("Welcome to the Binary Search Tree Program\n");

  // Create the BST and insert some data
  struct Node* root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  // Print the inorder traversal of the BST
  printf("\nThe inorder traversal of the BST is: ");
  inorder(root);

  // Search for a specified data in the BST
  int data_to_search = 40;
  printf("\nSearching for the data %d in the BST...\n", data_to_search);
  struct Node* result = search(root, data_to_search);
  if (result != NULL) printf("Data %d is present in the BST\n", data_to_search);
  else printf("Data %d is not present in the BST\n", data_to_search);

  // Exit the program
  printf("\nThank you for using the Binary Search Tree Program!\n");

  return 0;
}