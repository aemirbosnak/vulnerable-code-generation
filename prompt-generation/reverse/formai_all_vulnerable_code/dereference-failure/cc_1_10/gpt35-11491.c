//FormAI DATASET v1.0 Category: Binary search trees ; Style: romantic
#include<stdio.h>
#include<stdlib.h>

//Structure to hold node data
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

//Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Function to insert a value into the binary search tree
struct Node* insert(struct Node* node, int data) {
    if (node == NULL)
        return createNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

//Function to search for a value in the binary search tree
int search(struct Node* node, int data) {
    if (node == NULL)
        return 0;
    if (data == node->data)
        return 1;
    else if (data < node->data)
        return search(node->left, data);
    else
        return search(node->right, data);
}

//Function to delete a node from the binary search tree
struct Node* deleteNode(struct Node* node, int data) {
    if (node == NULL)
        return node;
    if (data < node->data)
        node->left = deleteNode(node->left, data);
    else if (data > node->data)
        node->right = deleteNode(node->right, data);
    else {
        if (node->left == NULL) {
            struct Node* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL) {
            struct Node* temp = node->left;
            free(node);
            return temp;
        }
        struct Node* temp = node->right;
        while (temp->left != NULL)
            temp = temp->left;
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

//Function to traverse the binary search tree in order
void inorder(struct Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

int main() {
    //Create a binary search tree
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    //Print elements in the binary search tree
    printf("Elements in the binary search tree: ");
    inorder(root);
    printf("\n");

    //Search for an element in the binary search tree
    int value = 70;
    if (search(root, value))
        printf("%d is found in the binary search tree\n", value);
    else
        printf("%d is not found in the binary search tree\n", value);

    //Delete an element from the binary search tree
    root = deleteNode(root, 30);

    //Print elements in the binary search tree after deleting an element
    printf("Elements in the binary search tree after deleting 30: ");
    inorder(root);
    printf("\n");

    return 0;
}