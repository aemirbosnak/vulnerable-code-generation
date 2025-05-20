//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// A binary search tree node
struct BSTNode {
  int data;
  struct BSTNode *left;
  struct BSTNode *right;
};

// Create a new binary search tree node
struct BSTNode *createBSTNode(int data) {
  struct BSTNode *newNode = (struct BSTNode *)malloc(sizeof(struct BSTNode));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Insert a new node into a binary search tree
struct BSTNode *insert(struct BSTNode *root, int data) {
  if (root == NULL) {  // Tree is empty
    return createBSTNode(data);
  } else if (data < root->data) {  // Data is less than root's data
    root->left = insert(root->left, data);
  } else {  // Data is greater than or equal to root's data
    root->right = insert(root->right, data);
  }
  return root;
}

// Search for a node in a binary search tree
struct BSTNode *search(struct BSTNode *root, int data) {
  if (root == NULL) {  // Tree is empty
    return NULL;
  } else if (data == root->data) {  // Data is equal to root's data
    return root;
  } else if (data < root->data) {  // Data is less than root's data
    return search(root->left, data);
  } else {  // Data is greater than root's data
    return search(root->right, data);
  }
}

// Find the minimum value in a binary search tree
struct BSTNode *findMin(struct BSTNode *root) {
  if (root == NULL) {  // Tree is empty
    return NULL;
  } else if (root->left == NULL) {  // Root is the minimum value
    return root;
  } else {  // Minimum value is in the left subtree
    return findMin(root->left);
  }
}

// Find the maximum value in a binary search tree
struct BSTNode *findMax(struct BSTNode *root) {
  if (root == NULL) {  // Tree is empty
    return NULL;
  } else if (root->right == NULL) {  // Root is the maximum value
    return root;
  } else {  // Maximum value is in the right subtree
    return findMax(root->right);
  }
}

// Delete a node from a binary search tree
struct BSTNode *delete(struct BSTNode *root, int data) {
  if (root == NULL) {  // Tree is empty
    return NULL;
  } else if (data < root->data) {  // Data is less than root's data
    root->left = delete(root->left, data);
  } else if (data > root->data) {  // Data is greater than root's data
    root->right = delete(root->right, data);
  } else {  // Data is equal to root's data
    if (root->left == NULL) {  // Root has no left child
      struct BSTNode *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {  // Root has no right child
      struct BSTNode *temp = root->left;
      free(root);
      return temp;
    } else {  // Root has both left and right children
      struct BSTNode *temp = findMin(root->right);  // Find the minimum value in the right subtree
      root->data = temp->data;  // Replace root's data with the minimum value from the right subtree
      root->right = delete(
          root->right, temp->data);  // Delete the minimum value from the right subtree
    }
  }
  return root;
}

// Print a binary search tree in preorder traversal
void preorder(struct BSTNode *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

// Print a binary search tree in inorder traversal
void inorder(struct BSTNode *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

// Print a binary search tree in postorder traversal
void postorder(struct BSTNode *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

// Main function
int main() {
  // Create a binary search tree
  struct BSTNode *root = NULL;
  root = insert(root, 10);
  root = insert(root, 5);
  root = insert(root, 15);
  root = insert(root, 2);
  root = insert(root, 7);
  root = insert(root, 12);
  root = insert(root, 20);

  // Search for a value in the binary search tree
  struct BSTNode *foundNode = search(root, 15);
  if (foundNode != NULL) {
    printf("Value found in the binary search tree: %d\n", foundNode->data);
  } else {
    printf("Value not found in the binary search tree.\n");
  }

  // Find the minimum value in the binary search tree
  struct BSTNode *minNode = findMin(root);
  if (minNode != NULL) {
    printf("Minimum value in the binary search tree: %d\n", minNode->data);
  }

  // Find the maximum value in the binary search tree
  struct BSTNode *maxNode = findMax(root);
  if (maxNode != NULL) {
    printf("Maximum value in the binary search tree: %d\n", maxNode->data);
  }

  // Delete a value from the binary search tree
  root = delete(root, 15);
  printf("Deleted the value 15 from the binary search tree.\n");

  // Print the binary search tree in preorder traversal
  printf("Preorder traversal of the binary search tree: ");
  preorder(root);
  printf("\n");

  // Print the binary search tree in inorder traversal
  printf("Inorder traversal of the binary search tree: ");
  inorder(root);
  printf("\n");

  // Print the binary search tree in postorder traversal
  printf("Postorder traversal of the binary search tree: ");
  postorder(root);
  printf("\n");

  return 0;
}