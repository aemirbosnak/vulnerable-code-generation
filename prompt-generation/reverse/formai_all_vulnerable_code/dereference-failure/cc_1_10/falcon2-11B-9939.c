//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: detailed
#include <stdio.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

void insert(struct node* root, int data)
{
    if (root == NULL)
    {
        root = (struct node*)malloc(sizeof(struct node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if (data < root->data)
        insert(root->left, data);
    else if (data > root->data)
        insert(root->right, data);
}

void preorder(struct node* root)
{
    if (root!= NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    struct node* root = NULL;
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);
    insert(root, 70);
    insert(root, 80);
    insert(root, 90);
    insert(root, 100);

    printf("Preorder traversal of BST is:\n");
    preorder(root);
    printf("\n");

    return 0;
}