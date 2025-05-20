//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Define the tree node structure
typedef struct tree_node {
  int data;
  struct tree_node *left;
  struct tree_node *right;
} tree_node;

// Create a new tree node
tree_node *create_node(int data) {
  tree_node *new_node = (tree_node *)malloc(sizeof(tree_node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Insert a new node into the tree
void insert_node(tree_node **root, int data) {
  if (*root == NULL) {
    *root = create_node(data);
  } else if (data < (*root)->data) {
    insert_node(&(*root)->left, data);
  } else {
    insert_node(&(*root)->right, data);
  }
}

// Perform a depth-first search of the tree
void dfs(tree_node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    dfs(root->left);
    dfs(root->right);
  }
}

// Perform a breadth-first search of the tree
void bfs(tree_node *root) {
  if (root != NULL) {
    // Create a queue to store the nodes to be visited
    tree_node **queue = (tree_node **)malloc(sizeof(tree_node *) * 100);
    int front = 0;
    int rear = 0;

    // Add the root node to the queue
    queue[rear++] = root;

    // While there are nodes in the queue, visit them
    while (front != rear) {
      // Get the next node from the queue
      tree_node *node = queue[front++];

      // Print the node's data
      printf("%d ", node->data);

      // If the node has any children, add them to the queue
      if (node->left != NULL) {
        queue[rear++] = node->left;
      }
      if (node->right != NULL) {
        queue[rear++] = node->right;
      }
    }

    // Free the queue
    free(queue);
  }
}

// Create a binary tree
tree_node *create_tree() {
  tree_node *root = NULL;
  insert_node(&root, 10);
  insert_node(&root, 5);
  insert_node(&root, 15);
  insert_node(&root, 2);
  insert_node(&root, 7);
  insert_node(&root, 12);
  insert_node(&root, 20);
  return root;
}

// Main function
int main() {
  // Create the binary tree
  tree_node *root = create_tree();

  // Perform a depth-first search of the tree
  printf("Depth-first search: ");
  dfs(root);
  printf("\n");

  // Perform a breadth-first search of the tree
  printf("Breadth-first search: ");
  bfs(root);
  printf("\n");

  return 0;
}