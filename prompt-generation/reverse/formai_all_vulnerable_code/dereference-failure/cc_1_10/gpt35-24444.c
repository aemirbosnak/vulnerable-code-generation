//FormAI DATASET v1.0 Category: Binary search trees ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
};

void insert(struct node **root, int data){
    if(*root == NULL){
        *root = newNode(data);
    }
    else{
        if(data < (*root)->data){
            insert(&(*root)->left, data);
        }
        else{
            insert(&(*root)->right, data);
        }
    }
}

struct node *search(struct node *root, int data){
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

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    struct node *root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    printf("Inorder traversal of the binary search tree is: ");
    inorder(root);

    int search_data = 40;
    struct node *result = search(root, search_data);
    if(result == NULL){
        printf("\n%d not found in the binary search tree", search_data);
    }
    else{
        printf("\n%d found in the binary search tree", search_data);
    }

    return 0;
}