//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// A binary tree node
struct node {
  int data;
  struct node *left;
  struct node *right;
};

// A utility function to create a new Binary Tree node
struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return (node);
}

// A utility function to insert a new node with the given key in BST
struct node *insert(struct node *node, int key) {
  if (node == NULL) return newNode(key);
  if (key < node->data)
    node->left = insert(node->left, key);
  else if (key > node->data)
    node->right = insert(node->right, key);
  return node;
}

// A utility function to search a given key in BST
struct node *search(struct node *node, int key) {
  if (node == NULL) return NULL;
  if (key == node->data)
    return node;
  if (key < node->data)
    return search(node->left, key);
  else
    return search(node->right, key);
}

// A utility function to find the inorder successor of a given node
struct node *minValueNode(struct node *node) {
  struct node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

// A utility function to delete a given key from BST
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) return root;
  if (key < root->data)
    root->left = deleteNode(root->left, key);
  else if (key > root->data)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    struct node *temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

// A utility function to print the inorder traversal of BST
void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

// Driver program to test the above functions
int main() {
  struct node *root = NULL;
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);
  printf("Inorder traversal of the given BST: ");
  inorder(root);
  printf("\n");
  printf("Searching for 40 in BST: ");
  struct node *found = search(root, 40);
  if (found != NULL)
    printf("Found %d in BST\n", found->data);
  else
    printf("40 not found in BST\n");
  printf("Deleting 20 from BST: ");
  root = deleteNode(root, 20);
  printf("Inorder traversal of the modified BST: ");
  inorder(root);
  printf("\n");
  return 0;
}