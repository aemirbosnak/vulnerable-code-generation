//FormAI DATASET v1.0 Category: Binary search trees ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

/* Binary Search Tree Node */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* Function to create a new node with the given data */
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

/* Function to insert a node into BST */
struct node* insert(struct node* node, int data)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
    {
        return(newNode(data));
    }
    else
    {
        /* Otherwise, recur down the tree */
        if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = insert(node->right, data);
        }
        /* Return the (unchanged) node pointer */
        return node;
    }
}

/* Function to search a node in BST */
struct node* search(struct node* node, int data)
{
    /* If the tree is empty or the node found, return the node */
    if (node == NULL || node->data == data)
    {
        return node;
    }
    else
    {
        /* Recur down the tree */
        if (data < node->data)
        {
            return search(node->left, data);
        }
        else
        {
            return search(node->right, data);
        }
    }
}

/* Function to find the minimum value node in a given BST */
struct node* minValueNode(struct node* node)
{
    /* Loop down to find the leftmost leaf */
    struct node* current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

/* Function to delete a node from BST */
struct node* deleteNode(struct node* root, int data)
{
    /* Base Case */
    if (root == NULL)
    {
        return root;
    }
    /* Recur down the tree */
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    /* If the key is same as root's key, then this node is to be deleted */
    else
    {
        /* Node with only one child or no child */
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        /* Node with two children: Get the inorder successor (smallest in the right subtree) */
        struct node* temp = minValueNode(root->right);
        /* Copy the inorder successor's content to this node */
        root->data = temp->data;
        /* Delete the inorder successor */
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

/* Function to traverse Inorder BST */
void inorder(struct node* node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

/* Main Function */
int main()
{
    /* create root node and insert nodes into BST */
    struct node* root = NULL;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);
    insert(root, 4);
    insert(root, 7);
    insert(root, 13);
    /* print Inorder BST */
    printf("Inorder traversal of the given Binary Search Tree is: ");
    inorder(root);
    printf("\n");
    /* delete nodes from BST */
    root = deleteNode(root, 8);
    root = deleteNode(root, 3);
    root = deleteNode(root, 10);
    /* print Inorder BST */
    printf("Inorder traversal of the modified Binary Search Tree is: ");
    inorder(root);
    printf("\n");
    return 0;
}