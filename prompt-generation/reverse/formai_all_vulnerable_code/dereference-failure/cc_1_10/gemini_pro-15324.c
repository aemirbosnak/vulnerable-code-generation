//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: systematic
#include <stdlib.h>
#include <stdio.h>

// A binary tree node
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

// A utility function to create a new Binary Tree node
struct Node *newNode(int data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return (node);
}

// A utility function to do inorder traversal of BST
void inorder(struct Node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

// A utility function to insert a new node with given key in BST
struct Node *insert(struct Node *node, int key) {
  if (node == NULL) return newNode(key);

  if (key < node->data)
    node->left = insert(node->left, key);
  else if (key > node->data)
    node->right = insert(node->right, key);

  return node;
}

// A utility function to find the minimum value in BST
struct Node *minValueNode(struct Node *node) {
  struct Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

// A utility function to delete a given key from BST
struct Node *deleteNode(struct Node *root, int key) {
  if (root == NULL) return root;

  if (key < root->data)
    root->left = deleteNode(root->left, key);
  else if (key > root->data)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      struct Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct Node *temp = root->left;
      free(root);
      return temp;
    }

    struct Node *temp = minValueNode(root->right);

    root->data = temp->data;

    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

// Driver program to test the above functions
int main() {
  // Let us create following BST
  //      50
  //    /    \
  //   30    70
  //  /  \   /  \
  // 20  40  60  80
  struct Node *root = NULL;
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);

  // Print inorder traversal of the BST
  inorder(root);

  printf("\n");

  // Delete 20
  root = deleteNode(root, 20);

  // Print inorder traversal of the BST
  inorder(root);

  printf("\n");

  // Delete 30
  root = deleteNode(root, 30);

  // Print inorder traversal of the BST
  inorder(root);

  printf("\n");

  // Delete 50
  root = deleteNode(root, 50);

  // Print inorder traversal of the BST
  inorder(root);

  printf("\n");

  return 0;
}