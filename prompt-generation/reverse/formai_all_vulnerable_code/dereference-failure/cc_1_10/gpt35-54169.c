//FormAI DATASET v1.0 Category: Binary search trees ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};

struct node* create_node(int data) {
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

struct node* insert_node(struct node* root, int data) {
  if (root == NULL) {
    return create_node(data);
  }

  if (data < root->data) {
    root->left = insert_node(root->left, data);
  } else if (data > root->data) {
    root->right = insert_node(root->right, data);
  }

  return root;
}

struct node* search_node(struct node* root, int data) {
  if (root == NULL || root->data == data) {
    return root;
  }

  if (data < root->data) {
    return search_node(root->left, data);
  }

  return search_node(root->right, data);
}

struct node* delete_node(struct node* root, int data) {
  if (root == NULL) {
    return root;
  }

  if (data < root->data) {
    root->left = delete_node(root->left, data);
  } else if (data > root->data) {
    root->right = delete_node(root->right, data);
  } else {
    if (root->left == NULL) {
      struct node* temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node* temp = root->left;
      free(root);
      return temp;
    }

    struct node* temp = root->right;
    while (temp->left != NULL) {
      temp = temp->left;
    }

    root->data = temp->data;
    root->right = delete_node(root->right, temp->data);
  }
  return root;
}

void inorder_traversal(struct node* root) {
  if (root != NULL) {
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
  }
}

int main() {
  struct node* root = NULL;

  root = insert_node(root, 7);
  root = insert_node(root, 3);
  root = insert_node(root, 10);
  root = insert_node(root, 1);
  root = insert_node(root, 5);
  root = insert_node(root, 8);
  root = insert_node(root, 12);

  printf("Inorder traversal: ");
  inorder_traversal(root);
  printf("\n");

  struct node* found_node = search_node(root, 5);
  if (found_node != NULL) {
    printf("Found node: %d\n", found_node->data);
  } else {
    printf("Node not found\n");
  }

  root = delete_node(root, 7);

  printf("Inorder traversal after deleting root node: ");
  inorder_traversal(root);
  printf("\n");

  return 0;
}