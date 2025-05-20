//FormAI DATASET v1.0 Category: Binary search trees ; Style: funny
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *left_child;
  struct Node *right_child;
} Node;

Node* create_node(int value){
  Node *new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->left_child = NULL;
  new_node->right_child = NULL;
  return new_node;
}

void insert(Node **root, int value){
  if (*root == NULL){
    *root = create_node(value);
    printf("Successfully inserted value %d into the tree!\n", value);
  }
  else if (value < (*root)->value){
    insert(&(*root)->left_child, value);
  }
  else if (value > (*root)->value){
    insert(&(*root)->right_child, value);
  }
  else{
    printf("This value is already in the tree!\n");
  }
}

void print_in_order(Node *root){
  if (root != NULL){
    print_in_order(root->left_child);
    printf("%d ", root->value);
    print_in_order(root->right_child);
  }
}

int check_if_value_exists(Node *root, int value){
  if (root == NULL){
    return 0;
  }
  else if (root->value == value){
    return 1;
  }
  else if (value < root->value){
    return check_if_value_exists(root->left_child, value);
  }
  else{
    return check_if_value_exists(root->right_child, value);
  }
}

Node* find_minimum_value_node(Node *node){
  while (node->left_child != NULL){
    node = node->left_child;
  }
  return node;
}

Node* delete(Node *root, int value){
  if (root == NULL){
    return NULL;
  }
  if (value < root->value){
    root->left_child = delete(root->left_child, value);
    printf("Woops, value %d was not found in tree!\n",value);
  }
  else if (value > root->value){
    root->right_child = delete(root->right_child, value);
    printf("Oops, value %d was not found in tree!\n",value);
  }
  else{
    if (root->left_child == NULL && root->right_child == NULL){
      free(root);
      printf("Successfully deleted value %d from the tree!\n", value);
      return NULL;
    }
    else if (root->left_child == NULL){
      Node *temp = root->right_child;
      free(root);
      printf("Successfully deleted value %d from the tree!\n", value);
      return temp;
    }
    else if (root->right_child == NULL){
      Node *temp = root->left_child;
      free(root);
      printf("Successfully deleted value %d from the tree!\n", value);
      return temp;
    }
    else{
      Node *temp = find_minimum_value_node(root->right_child);
      root->value = temp->value;
      root->right_child = delete(root->right_child, temp->value);
      printf("Successfully deleted value %d from the tree!\n", value);
    }
  }
  return root;
}

int main(){
  Node *root = NULL;
  insert(&root, 6);
  insert(&root, 2);
  insert(&root, 3);
  insert(&root, 7);
  insert(&root, 1);
  insert(&root, 9);
  printf("\nIn-order traversal of the binary search tree: ");
  print_in_order(root);
  printf("\n");
  int value_to_find = 9;
  if (check_if_value_exists(root, value_to_find)){
    printf("The value %d exists in the tree.\n", value_to_find);
  }
  else{
    printf("The value %d does not exist in the tree.\n", value_to_find);
  }
  root = delete(root, 3);
  printf("In-order traversal of the binary search tree after deletion: ");
  print_in_order(root);
  printf("\n");
  return 0;
}