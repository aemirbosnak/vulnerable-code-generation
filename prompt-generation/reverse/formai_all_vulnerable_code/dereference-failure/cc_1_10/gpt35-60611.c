//FormAI DATASET v1.0 Category: Binary search trees ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

void insert(struct node **root, int data) {
    if(*root == NULL) {
        *root = createNode(data);
    }
    
    else if(data < (*root)->data) {
        insert(&((*root)->left), data);
    }
    
    else {
        insert(&((*root)->right), data);
    }
}

void inorderTraversal(struct node *root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        printf("%d\t", root->data);
        inorderTraversal(root->right);
    }
}

struct node* search(struct node *root, int data) {
    if(root == NULL || root->data == data) {
        return root;
    }
    
    else if(data < root->data) {
        return search(root->left, data);
    }
    
    else {
        return search(root->right, data);
    }
}

int main() {
    struct node *root = NULL;
    int arr[] = {50, 25, 75, 15, 30, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    for(int i=0; i<n; i++) {
        insert(&root, arr[i]);
    }
    
    printf("\nInorder Traversal: ");
    inorderTraversal(root);
    printf("\n");
    
    int findNumber = 80;
    
    struct node *foundNode = search(root, findNumber);
    
    if(foundNode == NULL) {
        printf("%d not found in the tree.\n", findNumber);
    } else {
        printf("%d found in the tree.\n", findNumber);
    }
    
    return 0;
}