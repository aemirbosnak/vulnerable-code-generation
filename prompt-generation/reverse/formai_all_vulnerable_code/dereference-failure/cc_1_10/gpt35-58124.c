//FormAI DATASET v1.0 Category: Binary search trees ; Style: excited
#include <stdio.h>
#include <stdlib.h>

/* Structure definition for each node */
typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

/* Method to create a new node */
Node* CreateNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/* Method to insert a node into the binary search tree */
Node* InsertNode(Node* root, int data)
{
    if(root == NULL)
        return CreateNode(data);

    if(data < root->data)
        root->left = InsertNode(root->left, data);
    else if(data > root->data)
        root->right = InsertNode(root->right, data);

    return root;
}

/* Method to find the minimum value node */
Node* FindMinNode(Node* node)
{
    if(node == NULL)
        return NULL;
    else if(node->left == NULL)
        return node;

    return FindMinNode(node->left);
}

/* Method to delete a node from the binary search tree */
Node* DeleteNode(Node* root, int data)
{
    if(root == NULL)
        return root;

    if(data < root->data)
        root->left = DeleteNode(root->left, data);
    else if(data > root->data)
        root->right = DeleteNode(root->right, data);
    else
    {
        /* Node to be deleted has no child */
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        /* Node to be deleted has one child */
        else if(root->left == NULL)
        {
            Node* temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL)
        {
            Node* temp = root;
            root = root->left;
            free(temp);
        }
        /* Node to be deleted has two children */
        else
        {
            Node* temp = FindMinNode(root->right);
            root->data = temp->data;
            root->right = DeleteNode(root->right, temp->data);
        }
    }
    return root;
}

/* Method to display all the nodes in the binary search tree */
void InOrderTraversal(Node* root)
{
    if(root != NULL)
    {
        InOrderTraversal(root->left);
        printf("%d -> ", root->data);
        InOrderTraversal(root->right);
    }
}

/* Driver code */
int main()
{
    Node* root = NULL;

    root = InsertNode(root, 50);
    root = InsertNode(root, 30);
    root = InsertNode(root, 20);
    root = InsertNode(root, 40);
    root = InsertNode(root, 70);
    root = InsertNode(root, 60);
    root = InsertNode(root, 80);

    printf("In Order Traversal of Initial Tree:\n");
    InOrderTraversal(root); // 20 -> 30 -> 40 -> 50 -> 60 -> 70 -> 80 -> 

    root = DeleteNode(root, 20);
    root = DeleteNode(root, 30);
    root = DeleteNode(root, 50);

    printf("\nIn Order Traversal of Modified Tree:\n");
    InOrderTraversal(root); // 40 -> 60 -> 70 -> 80 -> 

    return 0;
}