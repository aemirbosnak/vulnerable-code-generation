//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: random
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node_t;

node_t *create_node(int data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  if (new_node == NULL) {
    printf("Error: malloc failed.\n");
    exit(1);
  }
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void insert_node(node_t **root, int data) {
  if (*root == NULL) {
    *root = create_node(data);
  } else if (data < (*root)->data) {
    insert_node(&(*root)->left, data);
  } else {
    insert_node(&(*root)->right, data);
  }
}

node_t *find_node(node_t *root, int data) {
  if (root == NULL) {
    return NULL;
  } else if (root->data == data) {
    return root;
  } else if (data < root->data) {
    return find_node(root->left, data);
  } else {
    return find_node(root->right, data);
  }
}

void print_tree(node_t *root) {
  if (root == NULL) {
    return;
  }
  print_tree(root->left);
  printf("%d ", root->data);
  print_tree(root->right);
}

int main() {
  node_t *root = NULL;
  int i;

  for (i = 0; i < 10; i++) {
    insert_node(&root, i);
  }

  printf("Inorder traversal: ");
  print_tree(root);
  printf("\n");

  node_t *found_node = find_node(root, 5);
  if (found_node != NULL) {
    printf("Found node with data: %d\n", found_node->data);
  } else {
    printf("Node not found.\n");
  }

  return 0;
}