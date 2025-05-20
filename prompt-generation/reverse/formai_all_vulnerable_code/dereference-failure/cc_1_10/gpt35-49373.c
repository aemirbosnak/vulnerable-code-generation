//FormAI DATASET v1.0 Category: Binary search trees ; Style: artistic
/*
* This program demonstrates a Binary Search Tree implementation in C language
* The program allows the user to insert, delete and search elements in the BST.
* The program also displays the elements in sorted order
*/

#include<stdio.h>
#include<stdlib.h>

struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

typedef struct BSTNode* node;

// Function declarations
node createNode(int);
node insert(node, int);
node delete(node, int);
node search(node, int);
void inorder(node);

// Function to create new node with the given data
node createNode(int data) {
    node newNode = (node) malloc(sizeof(struct BSTNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert new node in the BST
node insert(node root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Function to delete a node from the BST
node delete(node root, int data) {
    if (root == NULL)
        return root;
    else if (data < root->data)
        root->left = delete(root->left, data);
    else if (data > root->data)
        root->right = delete(root->right, data);
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            node temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) {
            node temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: Two children
        else {
            node temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

// Function to search for an element in the BST
node search(node root, int data) {
    if (root == NULL || root->data == data)
        return root;
    if (root->data > data)
        return search(root->left, data);
    return search(root->right, data);
}

// Function to print the nodes of the BST in inorder
void inorder(node root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    node root = NULL;
    int choice, data;
    while (1) {
        printf("\nBinary Search Tree Menu:");
        printf("\n-----------------------");
        printf("\n1. Insert Element");
        printf("\n2. Delete Element");
        printf("\n3. Search Element");
        printf("\n4. Print Elements(Inorder)");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter element to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("\nEnter element to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;
            case 3:
                printf("\nEnter element to search: ");
                scanf("%d", &data);
                if (search(root, data) != NULL)
                    printf("\nElement found in the BST!");
                else
                    printf("\nElement not found in the BST!");
                break;
            case 4:
                printf("\nElements of BST(Inorder): ");
                inorder(root);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;
}