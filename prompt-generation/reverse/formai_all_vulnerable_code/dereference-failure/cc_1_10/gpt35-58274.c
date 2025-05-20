//FormAI DATASET v1.0 Category: Binary search trees ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

struct bstNode {
    int data;
    struct bstNode* left;
    struct bstNode* right;
};

struct bstNode* createNode(int data) {
    struct bstNode* newNode = (struct bstNode*) malloc(sizeof(struct bstNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct bstNode* insert(struct bstNode* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(struct bstNode* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    printf("Welcome to my binary search tree program! I hope this surprises you :)\n");
    
    struct bstNode* root = NULL;
    root = insert(root, 10);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 11);
    root = insert(root, 15);
    
    printf("The inorder traversal of the binary search tree is: ");
    inorder(root);
    
    printf("\nI hope you enjoyed this program! Have a nice day :)\n");
    return 0;
}