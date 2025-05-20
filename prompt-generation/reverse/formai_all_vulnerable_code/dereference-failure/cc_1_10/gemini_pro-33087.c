//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: lively
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} Node;

Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

Node *insert_node(Node *root, int data) {
  if (root == NULL) {
    return create_node(data);
  } else if (data < root->data) {
    root->left = insert_node(root->left, data);
  } else {
    root->right = insert_node(root->right, data);
  }
  return root;
}

void inorder_traversal(Node *root) {
  if (root == NULL) {
    return;
  }
  inorder_traversal(root->left);
  printf("%d ", root->data);
  inorder_traversal(root->right);
}

int main() {
  Node *root = NULL;
  int choice, data;

  while (1) {
    printf("\n1. Insert a node\n2. Inorder traversal\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the data to insert: ");
        scanf("%d", &data);
        root = insert_node(root, data);
        break;

      case 2:
        printf("Inorder traversal: ");
        inorder_traversal(root);
        printf("\n");
        break;

      case 3:
        exit(0);

      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}