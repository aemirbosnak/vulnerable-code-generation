//FormAI DATASET v1.0 Category: Binary search trees ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
 
// Binary Search Tree node structure
struct node
{
    int key;
    struct node *left, *right;
};
 
// Function to create a new binary search tree node
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Function to insert a new node with a given key in BST recursively
struct node* insert(struct node* node, int key)
{
    // Base case: Binary Search Tree is empty
    if (node == NULL) return newNode(key);
 
    // Otherwise, recur down the tree
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);    
 
    // Return the (unchanged) node pointer
    return node;
}
 
// Function to find the node with minimum key value recursively
struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 
// Function to delete the node with the given key value and return the new root node recursively
struct node* deleteNode(struct node* root, int key)
{
    // Base case: Binary Search Tree is empty
    if (root == NULL) return root;
 
    // Otherwise, recur down the tree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // Key is found and can be deleted
    else
    {
        // Case 1: Node has only one child or no child
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
 
        // Case 2: Node has two children, get the inorder successor
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
 
// Function to traverse the Binary Search Tree in pre-order recursively
void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
// Function to traverse the Binary Search Tree in in-order recursively
void inOrder(struct node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}
 
// Function to traverse the Binary Search Tree in post-order recursively
void postOrder(struct node *root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}
 
// Driver program to test above functions
int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 80);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 90);
    root = insert(root, 25);
    root = insert(root, 85);
 
    printf("Inorder traversal of the given tree is: ");
    inOrder(root);
    printf("\n");
 
    printf("Deleting key 90\n");
    root = deleteNode(root, 90);
    printf("Inorder traversal of the modified tree is: ");
    inOrder(root);
    printf("\n");
 
    printf("Deleting key 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree is: ");
    inOrder(root);
    printf("\n");
 
    printf("Preorder traversal of the modified tree is: ");
    preOrder(root);
    printf("\n");
 
    printf("Postorder traversal of the modified tree is: ");
    postOrder(root);
    printf("\n");
 
    return 0;
}