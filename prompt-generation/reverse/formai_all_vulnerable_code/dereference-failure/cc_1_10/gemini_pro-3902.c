//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// A binary search tree node
struct node {
  int data;
  struct node *left;
  struct node *right;
};

// Create a new binary search tree node
struct node *create_node(int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Insert a new node into a binary search tree
struct node *insert_node(struct node *root, int data) {
  if (root == NULL) {
    return create_node(data);
  } else if (data < root->data) {
    root->left = insert_node(root->left, data);
  } else {
    root->right = insert_node(root->right, data);
  }
  return root;
}

// Search for a node in a binary search tree
struct node *search_node(struct node *root, int data) {
  if (root == NULL) {
    return NULL;
  } else if (data == root->data) {
    return root;
  } else if (data < root->data) {
    return search_node(root->left, data);
  } else {
    return search_node(root->right, data);
  }
}

// Print a binary search tree in preorder traversal
void preorder_traversal(struct node *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  preorder_traversal(root->left);
  preorder_traversal(root->right);
}

// Print a binary search tree in inorder traversal
void inorder_traversal(struct node *root) {
  if (root == NULL) {
    return;
  }
  inorder_traversal(root->left);
  printf("%d ", root->data);
  inorder_traversal(root->right);
}

// Print a binary search tree in postorder traversal
void postorder_traversal(struct node *root) {
  if (root == NULL) {
    return;
  }
  postorder_traversal(root->left);
  postorder_traversal(root->right);
  printf("%d ", root->data);
}

// Find the minimum node in a binary search tree
struct node *find_min_node(struct node *root) {
  if (root == NULL) {
    return NULL;
  }
  while (root->left != NULL) {
    root = root->left;
  }
  return root;
}

// Find the maximum node in a binary search tree
struct node *find_max_node(struct node *root) {
  if (root == NULL) {
    return NULL;
  }
  while (root->right != NULL) {
    root = root->right;
  }
  return root;
}

// Delete a node from a binary search tree
struct node *delete_node(struct node *root, int data) {
  if (root == NULL) {
    return NULL;
  } else if (data < root->data) {
    root->left = delete_node(root->left, data);
  } else if (data > root->data) {
    root->right = delete_node(root->right, data);
  } else {
    // The node to be deleted is the root node
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    } else if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    } else {
      // The node to be deleted has two children
      struct node *temp = find_min_node(root->right);
      root->data = temp->data;
      root->right = delete_node(root->right, temp->data);
    }
  }
  return root;
}

// Main function
int main() {
  // Create a binary search tree
  struct node *root = NULL;
  root = insert_node(root, 50);
  root = insert_node(root, 30);
  root = insert_node(root, 20);
  root = insert_node(root, 40);
  root = insert_node(root, 70);
  root = insert_node(root, 60);
  root = insert_node(root, 80);

  // Print the binary search tree in preorder traversal
  printf("Preorder traversal: ");
  preorder_traversal(root);
  printf("\n");

  // Print the binary search tree in inorder traversal
  printf("Inorder traversal: ");
  inorder_traversal(root);
  printf("\n");

  // Print the binary search tree in postorder traversal
  printf("Postorder traversal: ");
  postorder_traversal(root);
  printf("\n");

  // Search for a node in the binary search tree
  struct node *found_node = search_node(root, 40);
  if (found_node != NULL) {
    printf("Node found: %d\n", found_node->data);
  } else {
    printf("Node not found\n");
  }

  // Find the minimum node in the binary search tree
  struct node *min_node = find_min_node(root);
  printf("Minimum node: %d\n", min_node->data);

  // Find the maximum node in the binary search tree
  struct node *max_node = find_max_node(root);
  printf("Maximum node: %d\n", max_node->data);

  // Delete a node from the binary search tree
  root = delete_node(root, 40);
  printf("Node deleted: 40\n");

  // Print the binary search tree in inorder traversal after deleting a node
  printf("Inorder traversal after deleting a node: ");
  inorder_traversal(root);
  printf("\n");

  return 0;
}