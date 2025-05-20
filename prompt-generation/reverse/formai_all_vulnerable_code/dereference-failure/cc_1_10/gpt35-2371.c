//FormAI DATASET v1.0 Category: Binary search trees ; Style: random
#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

BSTNode* create_node(int data) {
    BSTNode* node = (BSTNode*) malloc(sizeof(BSTNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int insert(BSTNode** root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
        return 1;
    }

    if (data < (*root)->data) {
        return insert(&(*root)->left, data);
    }

    if (data > (*root)->data) {
        return insert(&(*root)->right, data);
    }

    return 0;
}

BSTNode* search(BSTNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    }

    return search(root->right, data);
}

void inorder(BSTNode* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    BSTNode* root = NULL;

    insert(&root, 5);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 8);
    insert(&root, 6);

    printf("Inorder traversal of the BST:\n");
    inorder(root);

    int key = 8;
    BSTNode* result = search(root, key);

    if (result == NULL) {
        printf("\n%d doesn't exist in the BST.\n", key);
    } else {
        printf("\n%d exists in the BST.\n", key);
    }

    return 0;
}