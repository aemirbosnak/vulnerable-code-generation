//FormAI DATASET v1.0 Category: Data structures visualization ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node** root, int data){
    if(*root == NULL){
        *root = createNode(data);
        return;
    }
    if(data < (*root)->data){
        insert(&(*root)->left, data);
    }
    else{
        insert(&(*root)->right, data);
    }
}

void printTree(Node* root, int space){
    if(root == NULL){
        return;
    }
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for(int i = 5; i < space; i++){
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->left, space);
}

int main(){
    Node* root = NULL;
    int data[] = {50, 30, 20, 40, 70, 60, 80};
    int size = sizeof(data)/sizeof(data[0]);
    for(int i = 0; i < size; i++){
        insert(&root, data[i]);
    }
    printTree(root, 0);
    return 0;
}