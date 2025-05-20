//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node_t;

node_t *create_node(int data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
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

node_t *search_node(node_t *root, int data) {
  if (root == NULL) {
    return NULL;
  } else if (root->data == data) {
    return root;
  } else if (data < root->data) {
    return search_node(root->left, data);
  } else {
    return search_node(root->right, data);
  }
}

void print_inorder(node_t *root) {
  if (root != NULL) {
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
  }
}

void print_preorder(node_t *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    print_preorder(root->left);
    print_preorder(root->right);
  }
}

void print_postorder(node_t *root) {
  if (root != NULL) {
    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d ", root->data);
  }
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
  print_inorder(root);
  printf("\n");

  printf("Preorder traversal: ");
  print_preorder(root);
  printf("\n");

  printf("Postorder traversal: ");
  print_postorder(root);
  printf("\n");

  node_t *found_node = search_node(root, 12);
  if (found_node != NULL) {
    printf("Node with data 12 found!\n");
  } else {
    printf("Node with data 12 not found!\n");
  }

  return 0;
}