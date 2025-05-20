//FormAI DATASET v1.0 Category: Binary search trees ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

// Function to create a new node
struct Node* newNode(int key) {
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->data = key;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Function to insert a new node in the BST
struct Node* insert(struct Node* node, int key) {
  // If the tree is empty, create a new node
  if (node == NULL) return newNode(key);

  // Otherwise, recur down the tree
  if (key < node->data)
    node->left = insert(node->left, key);
  else if (key > node->data)
    node->right = insert(node->right, key);

  // Return the (unchanged) node pointer
  return node;
}

// Function to find the minimum value in the tree
struct Node* minValueNode(struct Node* node) {
  struct Node* current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int key) {
  // Base case
  if (root == NULL) return root;

  // If the key to be deleted is smaller than the root's key, then it lies in the left subtree
  if (key < root->data)
    root->left = deleteNode(root->left, key);

  // If the key to be deleted is greater than the root's key, then it lies in the right subtree
  else if (key > root->data)
    root->right = deleteNode(root->right, key);

  // If key is same as root's key, then this is the node to be deleted
  else {
    // node with only one child or no child
    if (root->left == NULL) {
      struct Node* temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL) {
      struct Node* temp = root->left;
      free(root);
      return temp;
    }

    // node with two children: Get the inorder successor (smallest in the right subtree)
    struct Node* temp = minValueNode(root->right);

    // Copy the inorder successor's content to this node
    root->data = temp->data;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

// Function to perform inorder traversal of the tree and print the nodes
void inorder(struct Node* root) {
  if (root != NULL) {
    inorder(root->left);
    printf(" %d ", root->data);
    inorder(root->right);
  }
}

// Main function
int main() {
  struct Node* root = NULL;

  // Insert nodes into the tree
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  // Print the inorder traversal of the tree
  printf("Inorder traversal of the tree: ");
  inorder(root);

  // Delete node with key 20
  root = deleteNode(root, 20);

  // Print the inorder traversal of the updated tree
  printf("\nInorder traversal of the updated tree: ");
  inorder(root);

  // Delete node with key 30
  root = deleteNode(root, 30);

  // Print the inorder traversal of the updated tree
  printf("\nInorder traversal of the updated tree: ");
  inorder(root);

  return 0;
}