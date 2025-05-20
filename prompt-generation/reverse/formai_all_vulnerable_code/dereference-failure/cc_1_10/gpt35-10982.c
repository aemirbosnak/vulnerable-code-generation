//FormAI DATASET v1.0 Category: Binary search trees ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
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
    if(root == NULL || root->data == data){
        return root;
    }
    else if(data < root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

void inorder(Node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 30);

    printf("Inorder Traversal: ");
    inorder(root);

    Node* result = search(root, 15);
    if(result == NULL) printf("\nElement not found\n");
    else printf("\nElement found: %d\n", result->data);

    return 0;
}