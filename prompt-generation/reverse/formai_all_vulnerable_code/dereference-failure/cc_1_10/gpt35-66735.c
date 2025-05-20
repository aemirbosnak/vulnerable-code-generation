//FormAI DATASET v1.0 Category: Binary search trees ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the tree node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the tree
struct Node* insertNode(struct Node* root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    else if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to search for a node in the tree
struct Node* searchNode(struct Node* root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    else if (data < root->data)
    {
        return searchNode(root->left, data);
    }
    else
    {
        return searchNode(root->right, data);
    }
}

// Function to find the minimum value in the tree
struct Node* findMin(struct Node* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the tree
struct Node* deleteNode(struct Node* root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        // Case 2: One child
        else if (root->left == NULL)
        {
            struct Node* temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct Node* temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: Two children
        else
        {
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Function to print the inorder traversal of the tree
void inorderTraversal(struct Node* root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Main function
int main()
{
    struct Node* root = NULL;
    int choice, data;
    do
    {
        printf("Select an option:\n");
        printf("1. Insert a node\n");
        printf("2. Search for a node\n");
        printf("3. Delete a node\n");
        printf("4. Print the inorder traversal of the tree\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Enter the data to be searched: ");
                scanf("%d", &data);
                if (searchNode(root, data) != NULL)
                {
                    printf("Node found.\n");
                }
                else
                {
                    printf("Node not found.\n");
                }
                break;
            case 3:
                printf("Enter the data to be deleted: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 4:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}