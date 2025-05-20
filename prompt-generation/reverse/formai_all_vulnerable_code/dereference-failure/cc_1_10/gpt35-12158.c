//FormAI DATASET v1.0 Category: Binary search trees ; Style: brave
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insertNode(struct node *root, int data)
{
    if(root == NULL)
        return createNode(data);
    if(data < root->data)
        root->left = insertNode(root->left, data);
    else if(data > root->data)
        root->right = insertNode(root->right, data);
    return root;
}

void inorderTraversal(struct node *root)
{
    if(root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

struct node* searchNode(struct node *root, int key)
{
    if(root == NULL || root->data == key)
        return root;
    if(key < root->data)
        return searchNode(root->left, key);
    return searchNode(root->right, key);
}

struct node* minValueNode(struct node *node)
{
    struct node *current = node;
    while(current && current->left != NULL)
        current = current->left;
    return current;
}

struct node* deleteNode(struct node *root, int key)
{
    if(root == NULL)
        return root;
    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if(root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct node *root = NULL;
    root = insertNode(root, 10);
    insertNode(root, 7);
    insertNode(root, 15);
    insertNode(root, 5);
    insertNode(root, 11);
    insertNode(root, 18);
    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\nDeleting node with value 15...\n");
    root = deleteNode(root, 15);
    printf("Inorder traversal after deleting node with value 15: ");
    inorderTraversal(root);
    printf("\nSearching for node with value 7...\n");
    struct node *searchResult = searchNode(root, 7);
    if(searchResult == NULL)
        printf("Node not found!\n");
    else
        printf("Node found: %d\n", searchResult->data);
    return 0;
}