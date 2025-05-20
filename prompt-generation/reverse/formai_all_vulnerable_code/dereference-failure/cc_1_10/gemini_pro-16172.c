//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// A binary search tree node
struct node {
  int data;
  struct node *left;
  struct node *right;
};

// Create a new binary search tree node
struct node* create_node(int data) {
  struct node *new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Insert a new node into a binary search tree
struct node* insert_node(struct node *root, int data) {
  if (root == NULL) {
    return create_node(data);
  } else {
    if (data < root->data) {
      root->left = insert_node(root->left, data);
    } else {
      root->right = insert_node(root->right, data);
    }
  }
  return root;
}

// Search for a node in a binary search tree
struct node* search_node(struct node *root, int data) {
  if (root == NULL) {
    return NULL;
  } else {
    if (data == root->data) {
      return root;
    } else if (data < root->data) {
      return search_node(root->left, data);
    } else {
      return search_node(root->right, data);
    }
  }
}

// Print a binary search tree in order
void print_tree_inorder(struct node *root) {
  if (root == NULL) {
    return;
  } else {
    print_tree_inorder(root->left);
    printf("%d ", root->data);
    print_tree_inorder(root->right);
  }
}

// Print a binary search tree preorder
void print_tree_preorder(struct node *root) {
  if (root == NULL) {
    return;
  } else {
    printf("%d ", root->data);
    print_tree_preorder(root->left);
    print_tree_preorder(root->right);
  }
}

// Print a binary search tree postorder
void print_tree_postorder(struct node *root) {
  if (root == NULL) {
    return;
  } else {
    print_tree_postorder(root->left);
    print_tree_postorder(root->right);
    printf("%d ", root->data);
  }
}

// Find the minimum value in a binary search tree
struct node* find_min(struct node *root) {
  if (root == NULL) {
    return NULL;
  } else {
    while (root->left != NULL) {
      root = root->left;
    }
    return root;
  }
}

// Find the maximum value in a binary search tree
struct node* find_max(struct node *root) {
  if (root == NULL) {
    return NULL;
  } else {
    while (root->right != NULL) {
      root = root->right;
    }
    return root;
  }
}

// Delete a node from a binary search tree
struct node* delete_node(struct node *root, int data) {
  if (root == NULL) {
    return NULL;
  } else {
    if (data < root->data) {
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
        struct node *temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
      }
    }
  }
  return root;
}

// Free a binary search tree
void free_tree(struct node *root) {
  if (root == NULL) {
    return;
  } else {
    free_tree(root->left);
    free_tree(root->right);
    free(root);
  }
}

// Main function
int main() {
  // Create a binary search tree
  struct node *root = create_node(50);
  insert_node(root, 30);
  insert_node(root, 70);
  insert_node(root, 20);
  insert_node(root, 40);
  insert_node(root, 60);
  insert_node(root, 80);

  // Print the binary search tree in order
  printf("In order: ");
  print_tree_inorder(root);
  printf("\n");

  // Print the binary search tree preorder
  printf("Preorder: ");
  print_tree_preorder(root);
  printf("\n");

  // Print the binary search tree postorder
  printf("Postorder: ");
  print_tree_postorder(root);
  printf("\n");

  // Search for a node in the binary search tree
  struct node *found_node = search_node(root, 40);
  if (found_node != NULL) {
    printf("Found node with data %d\n", found_node->data);
  } else {
    printf("Node not found\n");
  }

  // Find the minimum value in the binary search tree
  struct node *min_node = find_min(root);
  printf("Minimum value: %d\n", min_node->data);

  // Find the maximum value in the binary search tree
  struct node *max_node = find_max(root);
  printf("Maximum value: %d\n", max_node->data);

  // Delete a node from the binary search tree
  delete_node(root, 40);

  // Print the binary search tree in order after deleting a node
  printf("In order after deleting node with data 40: ");
  print_tree_inorder(root);
  printf("\n");

  // Free the binary search tree
  free_tree(root);

  return 0;
}