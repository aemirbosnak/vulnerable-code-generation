//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: happy
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node_t;

node_t *create_node(int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node_t *insert_node(node_t *root, int data) {
  if (root == NULL) {
    return create_node(data);
  }
  if (data < root->data) {
    root->left = insert_node(root->left, data);
  } else {
    root->right = insert_node(root->right, data);
  }
  return root;
}

node_t *search_node(node_t *root, int data) {
  if (root == NULL) {
    return NULL;
  }
  if (data == root->data) {
    return root;
  }
  if (data < root->data) {
    return search_node(root->left, data);
  } else {
    return search_node(root->right, data);
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
  int data[] = {10, 5, 15, 2, 7, 12, 20};
  int i;
  for (i = 0; i < 7; i++) {
    root = insert_node(root, data[i]);
  }
  printf("Inorder traversal of the tree: ");
  print_tree(root);
  printf("\n");
  int search_data = 12;
  node_t *found_node = search_node(root, search_data);
  if (found_node != NULL) {
    printf("Node %d found in the tree!\n", found_node->data);
  } else {
    printf("Node %d not found in the tree!\n", search_data);
  }
  free_tree(root);
  return 0;
}