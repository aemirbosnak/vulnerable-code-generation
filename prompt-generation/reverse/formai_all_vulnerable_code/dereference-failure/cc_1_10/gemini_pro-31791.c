//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Node structure for a binary tree
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node_t;

// Insert a new node with the given data into the binary tree
node_t *insert(node_t *root, int data) {
  if (root == NULL) {
    root = (node_t *)malloc(sizeof(node_t));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
  } else if (data <= root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }
  return root;
}

// Print the binary tree in a level-order traversal
void print_level_order(node_t *root) {
  if (root == NULL) {
    return;
  }
  // Create a queue to store the nodes at each level
  node_t **queue = (node_t **)malloc(sizeof(node_t *) * 100);
  int front = 0;
  int rear = 0;
  // Add the root node to the queue
  queue[rear++] = root;
  // While the queue is not empty, print the data of the nodes at the front of the queue and add their children to the queue
  while (front != rear) {
    node_t *node = queue[front++];
    printf("%d ", node->data);
    if (node->left != NULL) {
      queue[rear++] = node->left;
    }
    if (node->right != NULL) {
      queue[rear++] = node->right;
    }
  }
  // Free the memory allocated for the queue
  free(queue);
}

// Free the memory allocated for the binary tree
void free_tree(node_t *root) {
  if (root == NULL) {
    return;
  }
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}

// Main function
int main() {
  // Create a binary tree
  node_t *root = NULL;
  root = insert(root, 10);
  root = insert(root, 5);
  root = insert(root, 15);
  root = insert(root, 2);
  root = insert(root, 7);
  root = insert(root, 12);
  root = insert(root, 20);

  // Print the binary tree in a level-order traversal
  print_level_order(root);

  // Free the memory allocated for the binary tree
  free_tree(root);

  return 0;
}