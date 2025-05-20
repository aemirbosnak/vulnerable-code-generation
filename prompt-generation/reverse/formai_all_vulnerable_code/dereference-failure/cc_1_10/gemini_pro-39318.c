//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define the node of the binary search tree
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

// Define the binary search tree
typedef struct tree {
  struct node *root;
} tree;

// Create a new node
node *create_node(int data) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Insert a new node into the binary search tree
void insert_node(tree *t, int data) {
  node *new_node = create_node(data);
  node *current_node = t->root;
  while (current_node != NULL) {
    if (data < current_node->data) {
      if (current_node->left == NULL) {
        current_node->left = new_node;
        return;
      } else {
        current_node = current_node->left;
      }
    } else {
      if (current_node->right == NULL) {
        current_node->right = new_node;
        return;
      } else {
        current_node = current_node->right;
      }
    }
  }
  t->root = new_node;
}

// Search for a node in the binary search tree
node *search_node(tree *t, int data) {
  node *current_node = t->root;
  while (current_node != NULL) {
    if (data == current_node->data) {
      return current_node;
    } else if (data < current_node->data) {
      current_node = current_node->left;
    } else {
      current_node = current_node->right;
    }
  }
  return NULL;
}

// Delete a node from the binary search tree
void delete_node(tree *t, int data) {
  node *current_node = t->root;
  node *parent_node = NULL;
  while (current_node != NULL) {
    if (data == current_node->data) {
      if (current_node->left == NULL && current_node->right == NULL) {
        if (parent_node == NULL) {
          t->root = NULL;
        } else if (parent_node->left == current_node) {
          parent_node->left = NULL;
        } else {
          parent_node->right = NULL;
        }
      } else if (current_node->left == NULL) {
        if (parent_node == NULL) {
          t->root = current_node->right;
        } else if (parent_node->left == current_node) {
          parent_node->left = current_node->right;
        } else {
          parent_node->right = current_node->right;
        }
      } else if (current_node->right == NULL) {
        if (parent_node == NULL) {
          t->root = current_node->left;
        } else if (parent_node->left == current_node) {
          parent_node->left = current_node->left;
        } else {
          parent_node->right = current_node->left;
        }
      } else {
        node *successor_node = current_node->right;
        node *successor_parent_node = current_node;
        while (successor_node->left != NULL) {
          successor_parent_node = successor_node;
          successor_node = successor_node->left;
        }
        current_node->data = successor_node->data;
        if (successor_parent_node->left == successor_node) {
          successor_parent_node->left = successor_node->right;
        } else {
          successor_parent_node->right = successor_node->right;
        }
      }
      free(current_node);
      return;
    } else if (data < current_node->data) {
      parent_node = current_node;
      current_node = current_node->left;
    } else {
      parent_node = current_node;
      current_node = current_node->right;
    }
  }
}

// Print the binary search tree in order
void print_tree_in_order(tree *t) {
  node *current_node = t->root;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->left;
  }
  printf("\n");
}

// Print the binary search tree in pre-order
void print_tree_in_pre_order(tree *t) {
  node *current_node = t->root;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->right;
  }
  printf("\n");
}

// Print the binary search tree in post-order
void print_tree_in_post_order(tree *t) {
  node *current_node = t->root;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->left;
  }
  printf("\n");
}

// Main function
int main(void) {
  // Create a new binary search tree
  tree *t = (tree *)malloc(sizeof(tree));
  t->root = NULL;

  // Insert some nodes into the binary search tree
  insert_node(t, 10);
  insert_node(t, 5);
  insert_node(t, 15);
  insert_node(t, 2);
  insert_node(t, 7);
  insert_node(t, 12);
  insert_node(t, 20);

  // Print the binary search tree in order
  printf("In order: ");
  print_tree_in_order(t);

  // Print the binary search tree in pre-order
  printf("Pre order: ");
  print_tree_in_pre_order(t);

  // Print the binary search tree in post-order
  printf("Post order: ");
  print_tree_in_post_order(t);

  // Search for a node in the binary search tree
  node *found_node = search_node(t, 15);
  if (found_node != NULL) {
    printf("Found node: %d\n", found_node->data);
  } else {
    printf("Node not found\n");
  }

  // Delete a node from the binary search tree
  delete_node(t, 15);

  // Print the binary search tree in order
  printf("In order: ");
  print_tree_in_order(t);

  // Free the binary search tree
  free(t);

  return 0;
}