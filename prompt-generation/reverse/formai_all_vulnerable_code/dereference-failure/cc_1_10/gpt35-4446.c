//FormAI DATASET v1.0 Category: Binary search trees ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node* left;
  struct node* right;
} node;

node* root = NULL;

/** Insert a node into the binary search tree */
void insert(int value) {
  node* newNode = (node*) malloc(sizeof(node));
  newNode->value = value;
  newNode->left = NULL;
  newNode->right = NULL;

  // If tree is empty, insert as root
  if (root == NULL) {
    root = newNode;
    return;
  }

  // Traverse tree to find correct position to insert node
  node* current = root;
  while (1) {
    if (value < current->value) {
      if (current->left == NULL) {
        current->left = newNode;
        break;
      }
      current = current->left;
    } else {
      if (current->right == NULL) {
        current->right = newNode;
        break;
      }
      current = current->right;
    }
  }
}

/** Recursive function to traverse the tree in order */
void traverseInOrder(node* current) {
  if (current != NULL) {
    traverseInOrder(current->left);
    printf("%d ", current->value);
    traverseInOrder(current->right);
  }
}

int main() {
  // Insert nodes into tree
  insert(50);
  insert(30);
  insert(70);
  insert(20);
  insert(40);
  insert(60);
  insert(80);

  // Traverse tree in order and print node values
  traverseInOrder(root);
  printf("\n");

  return 0;
}