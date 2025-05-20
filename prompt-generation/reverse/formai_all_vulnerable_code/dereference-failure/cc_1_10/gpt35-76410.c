//FormAI DATASET v1.0 Category: Binary search trees ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

/* Let's create a BST node structure */
struct node {
    int data;
    struct node* left;
    struct node* right;
};

/* This function will create a new node */
struct node* createNode(int value) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* This function will insert a new node with the given value */
struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

/* This function will search for the given value */
struct node* search(struct node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (root->data < value) {
        return search(root->right, value);
    }
    return search(root->left, value);
}

/* This function will print the given tree in-order */
void printInOrder(struct node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

/* Main function */
int main() {

    /* Let's create an empty tree */
    struct node* root = NULL;

    /* Let's insert some nodes */
    printf("Inserting nodes into the tree...\n");
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 3);

    /* Let's print the tree */
    printf("The in-order traversal of the tree is: ");
    printInOrder(root);
    printf("\n");

    /* Let's search for some nodes */
    printf("Searching for node with value 7...\n");
    struct node* foundNode = search(root, 7);
    if (foundNode != NULL) {
        printf("Node found with value %d\n", foundNode->data);
    } else {
        printf("Node not found\n");
    }

    /* Let's search for some nodes */
    printf("Searching for node with value 100...\n");
    foundNode = search(root, 100);
    if (foundNode != NULL) {
        printf("Node found with value %d\n", foundNode->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}