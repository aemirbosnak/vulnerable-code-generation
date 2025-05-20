//FormAI DATASET v1.0 Category: Binary search trees ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure of the node
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

// Create a new node with given data
Node *newNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node into tree
Node *insert(Node *node, int data)
{
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

// Find a node with given data
Node *search(Node *node, int data)
{
    if (node == NULL || node->data == data)
        return node;

    if (data < node->data)
        return search(node->left, data);

    return search(node->right, data);
}

// Delete a node from the tree
Node *delete(Node *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = delete(root->left, data);

    else if (data > root->data)
        root->right = delete(root->right, data);

    else
    {
        // Case 1: Node with only one child or no child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node with two children
        Node *temp = root->right;
        while (temp && temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

// Print the tree in-order
void inOrder(Node *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
}

int main()
{
    Node *root = NULL;

    // Paranoid style, always verify results
    root = insert(root, 50);
    printf("Inserted 50, root: %d\n", root->data);
    root = insert(root, 30);
    printf("Inserted 30, root: %d\n", root->data);
    root = insert(root, 20);
    printf("Inserted 20, root: %d\n", root->data);
    root = insert(root, 40);
    printf("Inserted 40, root: %d\n", root->data);
    root = insert(root, 70);
    printf("Inserted 70, root: %d\n", root->data);
    root = insert(root, 60);
    printf("Inserted 60, root: %d\n", root->data);
    root = insert(root, 80);
    printf("Inserted 80, root: %d\n", root->data);

    printf("Inorder traversal: ");
    inOrder(root);

    // Paranoid style, always verify results
    printf("\nNode with data=60: %s\n", search(root, 60) ? "FOUND" : "NOT FOUND");
    printf("Node with data=10: %s\n", search(root, 10) ? "FOUND" : "NOT FOUND");

    printf("\nDelete node with data=20\n");
    root = delete(root, 20);
    printf("Inorder traversal after deleting 20: ");
    inOrder(root);

    printf("\nDelete node with data=30\n");
    root = delete(root, 30);
    printf("Inorder traversal after deleting 30: ");
    inOrder(root);

    return 0;
}