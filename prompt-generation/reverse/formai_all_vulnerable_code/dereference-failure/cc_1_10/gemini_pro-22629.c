//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Node structure for a binary search tree
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node_t;

// Function to create a new node with the given data
node_t *new_node(int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Function to insert a new node into a binary search tree
node_t *insert(node_t *root, int data) {
  if (root == NULL) {
    return new_node(data);
  } else if (data < root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }
  return root;
}

// Function to search for a node in a binary search tree
node_t *search(node_t *root, int data) {
  if (root == NULL || root->data == data) {
    return root;
  } else if (data < root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}

// Function to delete a node from a binary search tree
node_t *delete(node_t *root, int data) {
  if (root == NULL) {
    return NULL;
  } else if (data < root->data) {
    root->left = delete(root->left, data);
  } else if (data > root->data) {
    root->right = delete(root->right, data);
  } else {
    // Node to be deleted has no children
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    }
    // Node to be deleted has only one child
    else if (root->left == NULL) {
      node_t *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      node_t *temp = root->left;
      free(root);
      return temp;
    }
    // Node to be deleted has two children
    else {
      // Find the smallest node in the right subtree
      node_t *temp = root->right;
      while (temp->left != NULL) {
        temp = temp->left;
      }
      // Copy the data from the smallest node to the node to be deleted
      root->data = temp->data;
      // Delete the smallest node from the right subtree
      root->right = delete(root->right, temp->data);
    }
  }
  return root;
}

// Function to print a binary search tree in order
void print_inorder(node_t *root) {
  if (root == NULL) {
    return;
  }
  print_inorder(root->left);
  printf("%d ", root->data);
  print_inorder(root->right);
}

// Function to print a binary search tree in preorder
void print_preorder(node_t *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  print_preorder(root->left);
  print_preorder(root->right);
}

// Function to print a binary search tree in postorder
void print_postorder(node_t *root) {
  if (root == NULL) {
    return;
  }
  print_postorder(root->left);
  print_postorder(root->right);
  printf("%d ", root->data);
}

int main() {
  node_t *root = NULL;
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);

  printf("Inorder traversal: ");
  print_inorder(root);
  printf("\n");

  printf("Preorder traversal: ");
  print_preorder(root);
  printf("\n");

  printf("Postorder traversal: ");
  print_postorder(root);
  printf("\n");

  node_t *node = search(root, 40);
  if (node != NULL) {
    printf("Node with data 40 found.\n");
  } else {
    printf("Node with data 40 not found.\n");
  }

  root = delete(root, 40);

  printf("Inorder traversal after deleting 40: ");
  print_inorder(root);
  printf("\n");

  return 0;
}