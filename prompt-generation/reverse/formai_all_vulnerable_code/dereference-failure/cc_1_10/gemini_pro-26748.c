//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// A binary tree node
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

// A utility function to create a new Binary Tree node
struct Node* newNode(int data) {
  struct Node *node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

// A utility function to insert a new node with the given key in BST
struct Node* insert(struct Node* node, int key) {
  /* If the tree is empty, return a new node */
  if (node == NULL) return newNode(key);

  /* Otherwise, recur down the tree */
  if (key < node->data)
    node->left = insert(node->left, key);
  else if (key > node->data)
    node->right = insert(node->right, key);

  /* return the (unchanged) node pointer */
  return node;
}

// A utility function to search a given key in BST
struct Node* search(struct Node* node, int key) {
  /* Base Cases: root is null or key is present at root */
  if (node == NULL || node->data == key)
    return node;

  /* Key is greater than root's key */
  if (node->data < key)
    return search(node->right, key);

  /* Key is smaller than root's key */
  return search(node->left, key);
}

// A utility function to print the preorder traversal of the BST
void preorder(struct Node* node) {
  if (node == NULL) return;

  printf("%d ", node->data);
  preorder(node->left);
  preorder(node->right);
}

// Driver program to test the above functions
int main() {
  struct Node* root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  // Print the preorder traversal of the BST
  preorder(root);

  // Search a key in the BST
  struct Node *node = search(root, 40);
  if (node == NULL)
    printf("\nKey not found in the BST");
  else
    printf("\nKey found in the BST");

  return 0;
}