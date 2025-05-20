//GEMINI-pro DATASET v1.0 Category: Educational ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the structure of a node in the binary tree
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

// Create a new node with the given data
node* create_node(int data) {
  node *new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Insert a new node into the binary tree
void insert_node(node **root, int data) {
  if (*root == NULL) {
    *root = create_node(data);
  } else if (data < (*root)->data) {
    insert_node(&(*root)->left, data);
  } else {
    insert_node(&(*root)->right, data);
  }
}

// Find the minimum value in the binary tree
node* find_min(node *root) {
  if (root == NULL) {
    return NULL;
  } else if (root->left == NULL) {
    return root;
  } else {
    return find_min(root->left);
  }
}

// Find the maximum value in the binary tree
node* find_max(node *root) {
  if (root == NULL) {
    return NULL;
  } else if (root->right == NULL) {
    return root;
  } else {
    return find_max(root->right);
  }
}

// Delete a node from the binary tree
void delete_node(node **root, int data) {
  if (*root == NULL) {
    return;
  } else if (data < (*root)->data) {
    delete_node(&(*root)->left, data);
  } else if (data > (*root)->data) {
    delete_node(&(*root)->right, data);
  } else {
    if ((*root)->left == NULL) {
      node *temp = *root;
      *root = (*root)->right;
      free(temp);
    } else if ((*root)->right == NULL) {
      node *temp = *root;
      *root = (*root)->left;
      free(temp);
    } else {
      node *temp = find_min((*root)->right);
      (*root)->data = temp->data;
      delete_node(&(*root)->right, temp->data);
    }
  }
}

// Print the binary tree in order
void print_tree(node *root) {
  if (root == NULL) {
    return;
  } else {
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
  }
}

// Free the memory allocated for the binary tree
void free_tree(node *root) {
  if (root == NULL) {
    return;
  } else {
    free_tree(root->left);
    free_tree(root->right);
    free(root);
  }
}

int main() {
  // Create a binary tree
  node *root = NULL;
  insert_node(&root, 10);
  insert_node(&root, 5);
  insert_node(&root, 15);
  insert_node(&root, 2);
  insert_node(&root, 7);
  insert_node(&root, 12);
  insert_node(&root, 20);

  // Print the binary tree in order
  printf("Binary tree in order: ");
  print_tree(root);
  printf("\n");

  // Find the minimum value in the binary tree
  node *min_node = find_min(root);
  printf("Minimum value in the binary tree: %d\n", min_node->data);

  // Find the maximum value in the binary tree
  node *max_node = find_max(root);
  printf("Maximum value in the binary tree: %d\n", max_node->data);

  // Delete a node from the binary tree
  delete_node(&root, 10);

  // Print the binary tree in order
  printf("Binary tree in order after deleting 10: ");
  print_tree(root);
  printf("\n");

  // Free the memory allocated for the binary tree
  free_tree(root);

  return 0;
}