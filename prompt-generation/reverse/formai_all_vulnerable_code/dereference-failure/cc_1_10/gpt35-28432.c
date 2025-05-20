//FormAI DATASET v1.0 Category: Binary search trees ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the binary search tree node
struct node {
  int data;
  struct node* left;
  struct node* right;
};

// Function to create a new node with given data
struct node* newNode(int data) {
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Function to insert a new node into the binary search tree
struct node* insert(struct node* node, int data) {
  if (node == NULL) {
    return newNode(data);
  }
  if (data < node->data) {
    node->left = insert(node->left, data);
  }
  else if (data > node->data) {
    node->right = insert(node->right, data);
  }
  return node;
}

// Function to do an in-order traversal of the binary search tree
void inorder(struct node* node) {
  if (node != NULL) {
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
  }
}

// Function to find the minimum value in the binary search tree
struct node* minValueNode(struct node* node) {
  struct node* current = node;
  while (current->left != NULL) {
    current = current->left;
  }
  return current;
}

// Function to delete a node from the binary search tree
struct node* deleteNode(struct node* root, int key) {
  if (root == NULL) {
    return root;
  }
  if (key < root->data) {
    root->left = deleteNode(root->left, key);
  }
  else if (key > root->data) {
    root->right = deleteNode(root->right, key);
  }
  else {
    if (root->left == NULL) {
      struct node* temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL) {
      struct node* temp = root->left;
      free(root);
      return temp;
    }
    struct node* temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

int main() {
  struct node* root = NULL;

  // Insert some nodes into the binary search tree
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  printf("Inorder traversal of the binary search tree: ");
  inorder(root);

  printf("\nDelete 20\n");
  root = deleteNode(root, 20);
  printf("Inorder traversal of the binary search tree after deleting 20: ");
  inorder(root);

  printf("\nDelete 30\n");
  root = deleteNode(root, 30);
  printf("Inorder traversal of the binary search tree after deleting 30: ");
  inorder(root);

  printf("\nDelete 50\n");
  root = deleteNode(root, 50);
  printf("Inorder traversal of the binary search tree after deleting 50: ");
  inorder(root);

  return 0;
}