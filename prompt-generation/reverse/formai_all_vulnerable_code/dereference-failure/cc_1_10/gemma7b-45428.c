//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

struct Tree {
  struct Node* root;
};

struct Tree* insert(struct Tree* tree, int data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  if (tree == NULL) {
    tree = newNode;
  } else {
    struct Node* current = tree->root;
    struct Node* parent = NULL;

    while (current) {
      if (data < current->data) {
        parent = current;
        current = current->left;
      } else {
        parent = current;
        current = current->right;
      }
    }

    if (parent) {
      if (parent->left == NULL) {
        parent->left = newNode;
      } else {
        parent->right = newNode;
      }
    }
  }

  return tree;
}

int main() {
  struct Tree* tree = NULL;

  insert(tree, 5);
  insert(tree, 3);
  insert(tree, 8);
  insert(tree, 2);
  insert(tree, 4);
  insert(tree, 7);

  struct Node* current = tree->root;

  while (current) {
    printf("%d ", current->data);
    current = current->left;
  }

  return 0;
}