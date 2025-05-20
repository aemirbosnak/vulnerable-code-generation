//FormAI DATASET v1.0 Category: Binary search trees ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* createNode(int data){
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct node* insert(struct node* root,int data){
    if(root==NULL){
        root=createNode(data);
        return root;
    }
    else if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int search(struct node* root,int data){
    if(root==NULL){
        return -1;
    }
    else if(root->data==data){
        return 1;
    }
    else if(data<root->data){
        return search(root->left,data);
    }
    else if(data>root->data){
        return search(root->right,data);
    }
    return -1;
}

int main(){
    struct node* root=NULL;
    root=insert(root,10);
    insert(root,5);
    insert(root,15);
    insert(root,2);
    insert(root,7);
    insert(root,12);
    insert(root,20);
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");
    int n=5;
    if(search(root,n)==1){
        printf("Found\n");
    }
    else{
        printf("Not Found\n");
    }
    return 0;
}