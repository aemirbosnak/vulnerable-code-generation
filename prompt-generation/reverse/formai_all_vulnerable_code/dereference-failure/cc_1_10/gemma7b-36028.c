//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char data;
  struct Node* next;
} Node;

typedef struct Tree {
  Node* root;
  struct Tree* left;
  struct Tree* right;
} Tree;

void insert(Tree* tree, char data) {
  if (tree == NULL) {
    tree = malloc(sizeof(Tree));
    tree->root = malloc(sizeof(Node));
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

void traverse(Tree* tree) {
  if (tree) {
    traverse(tree->left);
    printf("%c ", tree->root->data);
    traverse(tree->right);
  }
}

int main() {
  Tree* tree = NULL;
  insert(tree, 'a');
  insert(tree, 'b');
  insert(tree, 'c');
  insert(tree, 'd');
  insert(tree, 'e');

  traverse(tree);

  return 0;
}