//FormAI DATASET v1.0 Category: Binary search trees ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int data){
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

struct node* search(struct node* root, int data){
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

void inorderTraversal(struct node* root){
    if(root != NULL){
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main(){
    struct node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    
    printf("Inorder traversal of tree: ");
    inorderTraversal(root);
    printf("\n\n");
    
    int searchKey = 15;
    struct node* searchedNode = search(root, searchKey);
    
    if(searchedNode == NULL){
        printf("Element %d not found in tree.", searchKey);
    }
    else{
        printf("Element %d found in tree.", searchKey);
    }
    return 0;
}