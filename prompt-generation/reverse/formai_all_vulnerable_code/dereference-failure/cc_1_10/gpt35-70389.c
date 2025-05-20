//FormAI DATASET v1.0 Category: Binary search trees ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

struct node* insert(struct node* node, int data){
    if(node==NULL){
        return(newNode(data));
    }else{
        if(data <= node->data){
            node->left = insert(node->left,data);
        }else{
            node->right = insert(node->right,data);
        }
        return(node);
    }
}

struct node* search(struct node* node, int data){
    if(node==NULL || node->data==data){
        return(node);
    }else if(data <= node->data){
        return(search(node->left,data));
    }else{
        return(search(node->right,data));
    }
} 

int main(){
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the given tree is: ");
    inorder(root);

    struct node* result = search(root, 70);
    if(result==NULL){
        printf("\nElement not found\n");
    }else{
        printf("\nElement found: %d\n", result->data);
    }

    return 0;
}