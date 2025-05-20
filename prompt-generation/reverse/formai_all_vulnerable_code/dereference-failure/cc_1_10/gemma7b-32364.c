//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

struct Tree {
  struct Node* root;
  int size;
};

void insert(struct Tree* tree, int data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  if (tree->root == NULL) {
    tree->root = newNode;
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

  tree->size++;
}

void traverse(struct Tree* tree) {
  struct Node* current = tree->root;

  while (current) {
    printf("%d ", current->data);
    traverse(tree);
  }
}

int main() {
  struct Tree* tree = malloc(sizeof(struct Tree));
  tree->root = NULL;
  tree->size = 0;

  insert(tree, 20);
  insert(tree, 10);
  insert(tree, 30);
  insert(tree, 25);
  insert(tree, 15);

  traverse(tree);

  return 0;
}