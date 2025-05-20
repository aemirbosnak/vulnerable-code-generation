//FormAI DATASET v1.0 Category: Binary search trees ; Style: romantic
#include<stdio.h>
#include<stdlib.h>

struct BST{
    int data;
    struct BST *left;
    struct BST *right;
};

struct BST *root = NULL;

struct BST* createNode(int val){
    struct BST* newNode = (struct BST*)malloc(sizeof(struct BST));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(struct BST *temp, struct BST* newNode){
    if(root == NULL){
        root = newNode;
        return;
    }
    if(temp->data > newNode->data){
        if(temp->left == NULL){
            temp->left = newNode;
            return;
        }
        insertNode(temp->left, newNode);
    }
    else{
        if(temp->right == NULL){
            temp->right = newNode;
            return;
        }
        insertNode(temp->right, newNode);
    }
}

void inorderTraversal(struct BST* temp){
    if(temp != NULL){
        inorderTraversal(temp->left);
        printf("%d ", temp->data);
        inorderTraversal(temp->right);
    }
}

int main(){
    int n, val;
    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &val);
        struct BST* newNode = createNode(val);
        insertNode(root, newNode);
    }
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    return 0;
}