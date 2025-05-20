//FormAI DATASET v1.0 Category: Binary search trees ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node* createNode(int data){
    node *newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insertNode(node *root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data < root->data){
        root->left = insertNode(root->left, data);
    }
    else if(data > root->data){
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inorderTraversal(node *root){
    if(root != NULL){
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

node* searchNode(node *root, int data){
    if(root == NULL){
        printf("Node not found\n");
        return NULL;
    }
    if(data == root->data){
        printf("Node found\n");
        return root;
    }
    else if(data < root->data){
        return searchNode(root->left, data);
    }
    else{
        return searchNode(root->right, data);
    }
}

int main(){
    int option, value;
    node *root = NULL;

    do{
        printf("\nBinary Search Tree Operations\n");
        printf("****************************\n");
        printf("1. Insert Node\n");
        printf("2. Search Node\n");
        printf("3. Inorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Enter the value you want to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("Enter the value you want to search: ");
                scanf("%d", &value);
                searchNode(root, value);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Please enter a valid option.\n");
        }
    }while(option != 4);
    return 0;
}