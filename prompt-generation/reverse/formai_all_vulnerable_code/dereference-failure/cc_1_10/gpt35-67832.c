//FormAI DATASET v1.0 Category: Binary search trees ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

struct tree_node {
    int data;
    struct tree_node* left;
    struct tree_node* right;
};

struct tree_node* create_new_node(int val){
    struct tree_node* new_node = malloc(sizeof(struct tree_node));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct tree_node* insert_node(struct tree_node* root, int val){
    if(root == NULL){
        return create_new_node(val);
    }
    else if(val < root->data){
        root->left = insert_node(root->left, val);
    }
    else if(val > root->data){
        root->right = insert_node(root->right, val);
    }
    return root;
}

void pre_order_traversal(struct tree_node* root) {
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

void in_order_traversal(struct tree_node* root){
    if(root == NULL){
        return;
    }
    in_order_traversal(root->left);
    printf("%d ", root->data);
    in_order_traversal(root->right);
}

void post_order_traversal(struct tree_node* root){
    if(root == NULL){
        return;
    }
    post_order_traversal(root->left);
    post_order_traversal(root->right);
    printf("%d ", root->data);
}

int main(){
    struct tree_node* root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
   
    printf("Pre-order traversal: ");
    pre_order_traversal(root);
    printf("\n");
  
    printf("In-order traversal: ");
    in_order_traversal(root);
    printf("\n");
   
    printf("Post-order traversal: ");
    post_order_traversal(root);
    printf("\n");
    
    return 0;
}