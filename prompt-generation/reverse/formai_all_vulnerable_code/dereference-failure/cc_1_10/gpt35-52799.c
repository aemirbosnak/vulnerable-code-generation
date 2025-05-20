//FormAI DATASET v1.0 Category: Binary search trees ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct node* insert_node(struct node* root, int data){
    if(root==NULL){
        root = create_node(data);
    }
    else if(data < root->data){
        root->left = insert_node(root->left, data);
    }
    else if(data > root->data){
        root->right = insert_node(root->right, data);
    }
    return root;
}

void in_order(struct node* root){
    if(root==NULL){
        return;
    }
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}

int find_min(struct node* root){
    struct node* current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return current->data;
}

int find_max(struct node* root){
    struct node* current = root;
    while(current->right != NULL){
        current = current->right;
    }
    return current->data;
}

int main(){
    struct node* root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);

    printf("In-order traversal of the binary search tree: ");
    in_order(root);
    printf("\n");

    printf("Minimum element in the binary search tree: %d\n", find_min(root));
    printf("Maximum element in the binary search tree: %d\n", find_max(root));

    return 0;
}