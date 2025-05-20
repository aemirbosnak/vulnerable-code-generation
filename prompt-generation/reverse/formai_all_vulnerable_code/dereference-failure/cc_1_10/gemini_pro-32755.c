//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: genius
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
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

// A utility function to insert a new node with the given key
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

// Finding the minimum element in a binary tree
struct Node* findMin(struct Node* node) {
  if (node == NULL) return NULL;
  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}

// Finding the maximum element in a binary tree
struct Node* findMax(struct Node* node) {
  if (node == NULL) return NULL;
  while (node->right != NULL) {
    node = node->right;
  }
  return node;
}

// Searching for a key in a binary tree
struct Node* search(struct Node* node, int key) {
  if (node == NULL) return NULL;
  if (node->data == key) return node;
  if (key < node->data)
    return search(node->left, key);
  else
    return search(node->right, key);
}

// A utility function to inorder traversal of a binary tree
void inorder(struct Node* node) {
  if (node == NULL) return;
  inorder(node->left);
  printf("%d ", node->data);
  inorder(node->right);
}

// A utility function to preorder traversal of a binary tree
void preorder(struct Node* node) {
  if (node == NULL) return;
  printf("%d ", node->data);
  preorder(node->left);
  preorder(node->right);
}

// A utility function to postorder traversal of a binary tree
void postorder(struct Node* node) {
  if (node == NULL) return;
  postorder(node->left);
  postorder(node->right);
  printf("%d ", node->data);
}

// Deleting a node from a binary tree
struct Node* delete(struct Node* node, int key) {
  if (node == NULL) return NULL;
  if (key < node->data)
    node->left = delete(node->left, key);
  else if (key > node->data)
    node->right = delete(node->right, key);
  else {
    if (node->left == NULL) {
      struct Node* temp = node->right;
      free(node);
      return temp;
    } else if (node->right == NULL) {
      struct Node* temp = node->left;
      free(node);
      return temp;
    }

    struct Node* temp = findMin(node->right);
    node->data = temp->data;
    node->right = delete(node->right, temp->data);
  }
  return node;
}

// Main function to test the above functions
int main() {
  struct Node* root = NULL;

  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);

  inorder(root);
  printf("\n");
  preorder(root);
  printf("\n");
  postorder(root);
  printf("\n");

  printf("%d is the minimum element\n", findMin(root)->data);
  printf("%d is the maximum element\n", findMax(root)->data);

  struct Node* node = search(root, 40);
  if (node != NULL)
    printf("Key found: %d\n", node->data);
  else
    printf("Key not found\n");

  root = delete(root, 20);
  inorder(root);
  printf("\n");

  return 0;
}