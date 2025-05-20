//FormAI DATASET v1.0 Category: Binary search trees ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node {
    int data;
    struct bst_node* left;
    struct bst_node* right;
} bst_node;

bst_node* create_node(int data) {
    bst_node* node = (bst_node*)malloc(sizeof(bst_node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bst_node* insert_node(bst_node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }

    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }

    return root;
}

void traverse_bst(bst_node* root) {
    if (root != NULL) {
        traverse_bst(root->left);
        printf("%d ", root->data);
        traverse_bst(root->right);
    }
}

bst_node* search_bst(bst_node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search_bst(root->left, data);
    } else {
        return search_bst(root->right, data);
    }
}

int main() {
    bst_node* root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);

    printf("In-order traversal of the BST:\n");
    traverse_bst(root);
    printf("\n");

    int search_num = 60;
    bst_node* search_result = search_bst(root, search_num);
    if (search_result != NULL) {
        printf("%d is found in the BST!\n", search_num);
    } else {
        printf("%d is not found in the BST.\n", search_num);
    }

    return 0;
}