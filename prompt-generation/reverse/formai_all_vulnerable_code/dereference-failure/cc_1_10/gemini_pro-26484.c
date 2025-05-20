//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A node in a binary search tree
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

// A binary search tree
typedef struct tree {
  struct node *root;
} tree;

// Create a new binary search tree
tree *create_tree() {
  tree *t = malloc(sizeof(tree));
  t->root = NULL;
  return t;
}

// Insert a new node into a binary search tree
void insert(tree *t, int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;

  if (t->root == NULL) {
    t->root = new_node;
  } else {
    node *current = t->root;
    while (true) {
      if (data < current->data) {
        if (current->left == NULL) {
          current->left = new_node;
          break;
        } else {
          current = current->left;
        }
      } else {
        if (current->right == NULL) {
          current->right = new_node;
          break;
        } else {
          current = current->right;
        }
      }
    }
  }
}

// Search for a node in a binary search tree
node *search(tree *t, int data) {
  node *current = t->root;
  while (current != NULL) {
    if (data == current->data) {
      return current;
    } else if (data < current->data) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return NULL;
}

// Print a binary search tree in order
void inorder(node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

// Print a binary search tree in preorder
void preorder(node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

// Print a binary search tree in postorder
void postorder(node *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

// Free the memory allocated for a binary search tree
void free_tree(node *root) {
  if (root != NULL) {
    free_tree(root->left);
    free_tree(root->right);
    free(root);
  }
}

// Main function
int main() {
  // Create a binary search tree
  tree *t = create_tree();

  // Insert some nodes into the tree
  insert(t, 10);
  insert(t, 5);
  insert(t, 15);
  insert(t, 2);
  insert(t, 7);
  insert(t, 12);
  insert(t, 20);

  // Print the tree in order
  printf("In order: ");
  inorder(t->root);
  printf("\n");

  // Print the tree in preorder
  printf("Pre order: ");
  preorder(t->root);
  printf("\n");

  // Print the tree in postorder
  printf("Post order: ");
  postorder(t->root);
  printf("\n");

  // Search for a node in the tree
  node *found = search(t, 12);
  if (found != NULL) {
    printf("Found node with data %d\n", found->data);
  } else {
    printf("Node not found\n");
  }

  // Free the memory allocated for the tree
  free_tree(t->root);

  return 0;
}