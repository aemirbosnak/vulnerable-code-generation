//FormAI DATASET v1.0 Category: Binary search trees ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insertNode(TreeNode** node, int data) {
    if (*node == NULL) {
        *node = createNode(data);
        printf("Inserted %d\n", data);
    }
    else if (data < (*node)->data) {
        insertNode(&(*node)->left, data);
    }
    else if (data > (*node)->data) {
        insertNode(&(*node)->right, data);
    }
    else {
        printf("Cannot insert duplicate data %d\n", data);
    }
}

void inorder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void deleteTree(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    printf("Deleting node: %d\n", node->data);
    free(node);
}

int main() {
    TreeNode* root = NULL;
    insertNode(&root, 50);
    insertNode(&root, 30);
    insertNode(&root, 70);
    insertNode(&root, 20);
    insertNode(&root, 40);
    insertNode(&root, 60);
    insertNode(&root, 80);
    printf("Inorder traversal of the BST: ");
    inorder(root);
    printf("\n");
    deleteTree(root);
    return 0;
}