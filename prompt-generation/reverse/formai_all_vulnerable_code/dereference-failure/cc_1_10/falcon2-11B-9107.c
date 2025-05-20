//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: interoperable
#include <stdio.h>

// Structure for a node in the BST
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node with given data in the BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to print the BST in pre-order traversal
void printPreOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main() {
    struct Node* root = NULL;

    // Inserting elements in the BST
    insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    insertNode(root, 90);

    // Printing the BST in pre-order traversal
    printf("Pre-order traversal of the BST:\n");
    printPreOrder(root);

    return 0;
}