//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: intelligent
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

// Find the minimum node in a binary search tree
struct node *find_min_node(struct node *root) {
  if (root == NULL) {
    return NULL;
  } else if (root->left == NULL) {
    return root;
  } else {
    return find_min_node(root->left);
  }
}

// Find the maximum node in a binary search tree
struct node *find_max_node(struct node *root) {
  if (root == NULL) {
    return NULL;
  } else if (root->right == NULL) {
    return root;
  } else {
    return find_max_node(root->right);
  }
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
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    } else {
      struct node *temp = find_min_node(root->right);
      root->data = temp->data;
      root->right = delete_node(root->right, temp->data);
    }
  }
  return root;
}

// Print a binary search tree in order
void print_tree_inorder(struct node *root) {
  if (root == NULL) {
    return;
  }
  print_tree_inorder(root->left);
  printf("%d ", root->data);
  print_tree_inorder(root->right);
}

// Print a binary search tree preorder
void print_tree_preorder(struct node *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  print_tree_preorder(root->left);
  print_tree_preorder(root->right);
}

// Print a binary search tree postorder
void print_tree_postorder(struct node *root) {
  if (root == NULL) {
    return;
  }
  print_tree_postorder(root->left);
  print_tree_postorder(root->right);
  printf("%d ", root->data);
}

// Main function
int main() {
  // Create a binary search tree
  struct node *root = NULL;
  root = insert_node(root, 10);
  root = insert_node(root, 5);
  root = insert_node(root, 15);
  root = insert_node(root, 2);
  root = insert_node(root, 7);
  root = insert_node(root, 12);
  root = insert_node(root, 20);

  // Print the binary search tree in order
  printf("In order traversal: ");
  print_tree_inorder(root);
  printf("\n");

  // Print the binary search tree preorder
  printf("Pre order traversal: ");
  print_tree_preorder(root);
  printf("\n");

  // Print the binary search tree postorder
  printf("Post order traversal: ");
  print_tree_postorder(root);
  printf("\n");

  // Search for a node in the binary search tree
  struct node *found_node = search_node(root, 12);
  if (found_node != NULL) {
    printf("Node found: %d\n", found_node->data);
  } else {
    printf("Node not found.\n");
  }

  // Delete a node from the binary search tree
  root = delete_node(root, 12);

  // Print the binary search tree in order
  printf("In order traversal after deleting node 12: ");
  print_tree_inorder(root);
  printf("\n");

  return 0;
}