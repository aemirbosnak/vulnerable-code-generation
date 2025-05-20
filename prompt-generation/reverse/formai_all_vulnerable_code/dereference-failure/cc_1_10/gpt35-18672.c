//FormAI DATASET v1.0 Category: Binary search trees ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

//Node structure
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

//Function to create new node
node* createNode(int data) {
    node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Function to insert nodes
node* insertNode(node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    else if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

//Function to traverse binary search tree in order
void inorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

//Function to search for a node
node* search(node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    else if (data < root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

int main() {
    //Create root node
    node* root = createNode(50);

    //Insert nodes
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    //Search for nodes
    node* node1 = search(root, 60);
    node* node2 = search(root, 90);

    if (node1) {
        printf("Node found with value %d\n", node1->data);
    }
    else {
        printf("Node not found\n");
    }

    if (node2) {
        printf("Node found with value %d\n", node2->data);
    }
    else {
        printf("Node not found\n");
    }

    //Traverse tree in order
    printf("Inorder Traversal: ");
    inorderTraversal(root);

    return 0;
}