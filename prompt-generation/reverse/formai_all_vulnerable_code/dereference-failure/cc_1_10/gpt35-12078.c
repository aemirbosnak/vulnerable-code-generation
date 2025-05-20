//FormAI DATASET v1.0 Category: Binary search trees ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int key){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key){
    if(node == NULL){
        return create_node(key);
    }
    if(key < node->data){
        node->left = insert(node->left, key);
    }
    else if(key > node->data){
        node->right = insert(node->right, key);
    }
    return node;
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node* search(struct node* root, int key){
    if (root == NULL || root->data == key){
        return root;
    }
    if (root->data < key){
        return search(root->right, key);
    }
    return search(root->left, key);
}

void main(){
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Binary Search Tree: ");
    inorder(root);
    int key = 50;
    struct node* result = search(root, key);
    if(result == NULL){
        printf("\n%d not found in the tree.\n", key);
    }
    else{
        printf("\n%d found in the tree.\n", result->data);
    }
}