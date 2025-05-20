//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Binary tree node structure
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node into a binary tree
void insert(struct node **root, int data)
{
    if (*root == NULL)
    {
        *root = newNode(data);
        return;
    }

    struct node *current = *root;
    while (1)
    {
        if (data < current->data)
        {
            if (current->left == NULL)
            {
                current->left = newNode(data);
                break;
            }
            else
            {
                current = current->left;
            }
        }
        else
        {
            if (current->right == NULL)
            {
                current->right = newNode(data);
                break;
            }
            else
            {
                current = current->right;
            }
        }
    }
}

// Function to print the binary tree in pre-order
void printPreOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main()
{
    struct node *root = NULL;

    // Insert some nodes into the binary tree
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);
    insert(&root, 90);

    // Print the binary tree in pre-order
    printf("\nPre-order traversal of the binary tree: \n");
    printPreOrder(root);

    // Free the memory allocated for each node
    while (root!= NULL)
    {
        struct node *temp = root;
        root = root->left;
        free(temp);
    }

    return 0;
}