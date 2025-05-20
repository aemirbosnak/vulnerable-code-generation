//FormAI DATASET v1.0 Category: Binary search trees ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *left_child, *right_child;
};

struct node *createNode(int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = data;
    new_node->left_child = new_node->right_child = NULL;
    return new_node;
}

struct node *insert(struct node *root, int value){
    if(root==NULL){
        return createNode(value);
    }
    if(value < root->value){
        root->left_child = insert(root->left_child, value);
    } else if(value > root->value){
        root->right_child = insert(root->right_child, value);
    }
    return root;
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left_child);
        printf("%d ", root->value);
        inorder(root->right_child);
    }
}

struct node *search(struct node *root, int value){
    if(root==NULL || root->value==value){
        return root;
    }
    if(value < root->value){
        return search(root->left_child, value);
    }
    return search(root->right_child, value);
}

int main(){
    struct node *root = NULL;
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 5);
    insert(root, 30);
    insert(root, 15);
    insert(root, 25);
    printf("Inorder traversal of the binary search tree is: ");
    inorder(root);
    printf("\n");
    int search_key = 25;
    struct node *search_res = search(root, search_key);
    printf("Searched element %d is present in the binary search tree at location %d\n", search_key, search_res);
    return 0;
}