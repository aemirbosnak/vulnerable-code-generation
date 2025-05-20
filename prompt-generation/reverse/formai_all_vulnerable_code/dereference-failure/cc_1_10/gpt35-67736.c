//FormAI DATASET v1.0 Category: Database Indexing System ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Node* insert(Node* root, int data){
    if(root == NULL){
        root = createNode(data);
    }
    else if(data <= root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

Node* search(Node* root, int data){
    if(root == NULL){
        return NULL;
    }
    else if(root->data == data){
        return root;
    }
    else if(data <= root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

void inOrderTraversal(Node* root){
    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main(){
    Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 9);
    root = insert(root, 1);
    root = insert(root, 4);
    
    inOrderTraversal(root);
    printf("\n");
    
    Node* searchResult = search(root, 4);
    if(searchResult != NULL){
        printf("%d is found!\n", searchResult->data);
    }
    else{
        printf("Not found :(\n");
    }
    return 0;
}