//FormAI DATASET v1.0 Category: Binary search trees ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the Binary Search Tree Node
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new Node
struct Node* newNode(int item)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to traverse and find a node with matching key
struct Node* search(struct Node* root, int key)
{
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}

// Function to insert a new node
struct Node* insert(struct Node* root, int key)
{
    if (root == NULL)
        return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

// Function to traverse and print a tree in-order
void traverse(struct Node* root)
{
    if (root != NULL) {
        traverse(root->left);
        printf("%d ", root->key);
        traverse(root->right);
    }
}

int main()
{
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Traverse and print the tree in-order
    printf("In-order traversal: ");
    traverse(root);

    // Attempt to find a node with key value 70
    struct Node* searchNode = search(root, 70);
    if (searchNode != NULL)
        printf("\n%d is in the tree.", searchNode->key);
    else
        printf("\n70 is not in the tree.");

    // Attempt to find a node with key value 90
    searchNode = search(root, 90);
    if (searchNode != NULL)
        printf("\n%d is in the tree.", searchNode->key);
    else
        printf("\n90 is not in the tree.");

    return 0;
}