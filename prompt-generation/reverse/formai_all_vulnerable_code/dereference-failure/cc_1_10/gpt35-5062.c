//FormAI DATASET v1.0 Category: Binary search trees ; Style: grateful
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int value){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int value){
    if(root == NULL){
        return createNode(value);
    }
    if(value < root->data){
        root->left = insert(root->left, value);
    }
    else{
        root->right = insert(root->right, value);
    }
    return root;
}

struct node* search(struct node* root, int value){
    if(root == NULL || root->data == value){
        return root;
    }
    else if(value < root->data){
        return search(root->left, value);
    }
    else{
        return search(root->right, value);
    }
}

void inorderTraversal(struct node* root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main(){
    struct node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 9);
    int value = 7;
    struct node* result = search(root, value);
    if(result == NULL){
        printf("Element not found.\n");
    }
    else{
        printf("Element found.\n");
    }
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    return 0;
}