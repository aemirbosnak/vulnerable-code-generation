//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the tree.
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

// Create a new node with the given data.
node* create_node(int data) {
  node *new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Insert a new node into the tree.
node* insert_node(node *root, int data) {
  if (root == NULL) {
    return create_node(data);
  } else if (data < root->data) {
    root->left = insert_node(root->left, data);
  } else {
    root->right = insert_node(root->right, data);
  }
  return root;
}

// Print the tree in preorder traversal.
void preorder_traversal(node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
  }
}

// Print the tree in inorder traversal.
void inorder_traversal(node *root) {
  if (root != NULL) {
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
  }
}

// Print the tree in postorder traversal.
void postorder_traversal(node *root) {
  if (root != NULL) {
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
  }
}

// Free the memory allocated for the tree.
void free_tree(node *root) {
  if (root != NULL) {
    free_tree(root->left);
    free_tree(root->right);
    free(root);
  }
}

// Main function.
int main() {
  // Create the root node of the tree.
  node *root = create_node(10);

  // Insert some nodes into the tree.
  insert_node(root, 5);
  insert_node(root, 15);
  insert_node(root, 2);
  insert_node(root, 7);
  insert_node(root, 12);
  insert_node(root, 20);

  // Print the tree in preorder traversal.
  printf("Preorder traversal: ");
  preorder_traversal(root);
  printf("\n");

  // Print the tree in inorder traversal.
  printf("Inorder traversal: ");
  inorder_traversal(root);
  printf("\n");

  // Print the tree in postorder traversal.
  printf("Postorder traversal: ");
  postorder_traversal(root);
  printf("\n");

  // Free the memory allocated for the tree.
  free_tree(root);

  return 0;
}