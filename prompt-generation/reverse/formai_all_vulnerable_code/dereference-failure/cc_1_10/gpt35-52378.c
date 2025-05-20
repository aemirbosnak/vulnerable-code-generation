//FormAI DATASET v1.0 Category: Binary search trees ; Style: brave
#include<stdio.h>  
#include<stdlib.h> 

struct node{  
    int data;  
    struct node *leftChild;  
    struct node *rightChild;  
};  

struct node *root = NULL;

struct node* insert(struct node *root, int data){  
    if(root == NULL){  
        root = (struct node*)malloc(sizeof(struct node));  
        root->data = data;  
        root->leftChild = NULL;  
        root->rightChild = NULL;  
    }  
    else if(data <= root->data){  
        root->leftChild = insert(root->leftChild,data);  
    }  
    else if(data > root->data){  
        root->rightChild = insert(root->rightChild,data);  
    }  
    return root;  
}  

struct node* search(struct node *root,int data){  
    if(root == NULL){  
        return NULL;  
    }  
    else if(root->data == data){  
        return root;  
    }  
    else if(data <= root->data){  
        return search(root->leftChild, data);  
    }  
    else{  
        return search(root->rightChild,data);  
    }  
}  

void preOrderTraversal(struct node *root) {  
    if(root != NULL) {  
        printf("%d ",root->data);  
        preOrderTraversal(root->leftChild);  
        preOrderTraversal(root->rightChild);  
    }  
}  

void inOrderTraversal(struct node *root) {  
    if(root != NULL) {  
        inOrderTraversal(root->leftChild);  
        printf("%d ",root->data);  
        inOrderTraversal(root->rightChild);  
    }  
}  

void postOrderTraversal(struct node *root) {  
    if(root != NULL) {  
        postOrderTraversal(root->leftChild);  
        postOrderTraversal(root->rightChild);  
        printf("%d ", root->data);  
    }  
}  

int main() {  
    root = insert(root, 5);  
    root = insert(root, 2);  
    root = insert(root, 4);  
    root = insert(root, 7);  
    root = insert(root, 6);  
    root = insert(root, 8);  

    printf("Preorder traversal of binary search tree is:\n");  
    preOrderTraversal(root);  

    printf("\nInorder traversal of binary search tree is:\n");  
    inOrderTraversal(root);  

    printf("\nPostorder traversal of binary search tree is:\n");  
    postOrderTraversal(root);  

    struct node *searchResult = search(root, 4);  
    if(searchResult == NULL){
        printf("\nElement not found in the binary search tree\n");  
    }  
    else{  
        printf("\nElement %d is present in the binary search tree\n", searchResult->data);  
    }

    return 0;  
}