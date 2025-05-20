//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: excited
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct bst_node {
  int data;
  struct bst_node *left;
  struct bst_node *right;
} bst_node;

bst_node *create_node(int data) {
  bst_node *new_node = (bst_node *)malloc(sizeof(bst_node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

bst_node *insert_node(bst_node *root, int data) {
  if (root == NULL) {
    return create_node(data);
  } else if (data < root->data) {
    root->left = insert_node(root->left, data);
  } else if (data > root->data) {
    root->right = insert_node(root->right, data);
  }
  return root;
}

bst_node *find_node(bst_node *root, int data) {
  if (root == NULL) {
    return NULL;
  } else if (data == root->data) {
    return root;
  } else if (data < root->data) {
    return find_node(root->left, data);
  } else if (data > root->data) {
    return find_node(root->right, data);
  }
  return NULL;
}

bst_node *delete_node(bst_node *root, int data) {
  if (root == NULL) {
    return NULL;
  } else if (data < root->data) {
    root->left = delete_node(root->left, data);
  } else if (data > root->data) {
    root->right = delete_node(root->right, data);
  } else {
    if (root->left == NULL) {
      bst_node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      bst_node *temp = root->left;
      free(root);
      return temp;
    } else {
      bst_node *temp = root->left;
      while (temp->right != NULL) {
        temp = temp->right;
      }
      root->data = temp->data;
      root->left = delete_node(root->left, temp->data);
    }
  }
  return root;
}

void inorder_traversal(bst_node *root) {
  if (root == NULL) {
    return;
  }
  inorder_traversal(root->left);
  printf("%d ", root->data);
  inorder_traversal(root->right);
}

void preorder_traversal(bst_node *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  preorder_traversal(root->left);
  preorder_traversal(root->right);
}

void postorder_traversal(bst_node *root) {
  if (root == NULL) {
    return;
  }
  postorder_traversal(root->left);
  postorder_traversal(root->right);
  printf("%d ", root->data);
}

int main() {
  bst_node *root = NULL;
  root = insert_node(root, 50);
  root = insert_node(root, 30);
  root = insert_node(root, 20);
  root = insert_node(root, 40);
  root = insert_node(root, 70);
  root = insert_node(root, 60);
  root = insert_node(root, 80);

  printf("Inorder traversal: ");
  inorder_traversal(root);
  printf("\n");

  bst_node *found_node = find_node(root, 60);
  if (found_node != NULL) {
    printf("Node with data 60 found!\n");
  } else {
    printf("Node with data 60 not found!\n");
  }

  root = delete_node(root, 20);

  printf("Inorder traversal after deleting node with data 20: ");
  inorder_traversal(root);
  printf("\n");

  return 0;
}