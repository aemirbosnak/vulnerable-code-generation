//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node_t;

node_t *create_node(int data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  if (new_node == NULL) {
    fprintf(stderr, "Error: could not allocate memory for new node\n");
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
    return;
  }
  if (data < (*root)->data) {
    insert_node(&(*root)->left, data);
  } else if (data > (*root)->data) {
    insert_node(&(*root)->right, data);
  }
}

bool search_node(node_t *root, int data) {
  if (root == NULL) {
    return false;
  }
  if (root->data == data) {
    return true;
  }
  if (data < root->data) {
    return search_node(root->left, data);
  } else if (data > root->data) {
    return search_node(root->right, data);
  }
  return false;
}

void print_tree(node_t *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  print_tree(root->left);
  print_tree(root->right);
}

void free_tree(node_t *root) {
  if (root == NULL) {
    return;
  }
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}

int main() {
  node_t *root = NULL;
  insert_node(&root, 10);
  insert_node(&root, 5);
  insert_node(&root, 15);
  insert_node(&root, 2);
  insert_node(&root, 7);
  insert_node(&root, 12);
  insert_node(&root, 20);
  printf("Inorder traversal: ");
  print_tree(root);
  printf("\n");
  printf("Search for 15: %s\n", search_node(root, 15) ? "true" : "false");
  printf("Search for 17: %s\n", search_node(root, 17) ? "true" : "false");
  free_tree(root);
  return 0;
}