//FormAI DATASET v1.0 Category: Binary search trees ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* node, int data){
    if(node == NULL){
        return newNode(data);
    }
    if(data < node->data){
        node->left = insert(node->left, data);
    }
    else if(data > node->data){
        node->right = insert(node->right, data);
    }
    return node;
}

struct Node* search(struct Node* node, int data){
    if(node == NULL){
        return NULL;
    }
    if(data == node->data){
        return node;
    }
    else if(data < node->data){
        return search(node->left, data);
    }
    else{
        return search(node->right, data);
    }
}

void inorder(struct Node* node){
    if(node == NULL){
        return;
    }
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

int main(){
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);

    printf("\nSearch for node 70...\n");
    if(search(root, 70) != NULL){
        printf("Node 70 is found!\n");
    }
    else{
        printf("Node 70 is not found.\n");
    }

    printf("Search for node 90...\n");
    if(search(root, 90) != NULL){
        printf("Node 90 is found!\n");
    }
    else{
        printf("Node 90 is not found.\n");
    }

    return 0;
}