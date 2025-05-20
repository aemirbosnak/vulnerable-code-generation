//FormAI DATASET v1.0 Category: Binary search trees ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node* left;
  struct Node* right;
};

struct Node* createNewNode(int value) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->value = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

struct Node* Insert(struct Node* root, int value) {
  if (root == NULL) {
    root = createNewNode(value);
    return root;
  }

  if (value < root->value) {
    root->left = Insert(root->left, value);
  } else {
    root->right = Insert(root->right, value);
  }

  return root;
}

void PrintTree(struct Node* root) {
  if (root != NULL) {
    PrintTree(root->left);
    printf("%d ", root->value);
    PrintTree(root->right);
  }
}

struct Node* Search(struct Node* root, int value) {
  if (root == NULL) {
    return NULL;
  }
  if (root->value == value) {
    return root;
  }
  if (value < root->value) {
    return Search(root->left, value);
  }
  return Search(root->right, value);
}

int main() {
  struct Node* root = NULL;

  root = Insert(root, 4);
  root = Insert(root, 2);
  root = Insert(root, 6);
  root = Insert(root, 1);
  root = Insert(root, 3);
  root = Insert(root, 5);
  root = Insert(root, 7);

  printf("Binary Tree: ");
  PrintTree(root);
  printf("\n");

  printf("Search for value 5: ");
  struct Node* searchResult = Search(root, 5);
  if (searchResult == NULL) {
    printf("Not found\n");
  } else {
    printf("Found! Value: %d\n", searchResult->value);
  }
}