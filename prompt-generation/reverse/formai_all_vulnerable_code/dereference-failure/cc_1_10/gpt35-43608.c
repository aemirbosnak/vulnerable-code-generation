//FormAI DATASET v1.0 Category: Binary search trees ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
} Node;

Node* newNode(int value)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

Node* insert(Node* root, int value)
{
    if (root == NULL) return newNode(value);

    if (value < root->value)
        root->left  = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d -> ", root->value);
        inorder(root->right);
    }
}

Node* search(Node* root, int value)
{
    if (root == NULL || root->value == value)
       return root;

    if (root->value < value)
       return search(root->right, value);

    return search(root->left, value);
}

int main()
{
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("\nBinary Search Tree Inorder Traversal:\n");
    inorder(root);

    int value = 20;
    Node* node = search(root, value);
    if(node != NULL)
        printf("\n%d is present in the binary search tree\n", value);
    else
        printf("\n%d is not present in the binary search tree\n", value);

    value = 90;
    node = search(root, value);
    if(node != NULL)
        printf("%d is present in the binary search tree\n", value);
    else
        printf("\n%d is not present in the binary search tree\n", value);

    return 0;
}