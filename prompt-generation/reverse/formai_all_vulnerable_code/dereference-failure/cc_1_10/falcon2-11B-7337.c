//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Node structure */
struct node
{
    int key;
    struct node* left;
    struct node* right;
};

/* Function to create a new node */
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/* Function to insert a new node in BST */
struct node* insert(struct node* root, int key)
{
    if (root == NULL)
        return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

/* Function to search a node in BST */
struct node* search(struct node* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        return search(root->left, key);
    else if (key > root->key)
        return search(root->right, key);
    else
        return root;
}

/* Function to inorder tree traversal */
void inorder(struct node* root)
{
    if (root!= NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

/* Function to print a level-order tree traversal */
void levelorder(struct node* root)
{
    struct node* temp = root;
    if (root!= NULL)
    {
        struct node* current = root;
        struct node* next = root->left;

        while (current!= NULL || next!= NULL)
        {
            while (next!= NULL)
            {
                printf("%d ", next->key);
                next = next->left;
            }

            printf("%d ", current->key);
            current = current->right;

            next = current->left;
        }
    }
}

/* Driver code */
int main()
{
    struct node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of BST is ");
    inorder(root);
    printf("\n");

    printf("Level order traversal of BST is ");
    levelorder(root);
    printf("\n");

    return 0;
}