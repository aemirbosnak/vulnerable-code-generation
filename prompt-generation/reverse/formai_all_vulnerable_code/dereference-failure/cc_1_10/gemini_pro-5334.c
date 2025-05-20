//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the binary search tree
struct node {
  char *name;
  int quantity;
  struct node *left;
  struct node *right;
};

// Create a new node
struct node *create_node(char *name, int quantity) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->name = strdup(name);
  new_node->quantity = quantity;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Insert a new node into the binary search tree
void insert_node(struct node **root, struct node *new_node) {
  if (*root == NULL) {
    *root = new_node;
  } else if (strcmp(new_node->name, (*root)->name) < 0) {
    insert_node(&(*root)->left, new_node);
  } else {
    insert_node(&(*root)->right, new_node);
  }
}

// Search for a node in the binary search tree
struct node *search_node(struct node *root, char *name) {
  if (root == NULL) {
    return NULL;
  } else if (strcmp(name, root->name) == 0) {
    return root;
  } else if (strcmp(name, root->name) < 0) {
    return search_node(root->left, name);
  } else {
    return search_node(root->right, name);
  }
}

// Delete a node from the binary search tree
void delete_node(struct node **root, char *name) {
  if (*root == NULL) {
    return;
  } else if (strcmp(name, (*root)->name) < 0) {
    delete_node(&(*root)->left, name);
  } else if (strcmp(name, (*root)->name) > 0) {
    delete_node(&(*root)->right, name);
  } else {
    if ((*root)->left == NULL && (*root)->right == NULL) {
      free(*root);
      *root = NULL;
    } else if ((*root)->left == NULL) {
      struct node *temp = *root;
      *root = (*root)->right;
      free(temp);
    } else if ((*root)->right == NULL) {
      struct node *temp = *root;
      *root = (*root)->left;
      free(temp);
    } else {
      struct node *temp = (*root)->left;
      while (temp->right != NULL) {
        temp = temp->right;
      }
      (*root)->name = temp->name;
      (*root)->quantity = temp->quantity;
      delete_node(&(*root)->left, temp->name);
    }
  }
}

// Print the binary search tree
void print_tree(struct node *root) {
  if (root == NULL) {
    return;
  }
  print_tree(root->left);
  printf("%s: %d\n", root->name, root->quantity);
  print_tree(root->right);
}

// Free the binary search tree
void free_tree(struct node *root) {
  if (root == NULL) {
    return;
  }
  free_tree(root->left);
  free_tree(root->right);
  free(root->name);
  free(root);
}

// Main function
int main() {
  // Create the root of the binary search tree
  struct node *root = NULL;

  // Insert some nodes into the binary search tree
  insert_node(&root, create_node("Aspirin", 100));
  insert_node(&root, create_node("Ibuprofen", 50));
  insert_node(&root, create_node("Paracetamol", 25));
  insert_node(&root, create_node("Codeine", 10));
  insert_node(&root, create_node("Morphine", 5));

  // Print the binary search tree
  print_tree(root);

  // Search for a node in the binary search tree
  struct node *found_node = search_node(root, "Ibuprofen");
  if (found_node != NULL) {
    printf("Found %s in the binary search tree\n", found_node->name);
  }

  // Delete a node from the binary search tree
  delete_node(&root, "Paracetamol");

  // Print the binary search tree
  print_tree(root);

  // Free the binary search tree
  free_tree(root);

  return 0;
}