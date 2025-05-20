//FormAI DATASET v1.0 Category: Binary search trees ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

struct bst_node{
    int data;
    struct bst_node* left;
    struct bst_node* right;
};

typedef struct bst_node bst_node_t;

bst_node_t* create_node(int data){
    bst_node_t* new_node = (bst_node_t*) malloc(sizeof(bst_node_t));

    if(new_node == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

bst_node_t* insert_node(bst_node_t* root, int data){
    if(root == NULL){
        return create_node(data);
    }

    if(data < root->data){
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }

    return root;
}

bst_node_t* search_node(bst_node_t* root, int key){
    if(root == NULL || root->data == key){
        return root;
    }

    if(key < root->data){
        return search_node(root->left, key);
    }

    return search_node(root->right, key);
}

void inorder_traversal(bst_node_t* root){
    if(root != NULL){
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main(){
    bst_node_t* root = NULL;

    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);

    printf("Inorder Traversal: ");
    inorder_traversal(root);

    int key = 20;
    bst_node_t* result = search_node(root, key);

    if(result == NULL){
        printf("\n%d does not exist in the BST\n", key);
    } else {
        printf("\n%d exists in the BST\n", key);
    }

    key = 90;
    result = search_node(root, key);

    if(result == NULL){
        printf("%d does not exist in the BST\n", key);
    } else {
        printf("%d exists in the BST\n", key);
    }

    return 0;
}