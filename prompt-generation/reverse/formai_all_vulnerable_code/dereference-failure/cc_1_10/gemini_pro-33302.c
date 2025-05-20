//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Node of a binary search tree
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

// Create a new node
struct Node *create_node(int data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Insert a node into a binary search tree
struct Node *insert_node(struct Node *root, int data) {
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

// Search for a node in a binary search tree
struct Node *search_node(struct Node *root, int data) {
  if (root == NULL) {
    return NULL;
  }

  if (data < root->data) {
    return search_node(root->left, data);
  } else if (data > root->data) {
    return search_node(root->right, data);
  } else {
    return root;
  }
}

// Print a binary search tree in pre-order
void print_pre_order(struct Node *root) {
  if (root == NULL) {
    return;
  }

  printf("%d ", root->data);
  print_pre_order(root->left);
  print_pre_order(root->right);
}

// Print a binary search tree in in-order
void print_in_order(struct Node *root) {
  if (root == NULL) {
    return;
  }

  print_in_order(root->left);
  printf("%d ", root->data);
  print_in_order(root->right);
}

// Print a binary search tree in post-order
void print_post_order(struct Node *root) {
  if (root == NULL) {
    return;
  }

  print_post_order(root->left);
  print_post_order(root->right);
  printf("%d ", root->data);
}

// Find the minimum node in a binary search tree
struct Node *find_min_node(struct Node *root) {
  if (root == NULL) {
    return NULL;
  }

  while (root->left != NULL) {
    root = root->left;
  }

  return root;
}

// Find the maximum node in a binary search tree
struct Node *find_max_node(struct Node *root) {
  if (root == NULL) {
    return NULL;
  }

  while (root->right != NULL) {
    root = root->right;
  }

  return root;
}

// Delete a node from a binary search tree
struct Node *delete_node(struct Node *root, int data) {
  if (root == NULL) {
    return NULL;
  }

  if (data < root->data) {
    root->left = delete_node(root->left, data);
  } else if (data > root->data) {
    root->right = delete_node(root->right, data);
  } else {
    if (root->left == NULL) {
      struct Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct Node *temp = root->left;
      free(root);
      return temp;
    } else {
      struct Node *temp = find_min_node(root->right);
      root->data = temp->data;
      root->right = delete_node(root->right, temp->data);
    }
  }

  return root;
}

// Destroy a binary search tree
void destroy_tree(struct Node *root) {
  if (root == NULL) {
    return;
  }

  destroy_tree(root->left);
  destroy_tree(root->right);
  free(root);
}

// Main function
int main() {
  // Create a binary search tree
  struct Node *root = NULL;
  root = insert_node(root, 10);
  root = insert_node(root, 5);
  root = insert_node(root, 15);
  root = insert_node(root, 2);
  root = insert_node(root, 7);
  root = insert_node(root, 12);
  root = insert_node(root, 20);

  // Search for a node in the binary search tree
  struct Node *found_node = search_node(root, 15);
  if (found_node != NULL) {
    printf("Found node: %d\n", found_node->data);
  } else {
    printf("Node not found\n");
  }

  // Print the binary search tree in pre-order
  printf("Pre-order: ");
  print_pre_order(root);
  printf("\n");

  // Print the binary search tree in in-order
  printf("In-order: ");
  print_in_order(root);
  printf("\n");

  // Print the binary search tree in post-order
  printf("Post-order: ");
  print_post_order(root);
  printf("\n");

  // Find the minimum node in the binary search tree
  struct Node *min_node = find_min_node(root);
  printf("Minimum node: %d\n", min_node->data);

  // Find the maximum node in the binary search tree
  struct Node *max_node = find_max_node(root);
  printf("Maximum node: %d\n", max_node->data);

  // Delete a node from the binary search tree
  root = delete_node(root, 15);

  // Print the binary search tree in in-order after deleting a node
  printf("In-order after deleting a node: ");
  print_in_order(root);
  printf("\n");

  // Destroy the binary search tree
  destroy_tree(root);

  return 0;
}