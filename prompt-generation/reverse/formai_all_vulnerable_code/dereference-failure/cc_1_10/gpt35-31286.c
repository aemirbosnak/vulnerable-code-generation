//FormAI DATASET v1.0 Category: Binary search trees ; Style: detailed
#include<stdio.h>
#include<stdlib.h>

typedef struct tree_node{
    int data;
    struct tree_node *left;
    struct tree_node *right;
}node;

node* insert(node *root, int data){
    if(root == NULL){
        node *temp = (node*)malloc(sizeof(node));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    
    if(data <= root->data){
        root->left = insert(root->left, data);
    }else{
        root->right = insert(root->right, data);
    }
    
    return root;
}

int search(node *root, int data){
    if(root == NULL){
        return 0;
    }else if(root->data == data){
        return 1;
    }else if(data <= root->data){
        return search(root->left, data);
    }else{
        return search(root->right, data);
    }
}

void inorder_traversal(node *root){
    if(root != NULL){
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main(){
    node *root = NULL;
    
    // inserting nodes into the tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    // performing inorder traversal
    printf("Inorder Traversal: ");
    inorder_traversal(root);
    printf("\n");
    
    // searching for nodes
    if(search(root, 20) == 1){
        printf("Found 20 in the tree.\n");
    }else{
        printf("20 is not present in the tree.\n");
    }
    
    if(search(root, 90) == 1){
        printf("Found 90 in the tree.\n");
    }else{
        printf("90 is not present in the tree.\n");
    }
    
    return 0;
}