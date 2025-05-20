//FormAI DATASET v1.0 Category: Binary search trees ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insertNode(struct node *root, int val){
    if(root == NULL){
        return createNode(val);
    }
    if(val <= root->data){
        root->left = insertNode(root->left, val);
    }
    else{
        root->right = insertNode(root->right, val);
    }
    return root;
}

struct node* findMin(struct node *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

struct node* deleteNode(struct node *root, int val){
    if(root == NULL){
        return root;
    }
    else if(val < root->data){
        root->left = deleteNode(root->left, val);
    }
    else if(val > root->data){
        root->right = deleteNode(root->right, val);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if(root->left == NULL){
            struct node *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL){
            struct node *temp = root;
            root = root->left;
            free(temp);
        }
        else{
            struct node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void inorderTraversal(struct node *root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main(){
    struct node *root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);

    printf("Inorder Traversal: ");
    inorderTraversal(root);

    printf("\n\nDeleting 20...\n");
    root = deleteNode(root, 20);
    printf("Inorder Traversal: ");
    inorderTraversal(root);

    printf("\n\nDeleting 30...\n");
    root = deleteNode(root, 30);
    printf("Inorder Traversal: ");
    inorderTraversal(root);

    printf("\n\nAdding 60...\n");
    insertNode(root, 60);
    printf("Inorder Traversal: ");
    inorderTraversal(root);

    return 0;
}