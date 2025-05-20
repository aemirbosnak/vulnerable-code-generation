//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the binary tree
typedef struct node {
  int item_id;
  char *item_name;
  int quantity;
  struct node *left;
  struct node *right;
} node;

// Create a new node
node *create_node(int item_id, char *item_name, int quantity) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->item_id = item_id;
  new_node->item_name = item_name;
  new_node->quantity = quantity;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Insert a node into the binary tree
void insert_node(node **root, node *new_node) {
  if (*root == NULL) {
    *root = new_node;
  } else if (new_node->item_id < (*root)->item_id) {
    insert_node(&(*root)->left, new_node);
  } else {
    insert_node(&(*root)->right, new_node);
  }
}

// Search for a node in the binary tree
node *search_node(node *root, int item_id) {
  if (root == NULL) {
    return NULL;
  } else if (root->item_id == item_id) {
    return root;
  } else if (item_id < root->item_id) {
    return search_node(root->left, item_id);
  } else {
    return search_node(root->right, item_id);
  }
}

// Delete a node from the binary tree
void delete_node(node **root, int item_id) {
  if (*root == NULL) {
    return;
  } else if (item_id < (*root)->item_id) {
    delete_node(&(*root)->left, item_id);
  } else if (item_id > (*root)->item_id) {
    delete_node(&(*root)->right, item_id);
  } else {
    // Found the node to delete
    if ((*root)->left == NULL && (*root)->right == NULL) {
      // No children, so just delete the node
      free(*root);
      *root = NULL;
    } else if ((*root)->left == NULL) {
      // Only a right child, so replace the node with its right child
      node *temp = *root;
      *root = (*root)->right;
      free(temp);
    } else if ((*root)->right == NULL) {
      // Only a left child, so replace the node with its left child
      node *temp = *root;
      *root = (*root)->left;
      free(temp);
    } else {
      // Two children, so find the smallest node in the right subtree and replace the node with that node
      node *temp = (*root)->right;
      while (temp->left != NULL) {
        temp = temp->left;
      }
      (*root)->item_id = temp->item_id;
      (*root)->item_name = temp->item_name;
      (*root)->quantity = temp->quantity;
      delete_node(&(*root)->right, temp->item_id);
    }
  }
}

// Print the binary tree in order
void print_tree(node *root) {
  if (root == NULL) {
    return;
  }
  print_tree(root->left);
  printf("%d %s %d\n", root->item_id, root->item_name, root->quantity);
  print_tree(root->right);
}

// Main function
int main() {
  // Create the root node of the binary tree
  node *root = NULL;
  insert_node(&root, create_node(1, "Item 1", 10));
  insert_node(&root, create_node(2, "Item 2", 20));
  insert_node(&root, create_node(3, "Item 3", 30));
  insert_node(&root, create_node(4, "Item 4", 40));
  insert_node(&root, create_node(5, "Item 5", 50));

  // Print the binary tree in order
  printf("Binary tree in order:\n");
  print_tree(root);
  printf("\n");

  // Search for a node in the binary tree
  node *found_node = search_node(root, 3);
  if (found_node != NULL) {
    printf("Found node with item_id %d, item_name %s, and quantity %d\n", found_node->item_id, found_node->item_name, found_node->quantity);
  } else {
    printf("Node not found\n");
  }

  // Delete a node from the binary tree
  delete_node(&root, 3);

  // Print the binary tree in order
  printf("Binary tree in order after deleting node with item_id 3:\n");
  print_tree(root);
  printf("\n");

  return 0;
}