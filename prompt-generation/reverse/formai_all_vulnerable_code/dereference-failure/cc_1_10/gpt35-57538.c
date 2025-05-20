//FormAI DATASET v1.0 Category: Binary search trees ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// create new node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// insert node
void insertNode(TreeNode** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
    } else if (value < (*root)->value) {
        insertNode(&(*root)->left, value);
    } else {
        insertNode(&(*root)->right, value);
    }
}

// search node
TreeNode* searchNode(TreeNode* root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    } else if (value < root->value) {
        return searchNode(root->left, value);
    } else {
        return searchNode(root->right, value);
    }
}

// traverse inorder
void traverseInorder(TreeNode* root) {
    if (root != NULL) {
        traverseInorder(root->left);
        printf("%d ", root->value);
        traverseInorder(root->right);
    }
}

int main() {
    TreeNode* root = NULL;
    int values[] = {10, 6, 14, 5, 8, 11, 18};

    for (int i = 0; i < sizeof(values)/sizeof(values[0]); i++) {
        insertNode(&root, values[i]);
    }

    printf("Inorder traversal: ");
    traverseInorder(root);
    printf("\n");

    // search for value
    int searchValue = 11;
    TreeNode* foundNode = searchNode(root, searchValue);
    if (foundNode != NULL) {
        printf("%d is found in the tree.\n", searchValue);
    } else {
        printf("%d is not found in the tree.\n", searchValue);
    }

    return 0;
}