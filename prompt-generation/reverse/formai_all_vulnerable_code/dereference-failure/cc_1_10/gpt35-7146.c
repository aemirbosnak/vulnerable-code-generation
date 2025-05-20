//FormAI DATASET v1.0 Category: Binary search trees ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node* left;
  struct Node* right;
};

struct Node* create_node(int value) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

struct Node* insert_node(struct Node* root, int value) {
  if (root == NULL) {
    return create_node(value);
  }
  if (value < root->value) {
    root->left = insert_node(root->left, value);
  } else {
    root->right = insert_node(root->right, value);
  }
  return root;
}

void preorder_traversal(struct Node* root) {
  if (root != NULL) {
    printf("%d ", root->value);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
  }
}

void inorder_traversal(struct Node* root) {
  if (root != NULL) {
    inorder_traversal(root->left);
    printf("%d ", root->value);
    inorder_traversal(root->right);
  }
}

void postorder_traversal(struct Node* root) {
  if (root != NULL) {
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->value);
  }
}

struct Node* delete_node(struct Node* root, int value) {
  if (root == NULL) {
    return root;
  }
  if (value < root->value) {
    root->left = delete_node(root->left, value);
  } else if (value > root->value) {
    root->right = delete_node(root->right, value);
  } else {
    if (root->left == NULL) {
      struct Node* temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct Node* temp = root->left;
      free(root);
      return temp;
    }
    struct Node* temp = root->right;
    while (temp->left != NULL) {
      temp = temp->left;
    }
    root->value = temp->value;
    root->right = delete_node(root->right, temp->value);
  }
  return root;
}

int main() {
  struct Node* root = create_node(50);
  insert_node(root, 30);
  insert_node(root, 20);
  insert_node(root, 40);
  insert_node(root, 70);
  insert_node(root, 60);
  insert_node(root, 80);
  printf("Preorder traversal of the tree: ");
  preorder_traversal(root);
  printf("\n");
  printf("Inorder traversal of the tree: ");
  inorder_traversal(root);
  printf("\n");
  printf("Postorder traversal of the tree: ");
  postorder_traversal(root);
  printf("\n");
  root = delete_node(root, 20);
  printf("Inorder traversal after deleting 20: ");
  inorder_traversal(root);
  printf("\n");
  return 0;
}