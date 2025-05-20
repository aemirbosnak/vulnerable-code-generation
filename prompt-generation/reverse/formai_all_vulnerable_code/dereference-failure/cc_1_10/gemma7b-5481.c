//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char data;
  struct Node* next;
};

struct Tree {
  struct Node* root;
  struct Tree* left;
  struct Tree* right;
};

void insert(struct Tree* tree, char data) {
  if (tree == NULL) {
    tree = (struct Tree*)malloc(sizeof(struct Tree));
    tree->root = (struct Node*)malloc(sizeof(struct Node));
    tree->root->data = data;
    tree->root->next = NULL;
    tree->left = NULL;
    tree->right = NULL;
  } else if (data < tree->root->data) {
    insert(tree->left, data);
  } else {
    insert(tree->right, data);
  }
}

void traverse(struct Tree* tree) {
  if (tree) {
    traverse(tree->left);
    printf("%c ", tree->root->data);
    traverse(tree->right);
  }
}

int main() {
  struct Tree* tree = NULL;
  insert(tree, 5);
  insert(tree, 2);
  insert(tree, 8);
  insert(tree, 3);
  insert(tree, 9);
  insert(tree, 4);
  insert(tree, 6);

  traverse(tree);

  return 0;
}