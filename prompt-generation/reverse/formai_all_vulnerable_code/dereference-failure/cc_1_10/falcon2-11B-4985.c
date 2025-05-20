//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: unmistakable
#include <stdio.h>

// Node struct
struct node
{
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node* newNode(int data)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node
void insert(struct node* root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
    }
    else if (data < root->data)
    {
        insert(root->left, data);
    }
    else if (data > root->data)
    {
        insert(root->right, data);
    }
}

// Function to search a node
int search(struct node* root, int data)
{
    if (root == NULL)
    {
        return -1;
    }
    if (data < root->data)
    {
        return search(root->left, data);
    }
    else if (data > root->data)
    {
        return search(root->right, data);
    }
    else
    {
        return 1;
    }
}

// Function to in-order traversal of a binary tree
void inorder(struct node* node)
{
    if (node == NULL)
    {
        return;
    }
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

int main()
{
    struct node* root = NULL;

    // Inserting nodes
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);

    // Searching nodes
    printf("Search for 50: %d\n", search(root, 50));
    printf("Search for 90: %d\n", search(root, 90));

    // In-order traversal
    inorder(root);

    return 0;
}