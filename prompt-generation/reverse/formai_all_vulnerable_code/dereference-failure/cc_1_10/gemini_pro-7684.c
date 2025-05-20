//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdlib.h>
#include <stdio.h>

// Define the node structure for the binary search tree
struct node {
  int key;
  struct node *left;
  struct node *right;
};

// Create a new node with the given key
struct node *create_node(int key) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->key = key;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Insert a new node into the binary search tree
void insert_node(struct node **root, int key) {
  if (*root == NULL) {
    *root = create_node(key);
    return;
  }

  if (key < (*root)->key) {
    insert_node(&(*root)->left, key);
  } else {
    insert_node(&(*root)->right, key);
  }
}

// Search for a node in the binary search tree
struct node *search_node(struct node *root, int key) {
  if (root == NULL) {
    return NULL;
  }

  if (root->key == key) {
    return root;
  }

  if (key < root->key) {
    return search_node(root->left, key);
  } else {
    return search_node(root->right, key);
  }
}

// Delete a node from the binary search tree
void delete_node(struct node **root, int key) {
  if (*root == NULL) {
    return;
  }

  if (key < (*root)->key) {
    delete_node(&(*root)->left, key);
  } else if (key > (*root)->key) {
    delete_node(&(*root)->right, key);
  } else {
    // Found the node to delete

    // If the node has no children, simply delete it
    if ((*root)->left == NULL && (*root)->right == NULL) {
      free(*root);
      *root = NULL;
      return;
    }

    // If the node has only one child, make the child the new root
    if ((*root)->left == NULL) {
      struct node *temp = *root;
      *root = (*root)->right;
      free(temp);
      return;
    } else if ((*root)->right == NULL) {
      struct node *temp = *root;
      *root = (*root)->left;
      free(temp);
      return;
    }

    // If the node has two children, find the smallest node in the right subtree and make it the new root
    struct node *temp = (*root)->right;
    while (temp->left != NULL) {
      temp = temp->left;
    }

    (*root)->key = temp->key;

    // Delete the smallest node in the right subtree
    delete_node(&(*root)->right, temp->key);
  }
}

// Print the binary search tree in order
void print_tree(struct node *root) {
  if (root == NULL) {
    return;
  }

  print_tree(root->left);
  printf("%d ", root->key);
  print_tree(root->right);
}

// Main function
int main() {
  // Create the root node of the binary search tree
  struct node *root = NULL;

  // Insert some nodes into the binary search tree
  insert_node(&root, 10);
  insert_node(&root, 5);
  insert_node(&root, 15);
  insert_node(&root, 3);
  insert_node(&root, 7);
  insert_node(&root, 12);
  insert_node(&root, 18);

  // Print the binary search tree in order
  printf("The binary search tree in order: ");
  print_tree(root);
  printf("\n");

  // Search for a node in the binary search tree
  struct node *found_node = search_node(root, 12);
  if (found_node != NULL) {
    printf("Found node with key %d\n", found_node->key);
  } else {
    printf("Node not found\n");
  }

  // Delete a node from the binary search tree
  delete_node(&root, 12);

  // Print the binary search tree in order
  printf("The binary search tree in order after deleting node with key 12: ");
  print_tree(root);
  printf("\n");

  return 0;
}