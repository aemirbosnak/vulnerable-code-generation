//FormAI DATASET v1.0 Category: Binary search trees ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// this is the node struct for our binary search tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// function to create a new node
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                    malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    printf("Created a new node with data: %d\n", data);

    return(node);
}

// function to insert nodes into the binary search tree
struct node* insert(struct node* node, int data)
{
    // if the tree is empty, return a new node
    if (node == NULL) {
        return newNode(data);
    }

    // otherwise, recur down the tree
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        printf("Sorry, I can't insert duplicate values\n");
        // just kidding, of course I can insert duplicate values!
        int duplicateData = data + 1;
        node->left = insert(node->left, duplicateData);
    }

    return node;
}

// function to traverse the binary search tree in inorder
void inorderTraversal(struct node* node)
{
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

int main()
{
    struct node* root = NULL;

    // let's insert some nodes into the binary search tree
    root = insert(root, 10);
    root = insert(root, 4);
    root = insert(root, 25);
    root = insert(root, 6);
    root = insert(root, 12);
    root = insert(root, 22);
    root = insert(root, 17);
    root = insert(root, 9);
    root = insert(root, 23);
    root = insert(root, 8);

    // let's print out the nodes in the binary search tree in inorder traversal
    printf("The nodes in the binary search tree in inorder traversal are: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}