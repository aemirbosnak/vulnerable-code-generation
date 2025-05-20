//FormAI DATASET v1.0 Category: Binary search trees ; Style: careful
#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *root = NULL;

struct node *createNode(int value) {
  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void insertNode(struct node *rootNode, int value) {
  if (root == NULL) {
    root = createNode(value);
  } else if (value < rootNode->data) {
    if (rootNode->left == NULL) {
      rootNode->left = createNode(value);
    } else {
      insertNode(rootNode->left, value);
    }
  } else {
    if (rootNode->right == NULL) {
      rootNode->right = createNode(value);
    } else {
      insertNode(rootNode->right, value);
    }
  }
}

void inorderTraversal(struct node *rootNode) {
  if (rootNode == NULL) {
    return;
  }
  inorderTraversal(rootNode->left);
  printf("%d ", rootNode->data);
  inorderTraversal(rootNode->right);
}

struct node *searchNode(struct node *rootNode, int value) {
  if (rootNode == NULL) {
    return NULL;
  } else if (rootNode->data == value) {
    return rootNode;
  } else if (rootNode->data > value) {
    return searchNode(rootNode->left, value);
  } else {
    return searchNode(rootNode->right, value);
  }
}

int main() {
  insertNode(root, 15);
  insertNode(root, 10);
  insertNode(root, 20);
  insertNode(root, 25);
  insertNode(root, 8);
  insertNode(root, 12);
  printf("The binary search tree is:\n");
  inorderTraversal(root);
  printf("\n");
  struct node *searchNodeResult = searchNode(root, 25);
  if (searchNodeResult == NULL) {
    printf("Node not found\n");
  } else {
    printf("Node found with value %d\n", searchNodeResult->data);
  }
  return 0;
}