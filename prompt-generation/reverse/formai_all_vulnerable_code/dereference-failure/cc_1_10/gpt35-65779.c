//FormAI DATASET v1.0 Category: Binary search trees ; Style: random
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return(new_node);
}

void inOrder(struct node* node)
{
    if (node == NULL)
        return;
    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}

struct node* insert(struct node* node, int data)
{
    if (node == NULL) 
        return(newNode(data));
    else
    {
        if (data <= node->data) 
            node->left = insert(node->left, data);
        else 
            node->right = insert(node->right, data);
        return(node); 
    }
}

int main()
{
    int i = 0, num[7] = { 3, 2, 7, 6, 8, 5, 10 };
    struct node* root = NULL;
 
    root = insert(root, num[0]);
    for (i = 1; i < 7; i++)
        insert(root, num[i]);

    printf("\nInorder traversal of binary search tree is:\n");
    inOrder(root);

    return 0;
}