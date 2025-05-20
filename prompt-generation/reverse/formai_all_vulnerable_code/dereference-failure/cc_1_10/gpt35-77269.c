//FormAI DATASET v1.0 Category: Binary search trees ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Initialize a node in the binary search tree
struct node {
  int key;
  struct node *left, *right;
};

struct node* createNode(int value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode -> key = value;
  newNode -> left = NULL;
  newNode -> right = NULL;
  return newNode;
}

// Insert a node into the binary search tree
struct node* insert(struct node* node, int key) {
  if (node == NULL) return createNode(key);

  if (key < node -> key) {
    node -> left = insert(node -> left, key);
  } else if (key > node -> key) {
    node -> right = insert(node -> right, key);
  }

  return node;
}

// Search for a node in the binary search tree
struct node* search(struct node* root, int key) {
  if (root == NULL || root -> key == key) {
    return root;
  }
  if (root -> key < key) {
    return search(root -> right, key);
  }
  return search(root -> left, key);
}

// Traverse the binary search tree in order
void inOrderTraversal(struct node* root) {
  if (root != NULL) {
    inOrderTraversal(root -> left);
    printf("%d \n", root -> key);
    inOrderTraversal(root -> right);
  }
}

int main() {
  struct node* root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  printf("In order traversal: \n");
  inOrderTraversal(root);

  int key = 40;
  if (search(root, key)) {
    printf("%d found in binary search tree\n", key);
  } else {
    printf("%d not found in binary search tree\n", key);
  }

  return 0;
}