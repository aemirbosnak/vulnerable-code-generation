//FormAI DATASET v1.0 Category: Binary search trees ; Style: complete
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNewNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct Node* root, int val){
    if(root == NULL){
        root = createNewNode(val);
        return;
    }

    if(val < root->data){
        if(root->left == NULL){
            root->left = createNewNode(val);
        }else{
            insert(root->left, val);
        }
    }else{
        if(root->right == NULL){
            root->right = createNewNode(val);
        }else{
            insert(root->right, val);
        }
    }
}

void inorderTraversal(struct Node* root){
    if(root != NULL){
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int search(struct Node* root, int val){
    if(root == NULL){
        return 0;
    }else if(root->data == val){
        return 1;
    }else if(root->data > val){
        return search(root->left, val);
    }else{
        return search(root->right, val);
    }
}

int main(){
    struct Node* root = createNewNode(10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    insert(root, 12);
    insert(root, 20);
    printf("Inorder Traversal of Binary Search Tree: ");
    inorderTraversal(root);
    printf("\n");
    int val = 7;
    if(search(root, val)){
        printf("%d found in the BST.\n", val);
    }else{
        printf("%d not found in the BST.\n", val);
    }
    val = 25;
    if(search(root, val)){
        printf("%d found in the BST.\n", val);
    }else{
        printf("%d not found in the BST.\n", val);
    }
    return 0;
}