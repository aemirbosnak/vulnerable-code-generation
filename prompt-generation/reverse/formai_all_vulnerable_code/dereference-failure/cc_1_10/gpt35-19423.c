//FormAI DATASET v1.0 Category: Binary search trees ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>

//defining structure for binary search tree node
struct bst_node{
    int data;
    struct bst_node *left;
    struct bst_node *right;
};

//function to create a new bst node
struct bst_node* createNode(int value){
    struct bst_node* newNode = (struct bst_node*) malloc(sizeof(struct bst_node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//function to insert a node in a bst
struct bst_node* insert(struct bst_node* root, int value){
    if(root==NULL){
        return createNode(value);
    }
    if(value <= root->data){
        root->left = insert(root->left, value);
    }else{
        root->right = insert(root->right, value);
    }
    return root;
}

//function to search for a value in a bst
struct bst_node* search(struct bst_node* root, int value){
    if(root == NULL || root->data == value){
        return root;
    }
    if(value < root->data){
        return search(root->left, value);
    }
    return search(root->right, value);
}

//function for inorder traversal of a bst
void inorder(struct bst_node* root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main(){
    struct bst_node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder Traversal of the given BST : ");
    inorder(root);
    printf("\n");
    int search_val = 60;
    struct bst_node* search_node = search(root, search_val);
    if(search_node!=NULL){
        printf("Value %d found in given BST",search_node->data);
    }else{
        printf("Value %d not found in given BST",search_val);
    }
    return 0;
}