//FormAI DATASET v1.0 Category: Binary search trees ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Defining the Node structure of the Binary Search Tree
struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

// Function to create and return a new Node
struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Function to insert a new Node into the Binary Search Tree
struct Node* insert(struct Node* root, int data) {
  if (root == NULL) {
    return createNode(data);
  } else if (data <= root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }
  return root;
}

// Function to search for a particular Node in the Binary Search Tree
struct Node* search(struct Node* root, int data) {
  if (root == NULL || root->data == data) {
    return root;
  } else if (data <= root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}

// Function to find the minimum value in the Binary Search Tree
struct Node* findMin(struct Node* root) {
  while (root->left != NULL) {
    root = root->left;
  }
  return root;
}

// Function to delete a Node from the Binary Search Tree
struct Node* delete(struct Node* root, int data) {
  if (root == NULL) {
    return root;
  } else if (data < root->data) {
    root->left = delete(root->left, data);
  } else if (data > root->data) {
    root->right = delete(root->right, data);
  } else {
    // Case 1: No child
    if (root->left == NULL && root->right == NULL) {
      free(root);
      root = NULL;
    }
    // Case 2: One child
    else if (root->left == NULL) {
      struct Node* temp = root;
      root = root->right;
      free(temp);
    } else if (root->right == NULL) {
      struct Node* temp = root;
      root = root->left;
      free(temp);
    }
    // Case 3: Two children
    else {
      struct Node* temp = findMin(root->right);
      root->data = temp->data;
      root->right = delete(root->right, temp->data);
    }
  }
  return root;
}

// Function to traverse the Binary Search Tree in in-order
void traverseInOrder(struct Node* root) {
  if (root == NULL) {
    return;
  }
  traverseInOrder(root->left);
  printf("%d ", root->data);
  traverseInOrder(root->right);
}

// Driver function
int main() {
  struct Node* root = NULL;
  root = insert(root, 15);
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 8);
  root = insert(root, 12);
  root = insert(root, 17);
  root = insert(root, 25);

  printf("In-order traversal of the Binary Search Tree: ");
  traverseInOrder(root);
  printf("\n\n");

  printf("Deleting node with value 12...\n");
  root = delete(root, 12);

  printf("In-order traversal of the Binary Search Tree: ");
  traverseInOrder(root);
  printf("\n\n");

  printf("Searching for node with value 17...\n");
  struct Node* node = search(root, 17);
  if (node != NULL) {
    printf("Node with value 17 found in the Binary Search Tree!\n\n");
  } else {
    printf("Node with value 17 not found in the Binary Search Tree.\n\n");
  }
  return 0;
}