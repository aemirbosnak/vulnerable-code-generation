//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: detailed
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node in the binary tree.
typedef struct node {
  int32_t data;
  struct node *left;
  struct node *right;
} node_t;

// Create a new node with the given data.
node_t *create_node(int32_t data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Insert a new node into the binary tree.
void insert_node(node_t **root, int32_t data) {
  if (*root == NULL) {
    *root = create_node(data);
    return;
  }
  if (data < (*root)->data) {
    insert_node(&(*root)->left, data);
  } else {
    insert_node(&(*root)->right, data);
  }
}

// Find the minimum value in the binary tree.
int32_t find_min(node_t *root) {
  if (root == NULL) {
    return INT32_MAX;
  }
  while (root->left != NULL) {
    root = root->left;
  }
  return root->data;
}

// Find the maximum value in the binary tree.
int32_t find_max(node_t *root) {
  if (root == NULL) {
    return INT32_MIN;
  }
  while (root->right != NULL) {
    root = root->right;
  }
  return root->data;
}

// Delete a node from the binary tree.
void delete_node(node_t **root, int32_t data) {
  if (*root == NULL) {
    return;
  }
  if (data < (*root)->data) {
    delete_node(&(*root)->left, data);
  } else if (data > (*root)->data) {
    delete_node(&(*root)->right, data);
  } else {
    if ((*root)->left == NULL) {
      node_t *temp = *root;
      *root = (*root)->right;
      free(temp);
    } else if ((*root)->right == NULL) {
      node_t *temp = *root;
      *root = (*root)->left;
      free(temp);
    } else {
      node_t *temp = *root;
      *root = (*root)->left;
      insert_node(root, temp->data);
      free(temp);
    }
  }
}

// Print the binary tree in preorder.
void preorder(node_t *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

// Print the binary tree in inorder.
void inorder(node_t *root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

// Print the binary tree in postorder.
void postorder(node_t *root) {
  if (root == NULL) {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}

// Free the binary tree.
void free_tree(node_t *root) {
  if (root == NULL) {
    return;
  }
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}

// Test the binary tree functions.
int main() {
  // Create a binary tree.
  node_t *root = NULL;
  insert_node(&root, 50);
  insert_node(&root, 30);
  insert_node(&root, 20);
  insert_node(&root, 40);
  insert_node(&root, 70);
  insert_node(&root, 60);
  insert_node(&root, 80);

  // Print the binary tree in preorder.
  printf("Preorder: ");
  preorder(root);
  printf("\n");

  // Print the binary tree in inorder.
  printf("Inorder: ");
  inorder(root);
  printf("\n");

  // Print the binary tree in postorder.
  printf("Postorder: ");
  postorder(root);
  printf("\n");

  // Find the minimum value in the binary tree.
  printf("Minimum value: %d\n", find_min(root));

  // Find the maximum value in the binary tree.
  printf("Maximum value: %d\n", find_max(root));

  // Delete a node from the binary tree.
  delete_node(&root, 40);

  // Print the binary tree in preorder.
  printf("Preorder: ");
  preorder(root);
  printf("\n");

  // Free the binary tree.
  free_tree(root);

  return 0;
}