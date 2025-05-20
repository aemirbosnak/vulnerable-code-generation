//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary tree
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

// Function to create a new node in the binary tree
node *create_node(int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Function to insert a new node into the binary tree
node *insert_node(node *root, int data) {
  if (root == NULL) {
    return create_node(data);
  } else if (data < root->data) {
    root->left = insert_node(root->left, data);
  } else {
    root->right = insert_node(root->right, data);
  }
  return root;
}

// Function to find the minimum value in the binary tree
node *find_min(node *root) {
  if (root == NULL) {
    return NULL;
  } else if (root->left == NULL) {
    return root;
  } else {
    return find_min(root->left);
  }
}

// Function to find the maximum value in the binary tree
node *find_max(node *root) {
  if (root == NULL) {
    return NULL;
  } else if (root->right == NULL) {
    return root;
  } else {
    return find_max(root->right);
  }
}

// Function to find the height of the binary tree
int find_height(node *root) {
  if (root == NULL) {
    return 0;
  } else {
    int left_height = find_height(root->left);
    int right_height = find_height(root->right);
    return 1 + (left_height > right_height ? left_height : right_height);
  }
}

// Function to check if the binary tree is balanced
int is_balanced(node *root) {
  if (root == NULL) {
    return 1;
  } else {
    int left_height = find_height(root->left);
    int right_height = find_height(root->right);
    return (abs(left_height - right_height) <= 1) && is_balanced(root->left) && is_balanced(root->right);
  }
}

// Function to print the binary tree in pre-order traversal
void print_pre_order(node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    print_pre_order(root->left);
    print_pre_order(root->right);
  }
}

// Function to print the binary tree in in-order traversal
void print_in_order(node *root) {
  if (root != NULL) {
    print_in_order(root->left);
    printf("%d ", root->data);
    print_in_order(root->right);
  }
}

// Function to print the binary tree in post-order traversal
void print_post_order(node *root) {
  if (root != NULL) {
    print_post_order(root->left);
    print_post_order(root->right);
    printf("%d ", root->data);
  }
}

// Function to free the memory allocated for the binary tree
void free_tree(node *root) {
  if (root != NULL) {
    free_tree(root->left);
    free_tree(root->right);
    free(root);
  }
}

// Main function
int main() {
  // Create the root of the binary tree
  node *root = create_node(50);

  // Insert some nodes into the binary tree
  insert_node(root, 30);
  insert_node(root, 20);
  insert_node(root, 40);
  insert_node(root, 70);
  insert_node(root, 60);
  insert_node(root, 80);

  // Print the binary tree in pre-order traversal
  printf("Pre-order traversal: ");
  print_pre_order(root);
  printf("\n");

  // Print the binary tree in in-order traversal
  printf("In-order traversal: ");
  print_in_order(root);
  printf("\n");

  // Print the binary tree in post-order traversal
  printf("Post-order traversal: ");
  print_post_order(root);
  printf("\n");

  // Find the minimum value in the binary tree
  node *min_node = find_min(root);
  printf("Minimum value: %d\n", min_node->data);

  // Find the maximum value in the binary tree
  node *max_node = find_max(root);
  printf("Maximum value: %d\n", max_node->data);

  // Find the height of the binary tree
  int height = find_height(root);
  printf("Height of the binary tree: %d\n", height);

  // Check if the binary tree is balanced
  int is_balanced_result = is_balanced(root);
  printf("Is the binary tree balanced: %s\n", is_balanced_result ? "Yes" : "No");

  // Free the memory allocated for the binary tree
  free_tree(root);

  return 0;
}