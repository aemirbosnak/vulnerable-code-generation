//FormAI DATASET v1.0 Category: Binary search trees ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* left;
  struct node* right;
};

struct node* create_node(int data){
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

struct node* insert_node(struct node* root, int data){
  if(root == NULL){
    return create_node(data);
  }
  
  if(data < root->data){
    root->left = insert_node(root->left, data);
  }else if(data > root->data){
    root->right = insert_node(root->right, data);
  }
  
  return root;
}

void inorder_traversal(struct node* root){
  if(root!= NULL){
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
  }
}

struct node* search_node(struct node* root, int data){
  if(root== NULL || root->data == data){
    return root;
  }
  
  if(data < root->data){
    return search_node(root->left, data);
  }else{
    return search_node(root->right, data);
  }
}

int main(){
  struct node* root = NULL;
  root = insert_node(root, 50);
  insert_node(root, 30);
  insert_node(root, 20);
  insert_node(root, 40);
  insert_node(root, 70);
  insert_node(root, 60);
  insert_node(root, 80);
  inorder_traversal(root);
  
  struct node* found_node = search_node(root, 40);
  if(found_node!= NULL){
    printf("\n%d is found in the tree!\n", found_node->data);
  }else{
    printf("\n40 is not found in the tree.\n");
  }
  
  found_node = search_node(root, 100);
  if(found_node!= NULL){
    printf("%d is found in the tree!", found_node->data);
  }else{
    printf("100 is not found in the tree.");
  }
  
  return 0;
}