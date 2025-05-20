//FormAI DATASET v1.0 Category: Binary search trees ; Style: calm
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left_child;
    struct node *right_child;
};

typedef struct node node_t;

void create_tree(node_t **root, int data){
    node_t *temp_node = NULL;
    if(!(*root)){
        temp_node = (node_t*)malloc(sizeof(node_t));
        temp_node->left_child = NULL;
        temp_node->right_child = NULL;
        temp_node->data = data;
        *root = temp_node;
        return;
    }

    if(data < (*root)->data)
        create_tree(&(*root)->left_child, data);
    else if(data > (*root)->data)
        create_tree(&(*root)->right_child, data);
}

void inorder(node_t *root){
    if(!root)
        return;
    inorder(root->left_child);
    printf("%d ", root->data);
    inorder(root->right_child);
}

void preorder(node_t *root){
    if(!root)
        return;
    printf("%d ", root->data);
    preorder(root->left_child); 
    preorder(root->right_child);
}

void postorder(node_t *root){
    if(!root)
        return;
    postorder(root->left_child); 
    postorder(root->right_child);
    printf("%d ", root->data);
}

int main(){
    node_t *root = NULL;
    int n, data;

    printf("Enter the number of elements in the tree: ");
    scanf("%d", &n);

    printf("Enter the elements of the tree:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &data);
        create_tree(&root, data);
    }

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    return 0;
}