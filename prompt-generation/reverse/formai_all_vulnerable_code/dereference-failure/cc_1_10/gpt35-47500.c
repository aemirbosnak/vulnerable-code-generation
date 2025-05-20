//FormAI DATASET v1.0 Category: Binary search trees ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

struct tree_node{
    int val;
    struct tree_node* left;
    struct tree_node* right;
};

struct tree_node* create_node(int val){
    struct tree_node* node = (struct tree_node*)malloc(sizeof(struct tree_node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(struct tree_node** root, int val){
    if(*root == NULL){
        *root = create_node(val);
    }
    else if(val <= (*root)->val){
        insert(&((*root)->left), val);
    }
    else{
        insert(&((*root)->right), val);
    }
}

void inorder_traversal(struct tree_node* root){
    if(root == NULL){
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->val);
    inorder_traversal(root->right);
}

struct tree_node* search(struct tree_node* root, int val){
    if(root == NULL || root->val == val){
        return root;
    }
    else if(val < root->val){
        return search(root->left, val);
    }
    else{
        return search(root->right, val);
    }
}

int main(){
    struct tree_node* root = NULL;
    insert(&root, 8);
    insert(&root, 3);
    insert(&root, 10);
    insert(&root, 1);
    insert(&root, 6);
    insert(&root, 14);
    insert(&root, 4);
    insert(&root, 7);
    insert(&root, 13);
    
    printf("Inorder traversal:\n");
    inorder_traversal(root);
    
    printf("\n\nSearching for 6...\n");
    struct tree_node* node = search(root, 6);
    if(node == NULL){
        printf("Not found\n");
    }
    else{
        printf("Found: %d\n", node->val);
    }
    
    printf("\nSearching for 2...\n");
    node = search(root, 2);
    if(node == NULL){
        printf("Not found\n");
    }
    else{
        printf("Found: %d\n", node->val);
    }
    
    return 0;
}