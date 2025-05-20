//FormAI DATASET v1.0 Category: Binary search trees ; Style: curious
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left_child;
    struct node *right_child;
}Node;

Node* new_node(int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->left_child=NULL;
    node->right_child=NULL;
    return node;
}

Node* insert(Node* root,int data){
    if(root==NULL){
        return new_node(data);
    }
    if(data<root->data){
        root->left_child=insert(root->left_child,data);
    }
    else if(data>root->data){
        root->right_child=insert(root->right_child,data);
    }
    return root;
}

Node* search(Node* root,int data){
    if(root==NULL || root->data==data){
        return root;
    }
    else if(data<root->data){
        return search(root->left_child,data);
    }
    else{
        return search(root->right_child,data);
    }
}

Node* find_min(Node* root){
    while(root->left_child!=NULL){
        root=root->left_child;
    }
    return root;
}

Node* delete(Node* root,int data){
    if(root==NULL){
        return root;
    }
    if(data<root->data){
        root->left_child=delete(root->left_child,data);
    }
    else if(data>root->data){
        root->right_child=delete(root->right_child,data);
    }
    else{
        if(root->left_child==NULL && root->right_child==NULL){
            free(root);
            root=NULL;
        }
        else if(root->left_child==NULL){
            Node* temp=root;
            root=root->right_child;
            free(temp);
        }
        else if(root->right_child==NULL){
            Node* temp=root;
            root=root->left_child;
            free(temp);
        }
        else{
            Node* temp=find_min(root->right_child);
            root->data=temp->data;
            root->right_child=delete(root->right_child,temp->data);
        }
    }
    return root;
}

void inorder_traversal(Node* root){
    if(root==NULL){
        return;
    }
    inorder_traversal(root->left_child);
    printf("%d ",root->data);
    inorder_traversal(root->right_child);
}

int main(){
    Node* root=NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
    printf("BST Inorder Traversal: ");
    inorder_traversal(root);
    printf("\n");
    Node* find=search(root,40);
    if(find==NULL){
        printf("Element not in BST\n");
    }
    else{
        printf("Element found in BST\n");
    }
    printf("Deleting node with one child...\n");
    root=delete(root,40);
    printf("BST Inorder Traversal: ");
    inorder_traversal(root);
    printf("\n");
    printf("Deleting node with two children...\n");
    root=delete(root,50);
    printf("BST Inorder Traversal: ");
    inorder_traversal(root);
    printf("\n");
    return 0;
}