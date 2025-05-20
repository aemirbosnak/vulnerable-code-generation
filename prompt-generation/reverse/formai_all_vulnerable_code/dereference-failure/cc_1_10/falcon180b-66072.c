//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the node structure for our binary search tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to search for a value in the tree
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to print the values in the tree in order
void printInOrder(Node* root) {
    if (root!= NULL) {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

// Function to print the values in the tree pre-order
void printPreOrder(Node* root) {
    if (root!= NULL) {
        printf("%d ", root->data);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

// Function to print the values in the tree post-order
void printPostOrder(Node* root) {
    if (root!= NULL) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    // Create the initial empty tree
    Node* tree = NULL;

    // Insert some values into the tree
    tree = insert(tree, 10);
    tree = insert(tree, 5);
    tree = insert(tree, 15);
    tree = insert(tree, 2);
    tree = insert(tree, 7);
    tree = insert(tree, 12);
    tree = insert(tree, 17);

    // Print the values in the tree in order
    printf("In-order traversal:\n");
    printInOrder(tree);
    printf("\n");

    // Print the values in the tree pre-order
    printf("Pre-order traversal:\n");
    printPreOrder(tree);
    printf("\n");

    // Print the values in the tree post-order
    printf("Post-order traversal:\n");
    printPostOrder(tree);
    printf("\n");

    // Search for a value in the tree
    Node* foundNode = search(tree, 7);
    if (foundNode!= NULL) {
        printf("Value %d found in the tree.\n", foundNode->data);
    } else {
        printf("Value %d not found in the tree.\n", 7);
    }

    return 0;
}