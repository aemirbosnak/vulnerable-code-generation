//FormAI DATASET v1.0 Category: Binary search trees ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}Node;

Node* new_node(int key){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert_node(Node* node, int key){
    if(node == NULL){
        return new_node(key);
    }
    if(key < node->data){
        node->left = insert_node(node->left, key);
    }
    else if(key > node->data){
        node->right = insert_node(node->right, key);
    }
    return node;
}

void inorder_traversal(Node* node){
    if(node != NULL){
        inorder_traversal(node->left);
        printf("%d ", node->data);
        inorder_traversal(node->right);
    }
}

void search_node(Node* node, int key){
    if(node == NULL){
        printf("Node not found\n");
    }
    else if(node->data == key){
        printf("Node found\n");
    }
    else if(key < node->data){
        search_node(node->left, key);
    }
    else{
        search_node(node->right, key);
    }
}

int main(){

    Node* root = NULL;

    root = insert_node(root, 10);
    insert_node(root, 6);
    insert_node(root, 18);
    insert_node(root, 3);
    insert_node(root, 8);
    insert_node(root, 15);
    insert_node(root, 20);

    printf("Inorder traversal of the binary search tree is: ");
    inorder_traversal(root);

    int key = 15;
    printf("\nSearching for node with key %d... ", key);
    search_node(root, key);

    return 0;
}