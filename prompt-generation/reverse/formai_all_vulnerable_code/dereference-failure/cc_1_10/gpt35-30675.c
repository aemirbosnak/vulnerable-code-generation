//FormAI DATASET v1.0 Category: Binary search trees ; Style: funny
#include<stdio.h>
#include<stdlib.h>

struct Node  // Creating a structure for our binary search tree
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int data) // Function to create new Node in the tree
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node)); // Allocating memory to the new node
    
    newnode->data= data; // Assigning our value to the new node
    newnode->left= NULL; // Assigning left and right child of the new node as NULL
    newnode->right= NULL;
    
    return newnode; // Returning the new Node
}

struct Node* insert(struct Node* node, int data) // Function to insert new node in our Binary Search Tree
{
    if (node == NULL) // When the tree is empty, insert the node as root
    {
        return create(data);
    }
    
    if (data < node->data) // If the data we want to insert is less than root, move to the left child
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data) // If the data we want to insert is greater than root, move to the right child
    {
        node->right = insert(node->right, data);
    }
    
    return node; // Returning the root node
}

void inorder(struct Node* node) // Function to traverse the tree in inorder manner
{
    if (node!= NULL)
    {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

int main() // Finally the main function
{
    printf("Welcome to the world of Binary Search Trees!\n\n");
    printf("First, let's create a tree with 5 nodes:\n\n");
    
    struct Node* root = NULL;
    root = insert(root, 25);
    insert(root, 15);
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    
    printf("Inorder traversal of the tree is: ");
    inorder(root);
    
    printf("\n\nOh no! We are missing a number 18 in our tree. Let's insert it:\n\n");
    insert(root, 18);
    
    printf("Inorder traversal after inserting 18 is: ");
    inorder(root);
    
    printf("\n\nWoohoo! The tree looks fine now. Thanks for playing with Binary Search Trees today :)");
    
    return 0;
}