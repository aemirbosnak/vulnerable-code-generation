//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: curious
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *left;
  struct node *right;
};

struct node *create_node(int value) {
  struct node *node = malloc(sizeof(struct node));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void insert_node(struct node **root, int value) {
  if (*root == NULL) {
    *root = create_node(value);
  } else if (value < (*root)->value) {
    insert_node(&(*root)->left, value);
  } else {
    insert_node(&(*root)->right, value);
  }
}

struct node *find_node(struct node *root, int value) {
  if (root == NULL) {
    return NULL;
  } else if (root->value == value) {
    return root;
  } else if (value < root->value) {
    return find_node(root->left, value);
  } else {
    return find_node(root->right, value);
  }
}

int main() {
  struct node *root = NULL;
  insert_node(&root, 10);
  insert_node(&root, 5);
  insert_node(&root, 15);
  insert_node(&root, 2);
  insert_node(&root, 7);
  insert_node(&root, 12);
  insert_node(&root, 20);
  assert(find_node(root, 10) != NULL);
  assert(find_node(root, 5) != NULL);
  assert(find_node(root, 15) != NULL);
  assert(find_node(root, 2) != NULL);
  assert(find_node(root, 7) != NULL);
  assert(find_node(root, 12) != NULL);
  assert(find_node(root, 20) != NULL);
  assert(find_node(root, 1) == NULL);
  assert(find_node(root, 8) == NULL);
  assert(find_node(root, 13) == NULL);
  return 0;
}