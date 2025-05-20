//FormAI DATASET v1.0 Category: Binary search trees ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

struct bstNode
{
    int data;
    struct bstNode *left;
    struct bstNode *right;
};

struct bstNode *createNode(int data)
{
    struct bstNode *node;
    node = (struct bstNode *) malloc(sizeof(struct bstNode));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

struct bstNode *insertNode(struct bstNode *root, int data)
{
    if (!root)
    {
        return createNode(data);
    }

    if (data < root -> data)
    {
        root -> left = insertNode(root -> left, data);
    }
    else if (data > root -> data)
    {
        root -> right = insertNode(root -> right, data);
    }

    return root;
}

void inorderTraversal(struct bstNode *root)
{
    if (root)
    {
        inorderTraversal(root -> left);
        printf("%d -> ", root -> data);
        inorderTraversal(root -> right);
    }
}

int main()
{
    struct bstNode *root;
    root = NULL;

    root = insertNode(root, 10);
    insertNode(root, 20);
    insertNode(root, 15);
    insertNode(root, 3);
    insertNode(root, 7);

    printf("Inorder traversal of BST:\n");
    inorderTraversal(root);

    return 0;
}