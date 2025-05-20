//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// The super cool and totally awesome binary tree node
typedef struct BinaryTreeNode {
  int value;
  struct BinaryTreeNode *left;
  struct BinaryTreeNode *right;
} BinaryTreeNode;

// Insert a value into the binary tree
BinaryTreeNode* insert(BinaryTreeNode *root, int value) {
  if (root == NULL) {
    root = malloc(sizeof(BinaryTreeNode));
    root->value = value;
    root->left = root->right = NULL;
  } else if (value < root->value) {
    root->left = insert(root->left, value);
  } else {
    root->right = insert(root->right, value);
  }

  return root;
}

// Search for a value in the binary tree
BinaryTreeNode* search(BinaryTreeNode *root, int value) {
  if (root == NULL || root->value == value) {
    return root;
  } else if (value < root->value) {
    return search(root->left, value);
  } else {
    return search(root->right, value);
  }
}

// Find the minimum value in the binary tree
BinaryTreeNode* findMin(BinaryTreeNode *root) {
  if (root->left == NULL) {
    return root;
  } else {
    return findMin(root->left);
  }
}

// Find the maximum value in the binary tree
BinaryTreeNode* findMax(BinaryTreeNode *root) {
  if (root->right == NULL) {
    return root;
  } else {
    return findMax(root->right);
  }
}

// Free the memory allocated for the binary tree
void freeTree(BinaryTreeNode *root) {
  if (root != NULL) {
    freeTree(root->left);
    freeTree(root->right);
    free(root);
  }
}

// Print the binary tree in preorder traversal
void printPreorder(BinaryTreeNode *root) {
  if (root != NULL) {
    printf("%d ", root->value);
    printPreorder(root->left);
    printPreorder(root->right);
  }
}

// Print the binary tree in inorder traversal
void printInorder(BinaryTreeNode *root) {
  if (root != NULL) {
    printInorder(root->left);
    printf("%d ", root->value);
    printInorder(root->right);
  }
}

// Print the binary tree in postorder traversal
void printPostorder(BinaryTreeNode *root) {
  if (root != NULL) {
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->value);
  }
}

int main() {
  // Let's create a binary tree with some awesome values!
  BinaryTreeNode *root = NULL;
  root = insert(root, 10);
  root = insert(root, 5);
  root = insert(root, 15);
  root = insert(root, 3);
  root = insert(root, 7);
  root = insert(root, 12);
  root = insert(root, 20);

  // Now, let's search for the value 15 in the tree
  BinaryTreeNode *node = search(root, 15);
  if (node != NULL) {
    printf("Yay! We found the value %d in the binary tree.\n", node->value);
  } else {
    printf("Aww, we couldn't find the value 15 in the binary tree.\n");
  }

  // Let's find the minimum and maximum values in the tree
  BinaryTreeNode *minNode = findMin(root);
  BinaryTreeNode *maxNode = findMax(root);
  printf("The minimum value in the binary tree is %d.\n", minNode->value);
  printf("The maximum value in the binary tree is %d.\n", maxNode->value);

  // Finally, let's print the binary tree in all three traversals
  printf("Preorder traversal: ");
  printPreorder(root);
  printf("\n");

  printf("Inorder traversal: ");
  printInorder(root);
  printf("\n");

  printf("Postorder traversal: ");
  printPostorder(root);
  printf("\n");

  // Don't forget to clean up after ourselves and free the memory allocated for the binary tree
  freeTree(root);

  return 0;
}